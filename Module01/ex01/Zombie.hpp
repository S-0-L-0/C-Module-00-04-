
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
private:
	std::string name;

public:
	// Costruttore di default (NUOVO! Necessario per array)
	Zombie();
	
	// Costruttore con parametro (dall'esercizio precedente)
	Zombie(std::string zombieName);
	
	// Distruttore
	~Zombie();
	
	// Metodo per impostare il nome (NUOVO!)
	void setName(std::string zombieName);
	
	// Metodo per annunciarsi
	void announce() const;
};

// Funzione richiesta dall'esercizio
Zombie* zombieHorde(int N, std::string name);

#endif