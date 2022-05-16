#include <vector>
#include "vector.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
	std::vector<int> v(10);
	for (int i = 0; i < 15; ++i) {
		v.push_back(i);
		std::cout << i << "\t" << v.size() << "\t" << v.capacity() << std::endl;
	}

	ft::vector<int> ftV(10);
	for (int i = 0; i < 15; ++i) {
		ftV.push_back(i);
		std::cout << i << "\t" << ftV.size() << "\t" << ftV.capacity() << std::endl;
	}

	return 0;
}
