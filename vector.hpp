#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

# include <memory>
#include <iostream>

namespace ft
{
	template<typename T, typename Allocator = std::allocator<T> >
	class vector {
	public:
		typedef T										value_type;
		typedef Allocator								allocator_type;
		typedef std::size_t								size_type;
		typedef std::ptrdiff_t							difference_type;
		typedef value_type&								reference;
		typedef const value_type&						const_reference;
		typedef typename Allocator::pointer				pointer;
		typedef typename Allocator::const_pointer		const_pointer;

		// iterator
		// LegacyRandomAccessIterator and LegacyContiguousIterator to value_type

		// const_iterator
		// LegacyRandomAccessIterator and LegacyContiguousIterator to const value_type

		// reverse_iterator	std::reverse_iterator<iterator>
		// const_reverse_iterator std::reverse_iterator<const_iterator>

	private:
		size_type               _size;
		size_type               _capacity;
		T*                      _array;
		Allocator               _alloc;

	public:
		vector();
		explicit vector( const Allocator& alloc );
		explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator());
		// template< class InputIt >
		// vector( InputIt first, InputIt last, const Allocator& alloc = Allocator() );
		vector( const vector& other );
		~vector();
		vector& operator=( const vector& other );
		void assign( size_type count, const T& value );
		allocator_type get_allocator() const;

		/* Element access */
		reference at( size_type pos );
		const_reference at( size_type pos ) const;

		reference operator[]( size_type pos );
		const_reference operator[]( size_type pos ) const;

		reference front();
		const_reference front() const;

		reference back();
		const_reference back() const;

		T* data();
		const T* data() const;

		/* Iterators */
		// iterator begin();
		// const_iterator begin() const;

		// iterator end();
		// const_iterator end() const;

		// reverse_iterator rbegin();
		// const_reverse_iterator rbegin() const;

		// reverse_iterator rend();
		// const_reverse_iterator rend() const;
		
		/* Capacity */
		bool empty() const;
		size_type size() const;
		size_type max_size() const;
		void reserve( size_type new_cap );
		size_type capacity() const;

