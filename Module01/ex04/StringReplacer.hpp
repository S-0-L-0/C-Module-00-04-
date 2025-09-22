
#ifndef STRINGREPLACER_HPP
#define STRINGREPLACER_HPP

#include <iostream>
#include <fstream>
#include <string>

class StringReplacer
{
private:
	std::string filename;
	std::string s1;  // Stringa da cercare
	std::string s2;  // Stringa di sostituzione
	
	// Metodi privati di utilità
	bool isValidInput() const;
	std::string getOutputFilename() const;
	std::string replaceAllOccurrences(const std::string& content) const;

public:
	// Costruttore
	StringReplacer(const std::string& fileName, const std::string& search, const std::string& replace);
	
	// Metodo principale per processare il file
	bool processFile() const;
	
	// Metodi di utilità
	void printUsage() const;
};

#endif