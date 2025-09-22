
#include "Zombie.hpp"

int main()
{
	std::cout << "=== ZOMBIE HORDE EXERCISE ===" << std::endl;
	
	// Test 1: Creare una piccola orda
	std::cout << "\n--- Test 1: Small horde (5 zombies) ---" << std::endl;
	int hordeSize1 = 5;
	Zombie* smallHorde = zombieHorde(hordeSize1, "Walker");
	
	if (smallHorde != nullptr)
	{
		// Tutti gli zombie si annunciano
		std::cout << "\nAll zombies announce themselves:" << std::endl;
		for (int i = 0; i < hordeSize1; i++)
		{
			smallHorde[i].announce();
		}
		
		// Pulizia memoria - IMPORTANTE!
		std::cout << "\nDestroying small horde..." << std::endl;
		delete[] smallHorde;
	}
	
	// Test 2: Orda più grande
	std::cout << "\n--- Test 2: Large horde (10 zombies) ---" << std::endl;
	int hordeSize2 = 10;
	Zombie* largeHorde = zombieHorde(hordeSize2, "Horde");
	
	if (largeHorde != nullptr)
	{
		// Solo alcuni zombie si annunciano (per non riempire troppo l'output)
		std::cout << "\nFirst 3 zombies announce:" << std::endl;
		for (int i = 0; i < 3 && i < hordeSize2; i++)
		{
			largeHorde[i].announce();
		}
		
		std::cout << "\nLast 3 zombies announce:" << std::endl;
		for (int i = hordeSize2 - 3; i < hordeSize2; i++)
		{
			if (i >= 0)
				largeHorde[i].announce();
		}
		
		// Pulizia memoria
		std::cout << "\nDestroying large horde..." << std::endl;
		delete[] largeHorde;
	}
	
	// Test 3: Caso edge - orda di 1 zombie
	std::cout << "\n--- Test 3: Single zombie horde ---" << std::endl;
	Zombie* singleHorde = zombieHorde(1, "Lonely");
	
	if (singleHorde != nullptr)
	{
		singleHorde[0].announce();
		delete[] singleHorde;
	}
	
	// Test 4: Caso edge - orda invalida
	std::cout << "\n--- Test 4: Invalid horde size ---" << std::endl;
	Zombie* invalidHorde = zombieHorde(0, "Invalid");
	if (invalidHorde == nullptr)
	{
		std::cout << "Correctly handled invalid horde size!" << std::endl;
	}
	
	// Test 5: Dimostrazione accesso array
	std::cout << "\n--- Test 5: Array access demonstration ---" << std::endl;
	Zombie* testHorde = zombieHorde(3, "Test");
	
	if (testHorde != nullptr)
	{
		std::cout << "\nAccessing zombies by index:" << std::endl;
		std::cout << "Zombie 0: ";
		testHorde[0].announce();
		
		std::cout << "Zombie 1: ";
		testHorde[1].announce();
		
		std::cout << "Zombie 2: ";
		testHorde[2].announce();
		
		// Dimostrazione che sono oggetti contigui in memoria
		std::cout << "\nMemory addresses:" << std::endl;
		for (int i = 0; i < 3; i++)
		{
			std::cout << "Zombie " << i << " address: " << &testHorde[i] << std::endl;
		}
		
		delete[] testHorde;
	}
	
	std::cout << "\n=== All tests completed! ===" << std::endl;
	return 0;
}