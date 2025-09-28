
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
	
	for (int i = 1; i <= 10; i++) {
		std::cout << "Action " << i << ": ";
		if (i % 2 == 0) {
			robot.beRepaired(1);
		} else {
			robot.attack("target" + std::to_string(i));
		}
	}
	
	std::cout << "Trying to act with no energy:" << std::endl;
	robot.attack("final_target");
	robot.beRepaired(5);
}

void testHealthDepletion() {
	std::cout << "\n=== Health Depletion Test ===" << std::endl;
	ClapTrap robot("C3PO");
	robot.takeDamage(15);
	robot.attack("enemy");
	robot.beRepaired(5);
}

void testEdgeCases() {
	std::cout << "\n=== Edge Cases Test ===" << std::endl;
	ClapTrap robot("BB-8");
	robot.takeDamage(0);
	robot.beRepaired(0);
	robot.attack("training_dummy");
	robot.takeDamage(3);
	robot.takeDamage(3);
	robot.takeDamage(3);
	robot.takeDamage(2);
	robot.takeDamage(5);
}

void testRepairHealing() {
	std::cout << "\n=== Repair and Healing Test ===" << std::endl;
	ClapTrap robot("SENTRY");
	robot.takeDamage(8);
	robot.beRepaired(5);
	robot.beRepaired(10);
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