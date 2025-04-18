#include "../includes/Serializer.hpp"
#include "../includes/Data.hpp"

uintptr_t Serializer::serialize(data_t *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

data_t *Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<data_t *>(raw);
}