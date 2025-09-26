
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
	private:
	std::string name;
	unsigned int hitPoints;
	unsigned int energyPoints;
	unsigned int attackDamage;

	public:
		// Constructor
		ClapTrap(const std::string& name);
		// Destructor
		~ClapTrap();
		// Copy Constructor
		ClapTrap(const ClapTrap& other);
		// Assignment Operator Overload
		ClapTrap& operator=(const ClapTrap& other);
	
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif