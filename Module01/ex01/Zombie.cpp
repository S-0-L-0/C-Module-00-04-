
#include "Zombie.hpp"

Zombie::Zombie()
{
	name = "Unnamed";
	std::cout << "A nameless zombie is born!" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << name << " is destroyed!" << std::endl;
}

void Zombie::setName(std::string zombieName)
{
	name = zombieName;
	std::cout << "Zombie is now named " << name << std::endl;
}

void Zombie::announce() const
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}