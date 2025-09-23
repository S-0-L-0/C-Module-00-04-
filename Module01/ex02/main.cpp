#include <iostream>
#include <string>

int main()
{
	std::cout << "=== HI THIS IS BRAIN EXERCISE ===" << std::endl;
	
	std::string brain = "HI THIS IS BRAIN";
	std::string* stringPTR = &brain;
	std::string& stringREF = brain;
	
	std::cout << "\n--- MEMORY ADDRESSES ---" << std::endl;
	
	std::cout << "Memory address of string variable: " << &brain << std::endl;
	std::cout << "Memory address held by stringPTR:  " << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF:  " << &stringREF << std::endl;
	
	std::cout << "\n--- VALUES ---" << std::endl;
	
	std::cout << "Value of string variable: " << brain << std::endl;
	std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;

	std::cout << "\n=== CONCLUSION: References and pointers access the same memory! ===" << std::endl;
	
	return 0;
}