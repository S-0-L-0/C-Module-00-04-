
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name) 
	: name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap " << this->name << " is constructed!" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->name << " is destroyed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) 
	: name(other.name), hitPoints(other.hitPoints), 
	  energyPoints(other.energyPoints), attackDamage(other.attackDamage) {
	std::cout << "ClapTrap " << this->name << " copy constructor called!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other) {
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	std::cout << "ClapTrap assignment operator called!" << std::endl;
	return *this;
}

void ClapTrap::attack(const std::string& target) {
	if (this->energyPoints <= 0) {
		std::cout << "ClapTrap " << this->name << " has no energy left to attack!" << std::endl;
		return;
	}
	if (this->hitPoints <= 0) {
		std::cout << "ClapTrap " << this->name << " is dead and cannot attack!" << std::endl;
		return;
	}
	
	this->energyPoints--;
	std::cout << "ClapTrap " << this->name << " attacks " << target 
			  << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->hitPoints <= 0) {
		std::cout << "ClapTrap " << this->name << " is already dead!" << std::endl;
		return;
	}
	
	if (amount >= this->hitPoints) {
		std::cout << "ClapTrap " << this->name << " takes " << amount 
				  << " points of damage and is destroyed!" << std::endl;
		this->hitPoints = 0;
	} else {
		this->hitPoints -= amount;
		std::cout << "ClapTrap " << this->name << " takes " << amount 
				  << " points of damage! Hit points now: " << this->hitPoints << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->energyPoints <= 0) {
		std::cout << "ClapTrap " << this->name << " has no energy left to repair!" << std::endl;
		return;
	}
	if (this->hitPoints <= 0) {
		std::cout << "ClapTrap " << this->name << " is dead and cannot repair!" << std::endl;
		return;
	}
	
	this->energyPoints--;
	this->hitPoints += amount;
	std::cout << "ClapTrap " << this->name << " is repaired for " << amount 
			  << " hit points! Hit points now: " << this->hitPoints << std::endl;
}