
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void testRequiredExample() {
	std::cout << "\n=== Required Example Test ===" << std::endl;
	
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	
	i->makeSound(); // will output the cat sound!
	j->makeSound();
	meta->makeSound();
	
	delete meta;
	delete j;
	delete i;
}

void testWrongClasses() {
	std::cout << "\n=== Wrong Classes Test ===" << std::endl;
	
	const WrongAnimal* wrong_meta = new WrongAnimal();
	const WrongAnimal* wrong_cat = new WrongCat();
	
	std::cout << "WrongCat type: " << wrong_cat->getType() << std::endl;
	wrong_cat->makeSound(); // Should output WrongAnimal sound!
	wrong_meta->makeSound();
	
	delete wrong_meta;
	delete wrong_cat;
}

void testVirtualVsNonVirtual() {
	std::cout << "\n=== Virtual vs Non-Virtual Comparison ===" << std::endl;
	
	std::cout << "With virtual functions (correct polymorphism):" << std::endl;
	Animal* dog = new Dog();
	dog->makeSound(); // Dog sound
	delete dog;
	
	std::cout << "\nWithout virtual functions (no polymorphism):" << std::endl;
	WrongAnimal* wrong_cat = new WrongCat();
	wrong_cat->makeSound(); // WrongAnimal sound
	delete wrong_cat;
}

void testConstructorDestructorChain() {
	std::cout << "\n=== Constructor/Destructor Chain Test ===" << std::endl;
	
	std::cout << "Creating Dog:" << std::endl;
	Animal* animal_dog = new Dog();
	
	std::cout << "\nDestroying Dog:" << std::endl;
	delete animal_dog;
}

void testCopyAndAssignment() {
	std::cout << "\n=== Copy and Assignment Test ===" << std::endl;
	
	Dog original_dog;
	Dog copied_dog(original_dog);
	
	Cat cat1;
	Cat cat2;
	cat2 = cat1;
	
	std::cout << "Testing sounds after copy/assignment:" << std::endl;
	copied_dog.makeSound();
	cat2.makeSound();
}

void testDirectObjectsVsPointers() {
	std::cout << "\n=== Direct Objects vs Pointers Test ===" << std::endl;
	
	std::cout << "Direct objects:" << std::endl;
	Dog direct_dog;
	Cat direct_cat;
	direct_dog.makeSound();
	direct_cat.makeSound();
	
	std::cout << "\nPointers to base class:" << std::endl;
	Animal* ptr_dog = new Dog();
	Animal* ptr_cat = new Cat();
	ptr_dog->makeSound();
	ptr_cat->makeSound();
	
	delete ptr_dog;
	delete ptr_cat;
}

void testArrayOfAnimals() {
	std::cout << "\n=== Array of Animals Test ===" << std::endl;
	
	const int size = 4;
	Animal* zoo[size];
	
	zoo[0] = new Animal();
	zoo[1] = new Dog();
	zoo[2] = new Cat();
	zoo[3] = new Dog();
	
	std::cout << "Zoo sounds:" << std::endl;
	for (int i = 0; i < size; i++) {
		std::cout << "Animal " << i << " (" << zoo[i]->getType() << "): ";
		zoo[i]->makeSound();
	}
	
	std::cout << "\nCleaning up zoo:" << std::endl;
	for (int i = 0; i < size; i++) {
		delete zoo[i];
	}
}

int main() {
	std::cout << "========== POLYMORPHISM COMPREHENSIVE TESTS ==========" << std::endl;
	
	testRequiredExample();
	testWrongClasses();
	testVirtualVsNonVirtual();
	testConstructorDestructorChain();
	testCopyAndAssignment();
	testDirectObjectsVsPointers();
	testArrayOfAnimals();
	
	std::cout << "\n========== ALL TESTS COMPLETED ==========" << std::endl;
	
	return 0;
}