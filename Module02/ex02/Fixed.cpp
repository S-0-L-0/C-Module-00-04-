
#include "Fixed.hpp"

Fixed::Fixed() : num(0) {
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : num(value << frac) {
    // std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : num(roundf(value * (1 << frac))) {
    // std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    // std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::~Fixed() {
    // std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->num = other.getRawBits();
    return *this;
}

bool Fixed::operator>(const Fixed& other) const {
    return this->num > other.num;
}

bool Fixed::operator<(const Fixed& other) const {
    return this->num < other.num;
}

bool Fixed::operator>=(const Fixed& other) const {
    return this->num >= other.num;
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->num <= other.num;
}

bool Fixed::operator==(const Fixed& other) const {
    return this->num == other.num;
}

bool Fixed::operator!=(const Fixed& other) const {
    return this->num != other.num;
}

Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->num + other.num);
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->num - other.num);
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    long long temp = (long long)this->num * other.num;
    result.setRawBits((int)(temp >> frac));
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    Fixed result;
    long long temp = ((long long)this->num << frac) / other.num;
    result.setRawBits((int)temp);
    return result;
}

Fixed& Fixed::operator++() {
    this->num += 1;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    this->num += 1;
    return temp;
}

Fixed& Fixed::operator--() {
    this->num -= 1;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    this->num -= 1;
    return temp;
}

Fixed& Fixed::min(Fixed& first, Fixed& second) {
    return (first < second) ? first : second;
}

const Fixed& Fixed::min(const Fixed& first, const Fixed& second) {
    return (first < second) ? first : second;
}

Fixed& Fixed::max(Fixed& first, Fixed& second) {
    return (first > second) ? first : second;
}

const Fixed& Fixed::max(const Fixed& first, const Fixed& second) {
    return (first > second) ? first : second;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(this->num) / (1 << frac);
}

int Fixed::toInt(void) const {
    return this->num >> frac;
}

int Fixed::getRawBits(void) const {
    // std::cout << "getRawBits member function called" << std::endl;
    return this->num;
}

void Fixed::setRawBits(int const raw) {
    this->num = raw;
}

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed) {
    stream << fixed.toFloat();
    return stream;
}