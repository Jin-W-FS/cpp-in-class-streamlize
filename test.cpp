#include <iostream>

#include "streamlize.hpp"

struct A
{
	int x;
	A(int _x):x(_x) {
	}
	typedef struct {} streamlizable;
	std::ostream& toStream(std::ostream& os) {
		return os << x;
	}
};

int main()
{
	A a(3);
	std::cout << "A: " << a << std::endl;
	return 0;
}

