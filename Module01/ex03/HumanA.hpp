
#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanA
{
private:
	std::string name;
	Weapon& weapon;  // REFERENCE - l'arma DEVE sempre esistere

public:
	// Costruttore: prende nome E arma (arma obbligatoria)
	HumanA(std::string humanName, Weapon& humanWeapon);
	
	// Funzione di attacco
	void attack() const;
};

#endif