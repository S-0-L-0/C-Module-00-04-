
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
	int num;
	static const int frac = 8;

public:
	// Orthodox Canonical Form + costruttori
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed& other);
	~Fixed();
	Fixed& operator=(const Fixed& other);

	// Operatori di confronto
	bool operator>(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;

	// Operatori aritmetici - RITORNANO Fixed
	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;

	// Incremento/decremento
	Fixed& operator++();      // Pre-incremento
	Fixed operator++(int);    // Post-incremento
	Fixed& operator--();      // Pre-decremento
	Fixed operator--(int);    // Post-decremento

	// Funzioni statiche
	static Fixed& min(Fixed& first, Fixed& second);
	static const Fixed& min(const Fixed& first, const Fixed& second);
	static Fixed& max(Fixed& first, Fixed& second);
	static const Fixed& max(const Fixed& first, const Fixed& second);

	// Conversioni
	float toFloat(void) const;
	int toInt(void) const;
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed);

#endif