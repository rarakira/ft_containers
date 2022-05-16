#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

# include <memory>

namespace ft
{
	template<typename T, typename Allocator = std::allocator<T> >
	class vector {
	public:
		typedef T								value_type;
		typedef Allocator						allocator_type;
		typedef std::size_t						size_type;
		typedef std::ptrdiff_t					difference_type;
		typedef value_type&						reference;
		typedef const value_type&				const_reference;
		typedef Allocator::pointer				pointer;
		typedef const Allocator::pointer		const_pointer;

		// iterator
		// LegacyRandomAccessIterator and LegacyContiguousIterator to value_type

		// const_iterator
		// LegacyRandomAccessIterator and LegacyContiguousIterator to const value_type

		// reverse_iterator	std::reverse_iterator<iterator>
		// const_reverse_iterator std::reverse_iterator<const_iterator>

	private:
		size_type               _size;
		size_type               _capacity;
		T*                      _data;
		Allocator               _alloc;

	public:
		vector();
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
		iterator begin();
		const_iterator begin() const;

		iterator end();
		const_iterator end() const;

		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;

		reverse_iterator rend();
		const_reverse_iterator rend() const;
		
		/* Capacity */
		bool empty() const;
		size_type size() const;
		size_type max_size() const;
		void reserve( size_type new_cap );
		size_type capacity() const;

		/* Modifiers */
		void clear();
		iterator insert( iterator pos, const T& value );
		iterator erase( iterator pos );
		iterator erase( iterator first, iterator last );
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

	/* Functions implementations */

	template<class T, class Allocator>
	vector<T, Allocator>::vector() : _size(0), _capacity(0), _alloc() {
		_data = _alloc.allocate(0);
	}

	template<class T, class Allocator>
	vector<T, Allocator>::~vector() {
		for (size_type i = 0; i < _size; ++i) {
			_alloc.destroy(_data + i);
		}
		_alloc.deallocate(_data, _capacity);
	}

} // namespace ft

#endif // FT_VECTOR_HPP