cpp-in-class-streamlize
=======================

For avoiding defining an external friend function to streamlize an object in c++ style.

Thus:
instead of writing code like this:

	// XXX.hpp
	class C {
	    ...
	public:
	    friend std::ostream& operator<<(std::ostream&, const C&);
	};

	// XXX.cpp or with "static inline" in XXX.hpp; outof the class, anyway.
	std::ostream& operator<<(std::ostream& os, C& obj) {
	    ...      	      
	}

we could write like this:

	// XXX.hpp
	#include "streamlize.hpp"

	class C {
	    ...
	public:
	    __to_stream__(std::ostream& os) {
	        ...
	    }
	};

and when calling, say

    	std::cout << C();

it will automatically call that function, just like __str__ or __len__ functions in Python.
