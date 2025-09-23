
	#include "Zombie.hpp"
	#include <sstream>
	
	Zombie* zombieHorde(int N, std::string name)
	{
		if (N <= 0)
		{
			std::cout << "Cannot create horde of " << N << " zombies!" << std::endl;
			return NULL;
		}
		std::cout << "Creating horde of " << N << " zombies..." << std::endl;
		Zombie* horde = new Zombie[N];
		for (int i = 0; i < N; i++)
		{
			std::stringstream ss;
			ss << name << "_" << i;
			std::string zombieName = ss.str();
			horde[i].setName(zombieName);
		}
		std::cout << "Horde of " << N << " zombies created!" << std::endl;
		return horde;
	}