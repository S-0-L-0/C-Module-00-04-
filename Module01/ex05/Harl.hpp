
#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl
{
private:
	// Funzioni private per ogni livello di lamentela
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

public:
	// Costruttore
	Harl();
	
	// Funzione pubblica principale che dispatcha alle funzioni private
	void complain(std::string level);
};

#endif