
#include "Zombie.hpp"

// Costruttore di default - necessario per creare array
Zombie::Zombie()
{
	name = "Unnamed";
	std::cout << "A nameless zombie is born!" << std::endl;
}

// Costruttore con parametro (dall'esercizio precedente)
Zombie::Zombie(std::string zombieName) : name(zombieName)
{
	std::cout << name << " is born!" << std::endl;
}

// Distruttore - messaggio di debug quando lo zombie viene distrutto
Zombie::~Zombie()
{
	std::cout << name << " is destroyed!" << std::endl;
}

// Metodo per impostare il nome (NUOVO per questo esercizio)
void Zombie::setName(std::string zombieName)
{
	name = zombieName;
	std::cout << "Zombie is now named " << name << std::endl;
}

// Metodo announce - lo zombie si annuncia
void Zombie::announce() const
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}