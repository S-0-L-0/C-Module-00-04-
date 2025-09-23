
#include "Zombie.hpp"

Zombie::Zombie(std::string zombieName) : name(zombieName)
{
	std::cout << name << " is born!" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << name << " is destroyed!" << std::endl;
}

void Zombie::announce() const
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
