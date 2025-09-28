
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

void testRequiredArrayDeletion() {
	std::cout << "\n=== Required Array Test ===" << std::endl;
	
	const int size = 10;
	Animal* animals[size];
	
	std::cout << "Creating animals array:" << std::endl;
	for (int i = 0; i < size; i++) {
		if (i < size / 2) {
			animals[i] = new Dog();
		} else {
			animals[i] = new Cat();
		}
	}
	
	std::cout << "\nTesting sounds:" << std::endl;
	for (int i = 0; i < size; i++) {
		std::cout << "Animal " << i << " (" << animals[i]->getType() << "): ";
		animals[i]->makeSound();
	}
	
	std::cout << "\nDeleting animals as Animals:" << std::endl;
	for (int i = 0; i < size; i++) {
		delete animals[i];
	}
}

void testAbstractClass() {
	std::cout << "\n=== Abstract Class Test ===" << std::endl;
	
	std::cout << "Trying to create abstract Animal objects:" << std::endl;
	// Animal animal; // Questo NON compilerebbe più
	// Animal* ptr = new Animal(); // Neanche questo
	
	std::cout << "Creating concrete Dog and Cat objects:" << std::endl;
	Animal* dog = new Dog();
	Animal* cat = new Cat();
	
	dog->makeSound();
	cat->makeSound();
	
	delete dog;
	delete cat;
}

void testDeepCopy() {
	std::cout << "\n=== Deep Copy Test ===" << std::endl;
	
	std::cout << "Creating original dog:" << std::endl;
	Dog original_dog;
	original_dog.getBrain()->setIdea(0, "I love bones");
	
	std::cout << "\nCreating copy via copy constructor:" << std::endl;
	Dog copied_dog(original_dog);
	
	std::cout << "\nModifying original dog's brain:" << std::endl;
	original_dog.getBrain()->setIdea(0, "I changed my mind about bones");
	
	std::cout << "\nChecking if copies are independent:" << std::endl;
	std::cout << "Original dog idea 0: " << original_dog.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copied dog idea 0: " << copied_dog.getBrain()->getIdea(0) << std::endl;
	
	if (original_dog.getBrain()->getIdea(0) != copied_dog.getBrain()->getIdea(0)) {
		std::cout << "SUCCESS: Deep copy working correctly!" << std::endl;
	} else {
		std::cout << "FAILURE: Shallow copy detected!" << std::endl;
	}
}

void testPolymorphism() {
	std::cout << "\n=== Polymorphism Test ===" << std::endl;
	
	const int size = 4;
	Animal* zoo[size];
	
	zoo[0] = new Dog();
	zoo[1] = new Cat();
	zoo[2] = new Dog();
	zoo[3] = new Cat();
	
	std::cout << "Zoo sounds (polymorphic calls):" << std::endl;
	for (int i = 0; i < size; i++) {
		std::cout << "Animal " << i << " (" << zoo[i]->getType() << "): ";
		zoo[i]->makeSound();  // Chiamata polimorfica
	}
	
	for (int i = 0; i < size; i++) {
		delete zoo[i];
	}
}

int main() {
	std::cout << "========== ABSTRACT CLASS TESTS ==========" << std::endl;
	
	testRequiredArrayDeletion();
	testAbstractClass();
	testDeepCopy();
	testPolymorphism();
	
	std::cout << "\n========== ALL TESTS COMPLETED ==========" << std::endl;
	
	return 0;
}