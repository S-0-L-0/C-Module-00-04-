
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	std::cout << "=== UNNECESSARY VIOLENCE EXERCISE ===" << std::endl;
	
	// Test case richiesto dall'esercizio
	std::cout << "\n--- Test Case 1: HumanA (always armed) ---" << std::endl;
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	
	std::cout << "\n--- Test Case 2: HumanB (optionally armed) ---" << std::endl;
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	
	// Test aggiuntivi per dimostrare le differenze
	std::cout << "\n--- Additional Tests ---" << std::endl;
	
	// Test HumanB senza arma
	std::cout << "\nTest: HumanB without weapon" << std::endl;
	{
		HumanB unarmed("Pacifist");
		unarmed.attack();  // Dovrebbe attaccare a mani nude
	}
	
	// Test cambiamento arma per HumanB
	std::cout << "\nTest: HumanB changing weapons" << std::endl;
	{
		Weapon sword("sharp sword");
		Weapon axe("heavy axe");
		
		HumanB warrior("Warrior");
		warrior.attack();  // Senza arma
		
		warrior.setWeapon(sword);
		warrior.attack();  // Con spada
		
		warrior.setWeapon(axe);
		warrior.attack();  // Con ascia
	}
	
	// Test per mostrare che HumanA non può esistere senza arma
	std::cout << "\nTest: HumanA must have weapon" << std::endl;
	{
		Weapon bow("elven bow");
		HumanA archer("Legolas", bow);
		archer.attack();
		
		// Non possiamo creare HumanA senza arma:
		// HumanA invalid();  ← Questo non compilerebbe!
	}
	
	std::cout << "\n=== All tests completed! ===" << std::endl;
	return 0;
}