#include <iostream>

#include "streamlize.hpp"

struct A
{
	int x;
	A(int _x):x(_x) {
	}
	__to_stream__(std::ostream& os) {
		os << x;
	}
};

int main()
{
	A a(3);
	std::cout << "A(3): " << a << std::endl;
	std::cout << "A(2): " << A(2) << std::endl;
	return 0;
}

