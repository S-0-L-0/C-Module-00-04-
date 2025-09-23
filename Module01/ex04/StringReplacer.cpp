
#include "StringReplacer.hpp"

StringReplacer::StringReplacer(const std::string& fileName, const std::string& search, const std::string& replace): filename(fileName), s1(search), s2(replace)
{
}

bool StringReplacer::isValidInput() const
{
	if (filename.empty())
	{
		std::cout << "Error: Filename cannot be empty" << std::endl;
		return false;
	}
	if (s1.empty())
	{
		std::cout << "Error: Search string cannot be empty" << std::endl;
		return false;
	}
	return true;
}

std::string StringReplacer::getOutputFilename() const
{
	return filename + ".replace";
}

std::string StringReplacer::replaceAllOccurrences(const std::string& content) const
{
	std::string result = content;
	size_t pos = 0;
	
	while ((pos = result.find(s1, pos)) != std::string::npos)
	{
		result.erase(pos, s1.length());
		result.insert(pos, s2);
		pos += s2.length();
	}
	return result;
}

bool StringReplacer::processFile() const
{
	if (!isValidInput())
	{
		return false;
	}
	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open())
	{
		std::cout << "Error: Cannot open file '" << filename << "'" << std::endl;
		return false;
	}
	std::string content;
	std::string line;
	while (std::getline(inputFile, line))
	{
		content += line;
		if (!inputFile.eof())
		{
			content += "\n";
		}
	}
	inputFile.close();
	std::string replacedContent = replaceAllOccurrences(content);
	std::string outputFilename = getOutputFilename();
	std::ofstream outputFile(outputFilename.c_str());
	if (!outputFile.is_open())
	{
		std::cout << "Error: Cannot create output file '" << outputFilename << "'" << std::endl;
		return false;
	}
	outputFile << replacedContent;
	outputFile.close();
	std::cout << "Success: File processed!" << std::endl;
	std::cout << "Input:  " << filename << std::endl;
	std::cout << "Output: " << outputFilename << std::endl;
	std::cout << "Replaced '" << s1 << "' with '" << s2 << "'" << std::endl;
	return true;
}

void StringReplacer::printUsage() const
{
	std::cout << "Usage: ./sed_replacer <filename> <search_string> <replace_string>" << std::endl;
	std::cout << "Example: ./sed_replacer input.txt \"hello\" \"hi\"" << std::endl;
}