		/* Modifiers */
		void clear();
		// iterator insert( iterator pos, const T& value );
		// iterator erase( iterator pos );
		// iterator erase( iterator first, iterator last );
		void push_back( const T& value );
		void pop_back();
		void resize( size_type count, T value = T() );
		void swap( vector& other );
	};

	/* Non-member functions */
	template< class T, class Allocator >
	bool operator==(const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs);

	template< class T, class Allocator >
	bool operator!=( const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs );
	
	template< class T, class Allocator >
	bool operator<( const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs );

	template< class T, class Allocator >
	bool operator<=( const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs );

	template< class T, class Allocator >
	bool operator>( const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs );

	template< class T, class Allocator >
	bool operator>=( const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs );

	template< class T, class Allocator >
	void swap( vector<T,Allocator>& lhs, vector<T,Allocator>& rhs );

	/* Constructors */

	template<class T, class Allocator>
	vector<T, Allocator>::vector() : _size(0), _capacity(0), _alloc() {
		_array = _alloc.allocate(0);
	}

	template<class T, class Allocator>
	vector<T, Allocator>::vector(const Allocator& alloc) :
		_size(0), _capacity(0), _alloc(alloc) {
		_array = _alloc.allocate(0);
	}

	template<class T, class Allocator>
	vector<T, Allocator>::vector(size_type count, const T& value, const Allocator& alloc) :
		_size(count), _capacity(count), _alloc(alloc) {
		_array = _alloc.allocate(_capacity);
		size_type i = 0;
		try {
			for (; i < count; ++i) {
				_alloc.construct(_array + i, value);
			}
		}
		catch (...) {
			for (; i > 0; --i) {
				_alloc.destroy(_array + i - 1);
			}
			_alloc.deallocate(_array, _capacity);
			throw ;
		}
	}
	// template< class InputIt >
	// vector( InputIt first, InputIt last, const Allocator& alloc = Allocator() );
	
	template<class T, class Allocator>
	vector<T, Allocator>::vector(const vector& other) {

	}

	/* Destructor */

	template<class T, class Allocator>
	vector<T, Allocator>::~vector() {
		for (size_type i = 0; i < _size; ++i) {
			_alloc.destroy(_array + i);
		}
		_alloc.deallocate(_array, _capacity);
	}

	// vector& operator=( const vector& other );
	// void assign( size_type count, const T& value );
	// allocator_type get_allocator() const;

	/* Element access functions implementation */

	template<class T, class Allocator>
	typename vector<T, Allocator>::reference vector<T, Allocator>::at(size_type pos) {
		if (pos >= _size) {
			throw std::out_of_range("vector");
		}
		return _array[pos];
	}

	template<class T, class Allocator>
	typename vector<T, Allocator>::const_reference vector<T, Allocator>::at(size_type pos) const {
		if (pos >= _size) {
			throw std::out_of_range("vector");
		}
		return _array[pos];
	}

	template<class T, class Allocator>
	typename vector<T, Allocator>::reference vector<T, Allocator>::operator[](size_type pos) {
		return _array[pos];
	}

	template<class T, class Allocator>
	typename vector<T, Allocator>::const_reference vector<T, Allocator>::operator[](size_type pos) const {
		return _array[pos];
	}

	template<class T, class Allocator>
	typename vector<T, Allocator>::reference vector<T, Allocator>::front() {
		return _array[0];
	}

	template<class T, class Allocator>
	typename vector<T, Allocator>::const_reference vector<T, Allocator>::front() const {
		return _array[0];
	}

	template<class T, class Allocator>
	typename vector<T, Allocator>::reference vector<T, Allocator>::back() {
		return _array[_size - 1];
	}

	template<class T, class Allocator>
	typename vector<T, Allocator>::const_reference vector<T, Allocator>::back() const {
		return _array[_size - 1];
	}

	template<class T, class Allocator>
	T* vector<T, Allocator>::data() {
		return _array;
	}

	template<class T, class Allocator>
	const T* vector<T, Allocator>::data() const {
		return _array;
	}

	/* Iterators functions implementation */

	// iterator begin();
	// const_iterator begin() const;

	// iterator end();
	// const_iterator end() const;

	// reverse_iterator rbegin();
	// const_reverse_iterator rbegin() const;

	// reverse_iterator rend();
	// const_reverse_iterator rend() const;

	/* Capacity functions implementation */

	template<class T, class Allocator>
	bool vector<T, Allocator>::empty() const {
		return (_size == 0);
	}

	template<class T, class Allocator>
	typename vector<T, Allocator>::size_type vector<T, Allocator>::size() const {
		return _size;
	}

	// size_type max_size() const;
	
	template<class T, class Allocator>
	void vector<T, Allocator>::reserve(size_type new_cap) {
		if (new_cap <= _capacity) return;
		T* newarr = _alloc.allocate(new_cap);
		size_type i = 0;
		try {
			for (; i < _size; ++i) {
				_alloc.construct(newarr + i, _array[i]);
			}
		} catch (...) {
			for (size_type j = 0; j < i; ++j) {
				_alloc.destroy(&_array[j]);
			}
			_alloc.deallocate(newarr, new_cap);
			throw;
		}
		for (size_type i = 0; i < _size; ++i) {
			_alloc.destroy(&_array[i]);
		}
		_alloc.deallocate(_array, _capacity);
		_array = newarr;
		_capacity = new_cap;
	}

	
	template<class T, class Allocator>
	typename vector<T, Allocator>::size_type vector<T, Allocator>::capacity() const {
		return _capacity;
	}

	/* Modifiers functions implementations */

	// void clear();
	// iterator insert( iterator pos, const T& value );
	// iterator erase( iterator pos );
	// iterator erase( iterator first, iterator last );

	template<class T, class Allocator>
	void vector<T, Allocator>::push_back(const T& value) {
		if (_capacity == _size) {
			if (_capacity == 0) {
				reserve(1);
			} else {
				reserve(2 * _size);
			}
		}
		_alloc.construct(_array + _size, value);
		++_size;
	}

	template<class T, class Allocator>
	void vector<T, Allocator>::pop_back() {
		--_size;
		_alloc.destroy(&_array[_size]);
	}

	template<class T, class Allocator>
	void vector<T, Allocator>::resize(size_type count, T value) {
		if (count > _capacity) reserve(count);
		for (size_type i = _size; i < count; ++i) {
			_alloc.construct(_array + _size, value);
		}
		if (count < _size) {
			_size = count;
		}
	}

	// void swap( vector& other );

} // namespace ft

#endif // FT_VECTOR_HPP