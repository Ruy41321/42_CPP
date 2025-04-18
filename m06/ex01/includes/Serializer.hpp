#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

# include <string>
# include <stdint.h>
# include "Data.hpp"

class Serializer
{
	private:
		Serializer() {}

	public:
		static uintptr_t serialize(data_t *ptr);
		static data_t *deserialize(uintptr_t raw);
};

#endif