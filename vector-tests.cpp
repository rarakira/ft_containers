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
	return 0;
}
