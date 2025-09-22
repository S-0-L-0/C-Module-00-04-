
#include <iostream>

int main(int ac, char **av)
{
	if (ac == 2)
	{
		unsigned long i = -1;
		std::string str = av[1];
		while (++i <= str.length())
			str[i] = toupper(str[i]);
		std::cout << str << "\n"; 
		return (0);
	}
	else if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	return (1);
}