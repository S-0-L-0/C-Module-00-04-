
#include "Zombie.hpp"

// Costruttore - inizializza il nome dello zombie
Zombie::Zombie(std::string zombieName) : name(zombieName)
{
	std::cout << name << " is born!" << std::endl;
}

// Distruttore - messaggio di debug quando lo zombie viene distrutto
Zombie::~Zombie()
{
	std::cout << name << " is destroyed!" << std::endl;
}

// Metodo announce - lo zombie si annuncia
void Zombie::announce() const
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
