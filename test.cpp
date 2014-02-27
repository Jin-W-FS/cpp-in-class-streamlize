#include <iostream>

#include "streamlize.hpp"

struct A {
	int x;
	A(int _x):x(_x) {}
	__to_stream__(std::ostream& os) const { os << x; }
};

struct B {
	int x;
	B(int _x):x(_x) {}
	__to_stream__(std::ostream& os) { os << x; }
};

struct C {
	int x;
	C(int _x):x(_x) {}
};
std::ostream& operator<<(std::ostream& os, const C& obj) {
	return os << obj.x;
}

struct D {
	int x;
	D(int _x):x(_x) {}
};
std::ostream& operator<<(std::ostream& os, D& obj) {
	return os << obj.x;
}
#ifdef __GXX_EXPERIMENTAL_CXX0X__
std::ostream& operator<<(std::ostream& os, D&& obj) {
	return os << obj.x;
}
#endif

int main()
{
	A a(0);
	std::cout << "A(0): " << a << std::endl;
	std::cout << "A(1): " << A(1) << std::endl;
	B b(0);
	std::cout << "B(0): " << b << std::endl;
#ifdef __GXX_EXPERIMENTAL_CXX0X__
	std::cout << "B(1): " << B(1) << std::endl;	// only after c++0x
#endif
	C c(0);
	std::cout << "C(0): " << c << std::endl;
	std::cout << "C(1): " << C(1) << std::endl;
	D d(0);
	std::cout << "D(0): " << d << std::endl;
#ifdef __GXX_EXPERIMENTAL_CXX0X__
	std::cout << "D(1): " << D(1) << std::endl;	// before c++0x, rvalue ref is treated as const ref
#endif
	return 0;
}

