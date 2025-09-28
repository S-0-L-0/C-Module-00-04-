
#include "Dog.hpp"

Dog::Dog() : Animal() {
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	this->type = "Dog";
	this->brain = new Brain(*other.brain);  // Deep copy
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		Animal::operator=(other);
		delete this->brain;  // Delete old brain
		this->brain = new Brain(*other.brain);  // Deep copy new brain
		this->type = "Dog";
	}
	std::cout << "Dog assignment operator called" << std::endl;
	return *this;
}

Dog::~Dog() {
	delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Woof! Woof!" << std::endl;
}

Brain* Dog::getBrain() const {
	return this->brain;
}