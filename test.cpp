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
	std::cout << "A: " << a << std::endl;
	return 0;
}

