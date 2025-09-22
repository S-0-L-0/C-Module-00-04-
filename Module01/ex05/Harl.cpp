
#include "Harl.hpp"

// Costruttore
Harl::Harl()
{
	std::cout << "Harl has been created and is ready to complain!" << std::endl;
}

// Funzioni private per ogni livello di lamentela
void Harl::debug(void)
{
	std::cout << "[DEBUG] I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[INFO] I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[WARNING] I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ERROR] This is unacceptable! I want to speak to the manager now." << std::endl;
}

// Funzione principale che usa puntatori a funzioni membro
void Harl::complain(std::string level)
{
	// Array di stringhe per i livelli
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	// Array di puntatori a funzioni membro
	// Sintassi: void (Harl::*functionPtr)(void)
	void (Harl::*functions[4])(void) = {
		&Harl::debug,
		&Harl::info, 
		&Harl::warning,
		&Harl::error
	};
	
	// Cerca il livello corrispondente
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			// Chiama la funzione attraverso il puntatore
			// Sintassi: (this->*functionPointer)()
			(this->*functions[i])();
			return;
		}
	}
	
	// Se il livello non è riconosciuto
	std::cout << "[UNKNOWN] Harl doesn't know how to complain at level: " << level << std::endl;
}