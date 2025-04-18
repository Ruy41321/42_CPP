#include "includes/Serializer.hpp"

#include <iostream>

int main()
{
	data_t data;
	data.n = 42;
	data.s = "Hello, World!";

	std::cout << "Original data: " << data.n << ", " << data.s << std::endl;

	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Serialized data: " << raw << std::endl;

	data_t *deserializedData = Serializer::deserialize(raw);
	std::cout << "Deserialized data: " << deserializedData->n << ", " << deserializedData->s << std::endl;

	return 0;
}