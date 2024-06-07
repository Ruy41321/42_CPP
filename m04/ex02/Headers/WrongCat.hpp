#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal{
	public:
		WrongCat();
		WrongCat(WrongCat &worngCat);
		WrongCat &operator=(WrongCat &wrongCat);
		~WrongCat();

		void makeSound(void) const;
};

#endif