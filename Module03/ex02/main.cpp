
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

void testFragTrapBasics() {
	std::cout << "\n=== FragTrap Basic Test ===" << std::endl;
	
	FragTrap frag("FT-1");
	frag.attack("enemy");
	frag.takeDamage(40);
	frag.beRepaired(15);
	frag.highFivesGuys();
}

void testFragTrapConstructionDestruction() {
	std::cout << "\n=== FragTrap Construction/Destruction Chain ===" << std::endl;
	
	std::cout << "Creating FragTrap:" << std::endl;
	FragTrap destroyer("Destroyer");
	
	std::cout << "\nFragTrap going out of scope:" << std::endl;
}

void testFragTrapValues() {
	std::cout << "\n=== FragTrap Values Test ===" << std::endl;
	
	FragTrap tank("Tank");
	
	std::cout << "FragTrap has 100 HP, 100 Energy, and 30 attack damage" << std::endl;
	tank.attack("target");  // Should show 30 damage
	tank.takeDamage(99);    // Should survive with 1 HP
	tank.attack("survivor_target");  // Should still work
	tank.highFivesGuys();   // Should work while alive
}

void testFragTrapSpecialAbility() {
	std::cout << "\n=== FragTrap Special Ability Test ===" << std::endl;
	
	FragTrap cheerful("Cheerful");
	
	cheerful.highFivesGuys();  // Healthy FragTrap
	cheerful.takeDamage(100);  // Kill the FragTrap
	cheerful.highFivesGuys();  // Dead FragTrap cannot high-five
}

void testFragTrapEnergyEndurance() {
	std::cout << "\n=== FragTrap Energy Endurance Test ===" << std::endl;
	
	FragTrap marathon("Marathon");
	
	std::cout << "FragTrap has 100 energy points - testing endurance:" << std::endl;
	
	// Use 50 energy points
	for (int i = 1; i <= 50; i++) {
		if (i % 10 == 0) {
			std::cout << "Energy checkpoint " << i << ": ";
		}
		if (i % 2 == 0) {
			marathon.beRepaired(1);
		} else {
			marathon.attack("training_target");
		}
	}
	
	std::cout << "50 energy points used, 50 remaining" << std::endl;
	marathon.highFivesGuys();  // Should still work
}

void testAllThreeClasses() {
	std::cout << "\n=== All Three Classes Comparison ===" << std::endl;
	
	ClapTrap clap("Basic");
	ScavTrap scav("Guardian"); 
	FragTrap frag("Destroyer");
	
	std::cout << "ClapTrap stats: 10 HP, 10 Energy, 0 Attack" << std::endl;
	clap.attack("test_target");
	
	std::cout << "ScavTrap stats: 100 HP, 50 Energy, 20 Attack" << std::endl;
	scav.attack("test_target");
	scav.guardGate();
	
	std::cout << "FragTrap stats: 100 HP, 100 Energy, 30 Attack" << std::endl;
	frag.attack("test_target");
	frag.highFivesGuys();
}

void testPolymorphicBehaviorAllClasses() {
	std::cout << "\n=== Polymorphic Behavior - All Classes ===" << std::endl;
	
	ClapTrap* clap_ptr = new ClapTrap("PolyClap");
	ClapTrap* scav_ptr = new ScavTrap("PolyScav");
	ClapTrap* frag_ptr = new FragTrap("PolyFrag");
	
	clap_ptr->attack("target1");  // ClapTrap attack, 0 damage
	scav_ptr->attack("target2");  // ClapTrap attack, 20 damage
	frag_ptr->attack("target3");  // ClapTrap attack, 30 damage
	
	delete clap_ptr;
	delete scav_ptr;
	delete frag_ptr;
}

// Previous test functions remain the same
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

int main() {
	std::cout << "========== FRAGTRAP COMPREHENSIVE TESTS ==========" << std::endl;
	
	testClapTrapBasics();
	testScavTrapBasics();
	testFragTrapBasics();
	testFragTrapConstructionDestruction();
	testFragTrapValues();
	testFragTrapSpecialAbility();
	testFragTrapEnergyEndurance();
	testAllThreeClasses();
	testPolymorphicBehaviorAllClasses();
	
	std::cout << "\n========== ALL TESTS COMPLETED ==========" << std::endl;
	
	return 0;
}