#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(){
    std::cout << "Default constructor called" << std::endl;
    this->setRawBits(0);
}

Fixed::Fixed(const Fixed &fixed){
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed::Fixed(const int value){
    std::cout << "Int constructor called" << std::endl;
    this->value = value * (1 << Fixed::fractionalBits);
}

Fixed::Fixed(const float value){
    std::cout << "Float constructor called" << std::endl;
    this->value = roundf(value * (1 << Fixed::fractionalBits));
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(fixed.getRawBits());
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fxd)
{
	out << fxd.toFloat();
	return out;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    //std::cout << "getRawBits member function called" << std::endl;
    return this->value;
}

void Fixed::setRawBits(int const rawBits) {
	this->value = rawBits;
}

float Fixed::toFloat(void) const {
	return (float)this->value / (float)(1 << Fixed::fractionalBits);
}

int Fixed::toInt(void) const {
	return this->value >> Fixed::fractionalBits;
}