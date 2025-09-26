#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void testClapTrapBasics() {
	std::cout << "\n=== ClapTrap Basic Test ===" << std::endl;
	
	ClapTrap clap("CT-1");
	clap.attack("enemy");
	clap.takeDamage(5);
	clap.beRepaired(3);
}

void testScavTrapBasics() {
	std::cout << "\n=== ScavTrap Basic Test ===" << std::endl;
	
	ScavTrap scav("ST-1");
	scav.attack("enemy");
	scav.takeDamage(30);
	scav.beRepaired(10);
	scav.guardGate();
}

void testConstructionDestruction() {
	std::cout << "\n=== Construction/Destruction Chain Test ===" << std::endl;
	
	std::cout << "Creating ScavTrap:" << std::endl;
	ScavTrap warrior("Warrior");
	
	std::cout << "\nScavTrap going out of scope:" << std::endl;
}

void testInheritedBehavior() {
	std::cout << "\n=== Inherited Behavior Test ===" << std::endl;
	
	ScavTrap defender("Defender");
	
	// Test inherited methods work with ScavTrap values
	std::cout << "ScavTrap has " << 100 << " HP and " << 20 << " attack damage" << std::endl;
	defender.attack("target");
	defender.takeDamage(90);  // Still alive with 10 HP
	defender.attack("another_target");  // Should still work
	defender.guardGate();
}

void testScavTrapSpecialAbility() {
	std::cout << "\n=== ScavTrap Special Ability Test ===" << std::endl;
	
	ScavTrap guardian("Guardian");
	
	guardian.guardGate();  // Healthy guardian
	guardian.takeDamage(100);  // Kill the guardian
	guardian.guardGate();  // Dead guardian cannot guard
}

void testEnergyDepletion() {
	std::cout << "\n=== ScavTrap Energy Test ===" << std::endl;
	
	ScavTrap fighter("Fighter");
	
	// ScavTrap has 50 energy points
	for (int i = 1; i <= 25; i++) {
		if (i % 2 == 0) {
			fighter.beRepaired(1);
		} else {
			fighter.attack("target" + std::to_string(i));
		}
	}
	
	// Should have 25 energy left, do 25 more actions
	for (int i = 26; i <= 50; i++) {
		fighter.attack("final_target");
	}
	
	// Now should be out of energy
	fighter.attack("no_energy_target");
	fighter.guardGate();  // Should still work (doesn't require energy)
}

void testPolymorphicBehavior() {
	std::cout << "\n=== Polymorphic Behavior Test ===" << std::endl;
	
	ClapTrap* clap_ptr = new ClapTrap("PolyClap");
	ClapTrap* scav_ptr = new ScavTrap("PolyScav");
	
	clap_ptr->attack("target1");  // ClapTrap attack
	scav_ptr->attack("target2");  // Should call ClapTrap attack (no virtual)
	
	delete clap_ptr;
	delete scav_ptr;
}

int main() {
	std::cout << "========== SCAVTRAP COMPREHENSIVE TESTS ==========" << std::endl;
	
	testClapTrapBasics();
	testScavTrapBasics();
	testConstructionDestruction();
	testInheritedBehavior();
	testScavTrapSpecialAbility();
	testEnergyDepletion();
	testPolymorphicBehavior();
	
	std::cout << "\n========== ALL TESTS COMPLETED ==========" << std::endl;
	
	return 0;
}