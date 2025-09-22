
#include "Weapon.hpp"

// Costruttore - inizializza il tipo di arma
Weapon::Weapon(std::string weaponType) : type(weaponType)
{
	std::cout << "Weapon created: " << type << std::endl;
}

// Getter - restituisce const reference (nessuna copia, nessuna modifica)
const std::string& Weapon::getType() const
{
	return type;
}

// Setter - cambia il tipo di arma
void Weapon::setType(std::string newType)
{
	std::cout << "Weapon type changed from '" << type << "' to '" << newType << "'" << std::endl;
	type = newType;
}