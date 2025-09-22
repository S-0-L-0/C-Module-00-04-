#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>

class PhoneBook
{
private:
	Contact contacts[8];	// Array di massimo 8 contatti (allocazione statica)
	int currentIndex;		// Indice del prossimo contatto da inserire
	int contactCount;		// Numero totale di contatti inseriti

	// Metodi privati di utilità
	std::string truncateString(std::string str) const;
	std::string getInput(std::string prompt) const;
	bool isValidIndex(int index) const;

public:
	PhoneBook();
	
	// Metodi pubblici per i comandi
	void addContact();
	void searchContacts();
	void displayContactList() const;
	void displayContact(int index) const;
	
	// Metodo per ottenere input dall'utente
	std::string getCommand() const;
};

#endif