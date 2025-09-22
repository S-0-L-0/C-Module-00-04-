
#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanB
{
private:
	std::string name;
	Weapon* weapon;  // POINTER - l'arma può essere NULL (opzionale)

public:
	// Costruttore: prende solo nome (niente arma iniziale)
	HumanB(std::string humanName);
	
	// Setter per impostare l'arma dopo la creazione
	void setWeapon(Weapon& humanWeapon);
	
	// Funzione di attacco
	void attack() const;
};

#endif