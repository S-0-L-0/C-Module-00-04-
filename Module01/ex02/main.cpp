#include <iostream>
#include <string>

int main()
{
	std::cout << "=== HI THIS IS BRAIN EXERCISE ===" << std::endl;
	
	// 1. String variable inizializzata
	std::string brain = "HI THIS IS BRAIN";
	
	// 2. stringPTR: un puntatore alla stringa
	std::string* stringPTR = &brain;
	
	// 3. stringREF: un riferimento alla stringa
	std::string& stringREF = brain;
	
	std::cout << "\n--- MEMORY ADDRESSES ---" << std::endl;
	
	// Indirizzi di memoria
	std::cout << "Memory address of string variable: " << &brain << std::endl;
	std::cout << "Memory address held by stringPTR:  " << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF:  " << &stringREF << std::endl;
	
	std::cout << "\n--- VALUES ---" << std::endl;
	
	// Valori
	std::cout << "Value of string variable: " << brain << std::endl;
	std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;
	
	// Extra demo per comprensione
	std::cout << "\n--- EXTRA DEMONSTRATION ---" << std::endl;
	
	// Dimostrare che puntano alla stessa cosa
	std::cout << "All three access the same memory location:" << std::endl;
	std::cout << "brain == *stringPTR == stringREF? " << std::boolalpha 
			  << (brain == *stringPTR && *stringPTR == stringREF) << std::endl;
	
	// Modificare attraverso il riferimento
	std::cout << "\nModifying through stringREF..." << std::endl;
	stringREF = "MODIFIED THROUGH REFERENCE";
	
	std::cout << "After modification:" << std::endl;
	std::cout << "brain: " << brain << std::endl;
	std::cout << "*stringPTR: " << *stringPTR << std::endl;
	std::cout << "stringREF: " << stringREF << std::endl;
	
	// Modificare attraverso il puntatore
	std::cout << "\nModifying through stringPTR..." << std::endl;
	*stringPTR = "MODIFIED THROUGH POINTER";
	
	std::cout << "After modification:" << std::endl;
	std::cout << "brain: " << brain << std::endl;
	std::cout << "*stringPTR: " << *stringPTR << std::endl;
	std::cout << "stringREF: " << stringREF << std::endl;
	
	std::cout << "\n=== CONCLUSION: References and pointers access the same memory! ===" << std::endl;
	
	return 0;
}