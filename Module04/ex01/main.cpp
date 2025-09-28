
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

void testRequiredArrayDeletion() {
	std::cout << "\n=== Required Array Test ===" << std::endl;
	
	const int size = 10;  // 5 dogs + 5 cats
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
		delete animals[i];  // Must call derived destructors due to virtual
	}
}

void testDeepCopy() {
	std::cout << "\n=== Deep Copy Test ===" << std::endl;
	
	std::cout << "Creating original dog:" << std::endl;
	Dog original_dog;
	original_dog.getBrain()->setIdea(0, "I love bones");
	original_dog.getBrain()->setIdea(1, "Cats are interesting");
	
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

void testAssignmentDeepCopy() {
	std::cout << "\n=== Assignment Deep Copy Test ===" << std::endl;
	
	Cat cat1;
	Cat cat2;
	
	cat1.getBrain()->setIdea(0, "I love fish");
	cat1.getBrain()->setIdea(1, "Dogs are loud");
	
	std::cout << "Before assignment:" << std::endl;
	std::cout << "Cat1 idea 0: " << cat1.getBrain()->getIdea(0) << std::endl;
	std::cout << "Cat2 idea 0: " << cat2.getBrain()->getIdea(0) << std::endl;
	
	cat2 = cat1;  // Assignment operator
	
	std::cout << "\nAfter assignment:" << std::endl;
	std::cout << "Cat1 idea 0: " << cat1.getBrain()->getIdea(0) << std::endl;
	std::cout << "Cat2 idea 0: " << cat2.getBrain()->getIdea(0) << std::endl;
	
	cat1.getBrain()->setIdea(0, "I changed my mind about fish");
	
	std::cout << "\nAfter modifying cat1:" << std::endl;
	std::cout << "Cat1 idea 0: " << cat1.getBrain()->getIdea(0) << std::endl;
	std::cout << "Cat2 idea 0: " << cat2.getBrain()->getIdea(0) << std::endl;
	
	if (cat1.getBrain()->getIdea(0) != cat2.getBrain()->getIdea(0)) {
		std::cout << "SUCCESS: Assignment deep copy working!" << std::endl;
	} else {
		std::cout << "FAILURE: Assignment shallow copy detected!" << std::endl;
	}
}

void testBrainPointerIndependence() {
	std::cout << "\n=== Brain Pointer Independence Test ===" << std::endl;
	
	Dog dog1;
	Dog dog2(dog1);
	
	std::cout << "Dog1 brain address: " << dog1.getBrain() << std::endl;
	std::cout << "Dog2 brain address: " << dog2.getBrain() << std::endl;
	
	if (dog1.getBrain() != dog2.getBrain()) {
		std::cout << "SUCCESS: Different brain pointers (deep copy)" << std::endl;
	} else {
		std::cout << "FAILURE: Same brain pointer (shallow copy)" << std::endl;
	}
}

void testMemoryLeakPrevention() {
	std::cout << "\n=== Memory Leak Prevention Test ===" << std::endl;
	
	std::cout << "Creating and destroying animals in scope:" << std::endl;
	{
		Dog* dog = new Dog();
		Cat* cat = new Cat();
		
		dog->getBrain()->setIdea(0, "Temporary thought");
		cat->getBrain()->setIdea(0, "Temporary idea");
		
		delete dog;
		delete cat;
	}
	std::cout << "Animals destroyed - check for proper cleanup" << std::endl;
}

int main() {
	std::cout << "========== BRAIN & DEEP COPY TESTS ==========" << std::endl;
	
	testRequiredArrayDeletion();
	testDeepCopy();
	testAssignmentDeepCopy();
	testBrainPointerIndependence();
	testMemoryLeakPrevention();
	
	std::cout << "\n========== ALL TESTS COMPLETED ==========" << std::endl;
	
	return 0;
}