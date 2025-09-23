
#include "Zombie.hpp"

int main()
{
	std::cout << "=== ZOMBIE HORDE EXERCISE ===" << std::endl;

	std::cout << "\n--- Test 1: Small horde (5 zombies) ---" << std::endl;
	int size = 5;
	Zombie* smallHorde = zombieHorde(size, "Horde");
	if (smallHorde != NULL)
	{
		std::cout << "\nAll zombies announce themselves:" << std::endl;
		for (int i = 0; i < size; i++)
		{
			smallHorde[i].announce();
		}
		std::cout << "\nDestroying small horde..." << std::endl;
		delete[] smallHorde;
	}
	
	std::cout << "\n--- Test 2: Large horde (10 zombies) ---" << std::endl;
	int size = 10;
	Zombie* largeHorde = zombieHorde(size, "Horde");
	if (largeHorde != NULL)
	{
		std::cout << "\nAll zombies announce themselves:" << std::endl;
		for (int i = 0; i < size; i++)
		{
			largeHorde[i].announce();
		}
		std::cout << "\nDestroying large horde..." << std::endl;
		delete[] largeHorde;
	}
	
	std::cout << "\n--- Test 3: Single zombie horde ---" << std::endl;
	Zombie* singleHorde = zombieHorde(1, "Lonely");
	if (singleHorde != NULL)
	{
		singleHorde[0].announce();
		delete[] singleHorde;
	}

	std::cout << "\n--- Test 4: Invalid horde size ---" << std::endl;
	Zombie* invalidHorde = zombieHorde(0, "Invalid");
	if (invalidHorde == NULL)
	{
		std::cout << "Correctly handled invalid horde size!" << std::endl;
	}

	std::cout << "\n=== All tests completed! ===" << std::endl;
	return 0;
}