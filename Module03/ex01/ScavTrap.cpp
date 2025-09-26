
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap " << this->name << " is constructed!" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->name << " is destroyed!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap " << this->name << " copy constructor called!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
		this->hitPoints = 100;
		this->energyPoints = 50;
		this->attackDamage = 20;
	}
	std::cout << "ScavTrap assignment operator called!" << std::endl;
	return *this;
}

void ScavTrap::attack(const std::string& target) {
	if (this->energyPoints <= 0) {
		std::cout << "ScavTrap " << this->name << " has no energy left to attack!" << std::endl;
		return;
	}
	if (this->hitPoints <= 0) {
		std::cout << "ScavTrap " << this->name << " is dead and cannot attack!" << std::endl;
		return;
	}
	
	this->energyPoints--;
	std::cout << "ScavTrap " << this->name << " fiercely attacks " << target 
			  << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
	if (this->hitPoints <= 0) {
		std::cout << "ScavTrap " << this->name << " is dead and cannot guard the gate!" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode!" << std::endl;
}