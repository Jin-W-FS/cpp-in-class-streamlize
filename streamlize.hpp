#ifndef STREAMLIZE_HELPER_HPP
#define STREAMLIZE_HELPER_HPP

#ifdef __to_stream__
#undef __to_stream__
#endif

#ifdef __GXX_EXPERIMENTAL_CXX0X__

// -std=c++0x  supports default template arguments of a function 
template <class T, class = typename T::streamlizable>
std::ostream& operator<<(std::ostream& os, T& obj) {
	obj.__to_stream__(os); return os;
}

// for temp object
template <class T, class = typename T::streamlizable>
std::ostream& operator<<(std::ostream& os, T&& obj) {
	obj.__to_stream__(os); return os;
}

#else

// common helper class
class __streamlize_helper {
private:
	struct streamlizer_base {
		void* p;
		void (*fn)(std::ostream& os, void* p);
		streamlizer_base(void* p_, void (*fn_)(std::ostream&, void*)):p(p_), fn(fn_) {}
		void __to_stream(std::ostream& os) const { fn(os, p); }
	};
	template <class T, class = typename T::streamlizable>
	struct streamlizer {
		static void streamlize_fn(std::ostream& os, void* p) { ((T*)p)->__to_stream__(os); }
	};
private:
	streamlizer_base s;
public:
	template <class T> __streamlize_helper(T& obj_):s(&obj_, streamlizer<T>::streamlize_fn) {}
	void __to_stream(std::ostream& os) const { s.__to_stream(os); }
};

static inline std::ostream& operator<<(std::ostream& os, const __streamlize_helper& s) {
	s.__to_stream(os); return os;
}

#endif	// __GXX_EXPERIMENTAL_CXX0X__

#define __to_stream__(...)		typedef struct {} streamlizable; void __to_stream__(__VA_ARGS__)

#endif
