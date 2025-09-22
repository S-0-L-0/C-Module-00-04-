
#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
private:
	std::string type;

public:
	// Costruttore che prende il tipo di arma
	Weapon(std::string weaponType);
	
	// Getter: restituisce reference CONST al tipo
	const std::string& getType() const;
	
	// Setter: imposta nuovo tipo
	void setType(std::string newType);
};

#endif