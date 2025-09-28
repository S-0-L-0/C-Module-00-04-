
#include "Harl.hpp"

int main()
{
	std::cout << "=== HARL 2.0 - AUTOMATED COMPLAINING SYSTEM ===" << std::endl;
	
	Harl harl;
	
	std::cout << "\n--- Testing all complaint levels ---" << std::endl;
	
	std::cout << "\n1. Testing DEBUG level:" << std::endl;
	harl.complain("DEBUG");
	
	std::cout << "\n2. Testing INFO level:" << std::endl;
	harl.complain("INFO");
	
	std::cout << "\n3. Testing WARNING level:" << std::endl;
	harl.complain("WARNING");
	
	std::cout << "\n4. Testing ERROR level:" << std::endl;
	harl.complain("ERROR");
	
	std::cout << "\n--- Testing invalid levels ---" << std::endl;
	
	std::cout << "\n5. Testing unknown level:" << std::endl;
	harl.complain("CRITICAL");
	
	std::cout << "\n6. Testing lowercase level:" << std::endl;
	harl.complain("debug");
	
	std::cout << "\n7. Testing empty level:" << std::endl;
	harl.complain("");
	
	std::cout << "\n8. Testing random text:" << std::endl;
	harl.complain("I want pizza");
	
	std::cout << "\n=== Session ended! ===" << std::endl;
	
	return 0;
}