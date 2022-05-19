#ifndef FT_REVERSE_ITERATOR_HPP
# define FT_REVERSE_ITERATOR_HPP

#include "IteratorTraits.hpp"

namespace ft {

template<class Iterator, class category = typename iterator_traits<Iterator>::iterator_category>
class reverse_iterator {
public:
	typedef	Iterator												iterator_type;
	typedef	typename iterator_traits<Iterator>::iterator_category	iterator_category;
	typedef	typename iterator_traits<Iterator>::value_type			value_type;
	typedef	typename iterator_traits<Iterator>::difference_type		difference_type;
	typedef	typename iterator_traits<Iterator>::pointer				pointer;
	typedef	typename iterator_traits<Iterator>::reference			reference;

	reverse_iterator() : _iter() {}

	explicit reverse_iterator (iterator_type it) :
				_iter(it) {}
	
	reverse_iterator(const reverse_iterator & other) :
				_iter(other._iter) {}
	
	~reverse_iterator() {}

	iterator_type base() const { return (_iter); }

	reference operator*() const {
		iterator_type tmp = _iter;
		return (*(--tmp));
	}

	reverse_iterator& operator++() {
		--_iter;
		return (*this);
	}
	
	reverse_iterator operator++(int) {
		reverse_iterator tmp = *this;
		++(*this);
		return (tmp);
	}

	reverse_iterator& operator--() {
		++_iter;
		return (*this);
	}

	reverse_iterator operator--(int) {
		reverse_iterator tmp = *this;
		--(*this);
		return (tmp);
	}
	
	pointer operator->() const { return &(operator*()); }
	
	friend bool operator==(reverse_iterator lhs, reverse_iterator rhs)
	{ return lhs._iter == rhs._iter; }
	
	friend bool operator!=(reverse_iterator lhs, reverse_iterator rhs)
	{ return lhs._iter != rhs._iter; }

private:
	iterator_type	_iter;
};

}

#endif // FT_REVERSE_ITERATOR_HPP