
#include "StringReplacer.hpp"

// Costruttore
StringReplacer::StringReplacer(const std::string& fileName, const std::string& search, const std::string& replace)
	: filename(fileName), s1(search), s2(replace)
{
}

// Valida l'input
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

// Genera il nome del file di output
std::string StringReplacer::getOutputFilename() const
{
	return filename + ".replace";
}

// Sostituisce tutte le occorrenze di s1 con s2 nel contenuto
std::string StringReplacer::replaceAllOccurrences(const std::string& content) const
{
	std::string result = content;
	size_t pos = 0;
	
	// Cerca e sostituisci fino a quando non ci sono più occorrenze
	while ((pos = result.find(s1, pos)) != std::string::npos)
	{
		// Rimuovi s1 e inserisci s2 nella stessa posizione
		result.erase(pos, s1.length());
		result.insert(pos, s2);
		
		// Muovi la posizione avanti di s2.length() per evitare loop infiniti
		pos += s2.length();
	}
	
	return result;
}

// Metodo principale per processare il file
bool StringReplacer::processFile() const
{
	// Valida input
	if (!isValidInput())
	{
		return false;
	}
	
	// Apri file di input
	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open())
	{
		std::cout << "Error: Cannot open file '" << filename << "'" << std::endl;
		return false;
	}
	
	// Leggi tutto il contenuto
	std::string content;
	std::string line;
	
	while (std::getline(inputFile, line))
	{
		content += line;
		if (!inputFile.eof())  // Aggiungi newline solo se non è l'ultima riga
		{
			content += "\n";
		}
	}
	
	inputFile.close();
	
	// Sostituisci le occorrenze
	std::string replacedContent = replaceAllOccurrences(content);
	
	// Crea file di output
	std::string outputFilename = getOutputFilename();
	std::ofstream outputFile(outputFilename.c_str());
	
	if (!outputFile.is_open())
	{
		std::cout << "Error: Cannot create output file '" << outputFilename << "'" << std::endl;
		return false;
	}
	
	// Scrivi contenuto modificato
	outputFile << replacedContent;
	outputFile.close();
	
	// Report successo
	std::cout << "Success: File processed!" << std::endl;
	std::cout << "Input:  " << filename << std::endl;
	std::cout << "Output: " << outputFilename << std::endl;
	std::cout << "Replaced '" << s1 << "' with '" << s2 << "'" << std::endl;
	
	return true;
}

// Stampa istruzioni d'uso
void StringReplacer::printUsage() const
{
	std::cout << "Usage: ./sed_replacer <filename> <search_string> <replace_string>" << std::endl;
	std::cout << "Example: ./sed_replacer input.txt \"hello\" \"hi\"" << std::endl;
}