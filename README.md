_This is a **21 School/Ecole 42** Project_

# ft_containers

Reimplementaion of C++98 STL containers. Subject can be found [here](https://cdn.intra.42.fr/pdf/pdf/47323/en.subject.pdf).

## Project goals

* Deeply understand containers structure, explore member types and functions
* Implement iterator system for each container type (where applicable)
* Produce tests, compare outputs and performance with original STL containers
* Use friend keyword for non-member overloads

### Container list

1. Vector
2. Map
3. Stack adaptor based on Vector (1) implementation
4. Set (based on Red-Black Tree)

### Technical requirements

* The coding language is C++98.
* The namespaces will be ft and all containers will be tested using ft::<container>.
* You cannot implement more public functions than the ones offered in the standard containers. Everything else must be private or protected. Each public function variable must be justified.
* You must use std::allocator
* For non-member overloads, the keyword friend is allowed.

## Useful links

* Good presentation on [iterators](https://home.csulb.edu/~pnguyen/cecs282/lecnotes/iterators.pdf)