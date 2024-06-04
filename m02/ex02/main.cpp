#include <iostream>
#include "Fixed.hpp"

void test(){
    Fixed a(5.05f);
    Fixed b(2.0f);

    // Test operatori di confronto
    std::cout << "a > b = " << (a > b) << std::endl;
    std::cout << "a < b = " << (a < b) << std::endl;
    std::cout << "a >= b = " << (a >= b) << std::endl;
    std::cout << "a <= b = " << (a <= b) << std::endl;
    std::cout << "a == b = " << (a == b) << std::endl;
    std::cout << "a != b = " << (a != b) << std::endl;

    // Test operatori aritmetici
    std::cout << "a + b = " << (a + b).toFloat() << std::endl;
    std::cout << "a - b = " << (a - b).toFloat() << std::endl;
    std::cout << "a * b = " << (a * b).toFloat() << std::endl;
    std::cout << "a / b = " << (a / b).toFloat() << std::endl;

    // Test operatori di incremento e decremento
    a++;
    std::cout << "a++ = " << a.toFloat() << std::endl;
    ++a;
    std::cout << "++a = " << a.toFloat() << std::endl;
    a--;
    std::cout << "a-- = " << a.toFloat() << std::endl;
    --a;
    std::cout << "--a = " << a.toFloat() << std::endl;

    // Test funzioni membro statiche min e max
    std::cout << "min(a, b) = " << Fixed::min(a, b).toFloat() << std::endl;
    std::cout << "max(a, b) = " << Fixed::max(a, b).toFloat() << std::endl;
}

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;

    std::cout << std::endl << "Test personali ...." << std::endl << std::endl;

    test();
    return 0;
}
