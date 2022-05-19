#ifndef FT_RANDOM_ACCESS_ITERATOR_HPP
#define FT_RANDOM_ACCESS_ITERATOR_HPP

#include "IteratorTraits.hpp"

namespace ft {

	/* https://www.cplusplus.com/reference/iterator/RandomAccessIterator/ */
	template <typename T>
	class random_access_iterator {

	public:
		typedef ft::random_access_iterator_tag					iterator_category;
		typedef T*												pointer;
		typedef T&												reference;
		typedef std::ptrdiff_t									difference_type;
		typedef random_access_iterator<T>						iterator;
		typedef random_access_iterator<const T> 				if_const;
		typedef T												value_type;

	public:

		/* Constructors and destructor */
		random_access_iterator(): _ptr(NULL) {}
		explicit random_access_iterator(pointer ptr) : _ptr(ptr) {}
		random_access_iterator(const random_access_iterator& x) { *this = x; }
		random_access_iterator& operator= (const random_access_iterator& x) {
			if (this != &x) {
				_ptr = x._ptr;
			}
			return *this;
		}
		~random_access_iterator(){}

		/* Equality/inequality operators */
		bool operator== (const iterator& rhs) const { return _ptr == rhs._ptr; }
		bool operator!= (const iterator& rhs) const { return _ptr != rhs._ptr; }

		/* Dereferencing */
		reference operator* () { return *_ptr; }
		pointer operator-> () { return _ptr; }

		/* Increment and decrement */
		iterator& operator++ () { ++_ptr; return *this; }

		iterator operator++ (int) {
			iterator tmp = *this;
			++_ptr;
			return tmp;
		}

		iterator& operator-- () { --_ptr; return *this; }

		iterator operator-- (int) {
			iterator tmp = *this;
			--_ptr;
			return tmp;
		}

		/* Arithmetic operations */
		iterator operator- (const difference_type& x) const { return iterator(_ptr - x); }
		difference_type operator-(const iterator& rhs) const { return _ptr - rhs._ptr;	}
		friend iterator operator+ (int n, iterator itr) { return iterator(itr._ptr + n); }
		iterator operator+ (const int n) const { return iterator(_ptr + n); }

		/* Comparison */
		bool operator > (const iterator& rhs) const { return _ptr > rhs._ptr; }
		bool operator < (const iterator& rhs) const { return _ptr < rhs._ptr; }
		bool operator >= (const iterator& rhs) const { return _ptr >= rhs._ptr; }
		bool operator <= (const iterator& rhs) const { return _ptr <= rhs._ptr; }

		/* Assignment operations */
		iterator& operator += (int n) { _ptr += n; return *this; }
		iterator& operator -= (int n) { _ptr -= n; return *this; }

		/* Offset dereference operator  */
		reference operator[](const difference_type n) const { return _ptr[n]; }

	private:
		pointer	_ptr;
	};
}

#endif //FT_RANDOM_ACCESS_ITERATOR_HPP