
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	std::cout << "=== UNNECESSARY VIOLENCE EXERCISE ===" << std::endl;
	
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

	std::cout << "\n=== All tests completed! ===" << std::endl;
	return 0;
}