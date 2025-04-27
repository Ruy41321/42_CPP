#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{
public:
	MutantStack();
	~MutantStack();
	MutantStack(const MutantStack &other);
	MutantStack &operator=(const MutantStack &other);
	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin();
	iterator end();
};

#endif

template<typename T>
MutantStack<T>::MutantStack()
{}

template<typename T>
MutantStack<T>::MutantStack(MutantStack const& to_copy) {
	*this = to_copy;
}

template<typename T>
MutantStack<T>::~MutantStack()
{}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(MutantStack const& to_copy)
{
	std::stack<T>::operator=(to_copy);
	return *this;
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return std::stack<T>::c.begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return std::stack<T>::c.end();
}