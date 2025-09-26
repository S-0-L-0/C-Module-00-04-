
#include "ClapTrap.hpp"

void testBasicFunctionality() {
	std::cout << "\n=== Basic Functionality Test ===" << std::endl;
	
	ClapTrap robot("R2D2");
	
	robot.attack("enemy");
	robot.takeDamage(5);
	robot.beRepaired(3);
	
	std::cout << "Current status: functional" << std::endl;
}

void testEnergyDepletion() {
	std::cout << "\n=== Energy Depletion Test ===" << std::endl;
	
	ClapTrap robot("Wall-E");
	
	// Consume all 10 energy points
	for (int i = 1; i <= 10; i++) {
		std::cout << "Action " << i << ": ";
		if (i % 2 == 0) {
			robot.beRepaired(1);
		} else {
			robot.attack("target" + std::to_string(i));
		}
	}
	
	// Try actions with no energy
	std::cout << "Trying to act with no energy:" << std::endl;
	robot.attack("final_target");
	robot.beRepaired(5);
}

void testHealthDepletion() {
	std::cout << "\n=== Health Depletion Test ===" << std::endl;
	
	ClapTrap robot("C3PO");
	
	robot.takeDamage(15);  // More than total hit points
	
	// Try actions while dead
	robot.attack("enemy");
	robot.beRepaired(5);
}

void testEdgeCases() {
	std::cout << "\n=== Edge Cases Test ===" << std::endl;
	
	ClapTrap robot("BB-8");
	
	// Take zero damage
	robot.takeDamage(0);
	
	// Repair zero amount
	robot.beRepaired(0);
	
	// Attack with zero damage (default)
	robot.attack("training_dummy");
	
	// Multiple small damages
	robot.takeDamage(3);
	robot.takeDamage(3);
	robot.takeDamage(3);
	robot.takeDamage(2);  // Should result in death
	
	robot.takeDamage(5);  // Damage to already dead robot
}

void testRepairHealing() {
	std::cout << "\n=== Repair and Healing Test ===" << std::endl;
	
	ClapTrap robot("SENTRY");
	
	robot.takeDamage(8);  // Down to 2 HP
	robot.beRepaired(5);  // Back to 7 HP
	robot.beRepaired(10); // Up to 17 HP (over initial)
	
	robot.attack("healed_enemy");
}

void testConstructorDestructor() {
	std::cout << "\n=== Constructor/Destructor Test ===" << std::endl;
	
	std::cout << "Creating multiple ClapTraps:" << std::endl;
	ClapTrap robot1("Alpha");
	ClapTrap robot2("Beta");
	
	robot1.attack("Beta");
	robot2.attack("Alpha");
	
	std::cout << "ClapTraps going out of scope..." << std::endl;
}

int main() {
	std::cout << "========== CLAPTRAP COMPREHENSIVE TESTS ==========" << std::endl;
	
	testBasicFunctionality();
	testEnergyDepletion();
	testHealthDepletion();
	testEdgeCases();
	testRepairHealing();
	testConstructorDestructor();
	
	std::cout << "\n========== ALL TESTS COMPLETED ==========" << std::endl;
	
	return 0;
}