
#include "HumanB.hpp"

HumanB::HumanB(std::string humanName) : name(humanName), weapon(NULL)
{
	std::cout << "HumanB " << name << " created without weapon" << std::endl;
}

void HumanB::setWeapon(Weapon& humanWeapon)
{
	weapon = &humanWeapon;
	std::cout << name << " is now armed with " << weapon->getType() << std::endl;
}

void HumanB::attack() const
{
	if (weapon != NULL)
	{
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	}
	else
	{
		std::cout << name << " attacks with their bare hands (no weapon!)" << std::endl;
	}
}