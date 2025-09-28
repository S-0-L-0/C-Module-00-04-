
#include "Cat.hpp"

Cat::Cat() : Animal() {
	this->type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
	this->type = "Cat";
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		Animal::operator=(other);
		this->type = "Cat";
	}
	std::cout << "Cat assignment operator called" << std::endl;
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow! Meow!" << std::endl;
}
