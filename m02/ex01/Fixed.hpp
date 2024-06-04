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
    
    int getRawBits( void ) const;

    void setRawBits( int const raw );

    int toInt( void ) const;

    float toFloat( void ) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fxd);

#endif