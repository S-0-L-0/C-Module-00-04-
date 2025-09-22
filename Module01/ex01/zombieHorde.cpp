
#include "Zombie.hpp"

// Crea un'orda di N zombie con allocazione singola
Zombie* zombieHorde(int N, std::string name)
{
	// Controllo input valido
	if (N <= 0)
	{
		std::cout << "Cannot create horde of " << N << " zombies!" << std::endl;
		return nullptr;
	}
	
	std::cout << "Creating horde of " << N << " zombies..." << std::endl;
	
	// ALLOCAZIONE SINGOLA per N oggetti Zombie
	// Questo chiama il costruttore di default per ogni zombie
	Zombie* horde = new Zombie[N];
	
	// Inizializziamo ogni zombie con il nome dato
	for (int i = 0; i < N; i++)
	{
		// Creiamo un nome unico per ogni zombie
		std::string zombieName = name + "_" + std::to_string(i);
		horde[i].setName(zombieName);
	}
	
	std::cout << "Horde of " << N << " zombies created!" << std::endl;
	
	// Restituiamo il puntatore al primo zombie dell'array
	return horde;
}