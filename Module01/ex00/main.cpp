#include "Zombie.hpp"

int main()
{
	std::cout << "=== ZOMBIE EXERCISE DEMO ===" << std::endl;
	
	// Test 1: Creazione zombie con newZombie (HEAP)
	std::cout << "\n--- Test 1: newZombie() - Heap allocation ---" << std::endl;
	Zombie* heapZombie = newZombie("HeapWalker");
	heapZombie->announce();
	// Lo zombie esiste ancora! Dobbiamo eliminarlo manualmente
	delete heapZombie;  // Importante: libera la memoria!
	
	// Test 2: Creazione zombie con randomChump (STACK)
	std::cout << "\n--- Test 2: randomChump() - Stack allocation ---" << std::endl;
	randomChump("StackBiter");
	// Lo zombie è già stato distrutto automaticamente!
	
	// Test 3: Dimostrazione della differenza
	std::cout << "\n--- Test 3: Multiple zombies ---" << std::endl;
	
	// Heap zombies - sopravvivono alla funzione
	Zombie* zombie1 = newZombie("Persistent1");
	Zombie* zombie2 = newZombie("Persistent2");
	
	zombie1->announce();
	zombie2->announce();
	
	// Stack zombie - viene distrutto subito
	randomChump("Temporary");
	
	std::cout << "\nHeap zombies are still alive here!" << std::endl;
	zombie1->announce();
	zombie2->announce();
	
	// Cleanup: eliminiamo i zombie heap
	std::cout << "\nCleaning up heap zombies..." << std::endl;
	delete zombie1;
	delete zombie2;
	
	std::cout << "\nProgram ending..." << std::endl;
	return 0;
}
