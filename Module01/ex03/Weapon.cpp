
#include "Weapon.hpp"

Weapon::Weapon(std::string weaponType) : type(weaponType)
{
	std::cout << "Weapon created: " << type << std::endl;
}

const std::string& Weapon::getType() const
{
	return type;
}

void Weapon::setType(std::string newType)
{
	std::cout << "Weapon type changed from '" << type << "' to '" << newType << "'" << std::endl;
	type = newType;
}