
#include "Harl.hpp"

int main()
{
	std::cout << "=== HARL 2.0 - AUTOMATED COMPLAINING SYSTEM ===" << std::endl;
	
	// Crea Harl
	Harl harl;
	
	std::cout << "\n--- Testing all complaint levels ---" << std::endl;
	
	// Test tutti i livelli validi
	std::cout << "\n1. Testing DEBUG level:" << std::endl;
	harl.complain("DEBUG");
	
	std::cout << "\n2. Testing INFO level:" << std::endl;
	harl.complain("INFO");
	
	std::cout << "\n3. Testing WARNING level:" << std::endl;
	harl.complain("WARNING");
	
	std::cout << "\n4. Testing ERROR level:" << std::endl;
	harl.complain("ERROR");
	
	// Test livelli non validi
	std::cout << "\n--- Testing invalid levels ---" << std::endl;
	
	std::cout << "\n5. Testing unknown level:" << std::endl;
	harl.complain("CRITICAL");
	
	std::cout << "\n6. Testing lowercase level:" << std::endl;
	harl.complain("debug");
	
	std::cout << "\n7. Testing empty level:" << std::endl;
	harl.complain("");
	
	std::cout << "\n8. Testing random text:" << std::endl;
	harl.complain("I want pizza");
	
	// Test scenario realistico
	std::cout << "\n--- Realistic scenario: Harl having a bad day ---" << std::endl;
	
	std::cout << "\nHarl starts debugging his burger experience:" << std::endl;
	harl.complain("DEBUG");
	
	std::cout << "\nHarl realizes something is wrong:" << std::endl;
	harl.complain("INFO");
	
	std::cout << "\nHarl gets suspicious:" << std::endl;
	harl.complain("WARNING");
	
	std::cout << "\nHarl loses his mind:" << std::endl;
	harl.complain("ERROR");
	
	// Test performance - molte lamentele
	std::cout << "\n--- Performance test: Harl complaining non-stop ---" << std::endl;
	
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	for (int round = 0; round < 3; round++)
	{
		std::cout << "\nRound " << (round + 1) << " of complaints:" << std::endl;
		for (int i = 0; i < 4; i++)
		{
			harl.complain(levels[i]);
		}
	}
	
	std::cout << "\n=== Harl is exhausted from complaining. Session ended! ===" << std::endl;
	
	return 0;
}