
#include "HumanA.hpp"

// Costruttore - DEVE ricevere un'arma (reference initialization)
HumanA::HumanA(std::string humanName, Weapon& humanWeapon) 
	: name(humanName), weapon(humanWeapon)
{
	std::cout << "HumanA " << name << " created with " << weapon.getType() << std::endl;
}

// Attacco - usa sempre l'arma (garantita dal reference)
void HumanA::attack() const
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}