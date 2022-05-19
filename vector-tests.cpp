#include <vector>
#include "vector.hpp"
// #include <iostream>

int main(int argc, char const *argv[])
{
	std::vector<int> v(10);
	for (int i = 0; i < 15; ++i) {
		v.push_back(i);
		std::cout << i << "\t" << v.size() << "\t" << v.capacity() << std::endl;
	}

	ft::vector<int> ft_v(10);
	for (int i = 0; i < 15; ++i) {
		ft_v.push_back(i);
		std::cout << i << "\t" << ft_v.size() << "\t" << ft_v.capacity() << std::endl;
	}

	try {
		std::cout << v.at(15) << std::endl;
		std::cout << v.at(35) << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	try {
		std::cout << ft_v.at(15) << std::endl;
		std::cout << ft_v.at(35) << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::vector<int> vv;
	ft::vector<int> ft_vv;
	std::cout << vv.empty() << '\n';
	std::cout << ft_vv.empty() << '\n';

	vv.push_back(1);
	vv.push_back(2);
	vv.push_back(3);
	std::cout << vv.size() << "\t" << vv.capacity() << std::endl;

	ft_vv.push_back(1);
	ft_vv.push_back(2);
	ft_vv.push_back(3);
	std::cout << ft_vv.size() << "\t" << ft_vv.capacity() << std::endl;

	std::cout << vv.empty() << '\n';
	std::cout << ft_vv.empty() << '\n';

	ft::vector<int> ft_new;

	std::cout << ft_new.empty() << '\n';
	ft_new = ft_vv;
	std::cout << ft_new.empty() << '\n';

	ft::vector<int>::iterator it = ft_new.begin();

	for (size_t i = 0; i < ft_new.size(); i++) {
		std::cout << "Iterator value: " << *it << std::endl;
		it++;
	}

	return 0;
}
