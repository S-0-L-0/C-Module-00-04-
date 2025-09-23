
#include "HumanA.hpp"

HumanA::HumanA(std::string humanName, Weapon& humanWeapon) : name(humanName), weapon(humanWeapon)
{
	std::cout << "HumanA " << name << " created with " << weapon.getType() << std::endl;
}

void HumanA::attack() const
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}