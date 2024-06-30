#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int value;
    static const int fractionalBits = 8;

public:
    Fixed();
    
    Fixed(const Fixed &fixed);

    Fixed(int const value);

    Fixed(float const value);

    ~Fixed();

    Fixed &operator=(const Fixed &fixed);
    
    // Operatori di confronto
    bool operator>(const Fixed &other) const ;
    bool operator<(const Fixed &other) const ;
    bool operator>=(const Fixed &other) const ;
    bool operator<=(const Fixed &other) const ;
    bool operator==(const Fixed &other) const ;
    bool operator!=(const Fixed &other) const ;

    // Operatori aritmetici
    Fixed operator+(const Fixed &other) const ;
    Fixed operator-(const Fixed &other) const ;
    Fixed operator*(const Fixed &other) const ;
    Fixed operator/(const Fixed &other) const ;

    // Operatori di incremento/decremento
    Fixed &operator++() ; //pre
    Fixed operator++(int) ; //post
    Fixed &operator--() ; //pre
    Fixed operator--(int) ; //post

    static Fixed &min(Fixed &a, Fixed &b) ;

    static const Fixed &min(const Fixed &a, const Fixed &b) ;

    static Fixed &max(Fixed &a, Fixed &b) ;

    static const Fixed &max(const Fixed &a, const Fixed &b) ;

    int getRawBits( void ) const;

    void setRawBits( int const raw );

    int toInt( void ) const;

    float toFloat( void ) const;
};

std::ostream &operator<<(std::ostream &stream, const Fixed &bureaucrat);

#endif