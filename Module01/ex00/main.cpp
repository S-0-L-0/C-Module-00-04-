#include "Zombie.hpp"

int main()
{
	std::cout << "=== ZOMBIE EXERCISE DEMO ===" << std::endl;
	
	std::cout << "\n--- Test 1: newZombie() - Heap allocation ---" << std::endl;
	Zombie* heapZombie = newZombie("HeapWalker");
	heapZombie->announce();
	delete heapZombie;
	
	std::cout << "\n--- Test 2: randomChump() - Stack allocation ---" << std::endl;
	randomChump("StackBiter");

	std::cout << "\n--- Test 3: Multiple zombies ---" << std::endl;
	Zombie* zombie1 = newZombie("HeapWalker1");
	Zombie* zombie2 = newZombie("HeapWalker2");
	zombie1->announce();
	zombie2->announce();
	randomChump("StackWalker");
	std::cout << "\nHeap zombies are still alive here!" << std::endl;
	zombie1->announce();
	zombie2->announce();
	std::cout << "\nCleaning up heap zombies..." << std::endl;
	delete zombie1;
	delete zombie2;
	std::cout << "\nProgram ending..." << std::endl;
	return 0;
}
