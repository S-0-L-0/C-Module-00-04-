
#include "StringReplacer.hpp"

int main(int argc, char **argv)
{
	std::cout << "=== SED IS FOR LOSERS ===" << std::endl;
	
	if (argc != 4)
	{
		std::cout << "Error: Wrong number of arguments" << std::endl;
		std::cout << "Expected: 3 arguments, got: " << (argc - 1) << std::endl;
		StringReplacer helper("", "", "");
		helper.printUsage();
		return 1;
	}
	std::string filename = argv[1];
	std::string searchString = argv[2];
	std::string replaceString = argv[3];
	std::cout << "\nFile: " << filename << std::endl;
	std::cout << "Source: '" << searchString << "'" << std::endl;
	std::cout << "Destination: '" << replaceString << "'" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	StringReplacer replacer(filename, searchString, replaceString);
	bool success = replacer.processFile();
	if (success)
	{
		std::cout << "----------------------------------------" << std::endl;
		std::cout << "Operation completed successfully!" << std::endl;
		return 0;
	}
	else
	{
		std::cout << "----------------------------------------" << std::endl;
		std::cout << "Operation failed!" << std::endl;
		return 1;
	}
}