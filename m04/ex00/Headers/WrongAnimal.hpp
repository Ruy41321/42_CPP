#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal {
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal &original);
		WrongAnimal &operator=(WrongAnimal &to_copy);
		virtual~WrongAnimal();

		std::string getType(void) const;

		void makeSound(void) const;
};

#endif