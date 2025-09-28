
#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap " << this->name << " is constructed!" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->name << " is destroyed!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap " << this->name << " copy constructor called!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
		this->hitPoints = 100;
		this->energyPoints = 100;
		this->attackDamage = 30;
	}
	std::cout << "FragTrap assignment operator called!" << std::endl;
	return *this;
}

void FragTrap::attack(const std::string& target) {
	if (this->energyPoints <= 0) {
		std::cout << "FragTrap " << this->name << " has no energy left to attack!" << std::endl;
		return;
	}
	if (this->hitPoints <= 0) {
		std::cout << "FragTrap " << this->name << " is dead and cannot attack!" << std::endl;
		return;
	}
	
	this->energyPoints--;
	std::cout << "FragTrap " << this->name << " powerfully attacks " << target 
			  << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	if (this->hitPoints <= 0) {
		std::cout << "FragTrap " << this->name << " is dead and cannot give high-fives!" << std::endl;
		return;
	}
	std::cout << "FragTrap " << this->name << " requests a positive high-five! Give me five!" << std::endl;
}
