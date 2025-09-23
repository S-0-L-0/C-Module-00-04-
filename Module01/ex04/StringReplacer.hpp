
#ifndef STRINGREPLACER_HPP
#define STRINGREPLACER_HPP

#include <iostream>
#include <fstream>
#include <string>

class StringReplacer
{
private:
	std::string filename;
	std::string s1;
	std::string s2;
	
	bool isValidInput() const;
	std::string getOutputFilename() const;
	std::string replaceAllOccurrences(const std::string& content) const;

public:
	StringReplacer(const std::string& fileName, const std::string& search, const std::string& replace);
	bool processFile() const;
	void printUsage() const;
};

#endif