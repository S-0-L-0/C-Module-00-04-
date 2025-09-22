
#include "Zombie.hpp"

// Crea uno zombie sullo STACK e lo fa annunciare
// Lo zombie viene distrutto automaticamente alla fine della funzione
void randomChump(std::string name)
{
	// Allocazione automatica sullo stack
	Zombie zombie(name);
	
	// Lo zombie si annuncia
	zombie.announce();
	
	// Alla fine della funzione, zombie viene distrutto automaticamente
}