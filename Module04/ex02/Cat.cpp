
#include "Cat.hpp"

Cat::Cat() : Animal() {
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
	this->type = "Cat";
	this->brain = new Brain(*other.brain);  // Deep copy
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		Animal::operator=(other);
		delete this->brain;  // Delete old brain
		this->brain = new Brain(*other.brain);  // Deep copy new brain
		this->type = "Cat";
	}
	std::cout << "Cat assignment operator called" << std::endl;
	return *this;
}

Cat::~Cat() {
	delete this->brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow! Meow!" << std::endl;
}

Brain* Cat::getBrain() const {
	return this->brain;
}