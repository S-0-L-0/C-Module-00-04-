
#include "Zombie.hpp"

// Crea uno zombie sull'HEAP e lo restituisce
// Lo zombie continua a esistere anche fuori dalla funzione
Zombie* newZombie(std::string name)
{
	// Allocazione dinamica con 'new'
	Zombie* zombie = new Zombie(name);
	
	return zombie;
}