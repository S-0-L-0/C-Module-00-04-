
#include "HumanB.hpp"

// Costruttore - NON riceve arma, inizializza a NULL
HumanB::HumanB(std::string humanName) : name(humanName), weapon(nullptr)
{
	std::cout << "HumanB " << name << " created without weapon" << std::endl;
}

// Setter per arma - prende reference ma salva come pointer
void HumanB::setWeapon(Weapon& humanWeapon)
{
	weapon = &humanWeapon;  // Salva l'indirizzo della arma
	std::cout << name << " is now armed with " << weapon->getType() << std::endl;
}

// Attacco - controlla se ha un'arma prima di usarla
void HumanB::attack() const
{
	if (weapon != nullptr)
	{
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	}
	else
	{
		std::cout << name << " attacks with their bare hands (no weapon!)" << std::endl;
	}
}