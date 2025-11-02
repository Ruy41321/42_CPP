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
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	
	iterator begin();
	iterator end();
	const_iterator begin() const;
	const_iterator end() const;
};

#endif

template<typename T>
MutantStack<T>::MutantStack()
{}

template<typename T>
MutantStack<T>::MutantStack(MutantStack const& other) {
	*this = other;
}

template<typename T>
MutantStack<T>::~MutantStack()
{}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(MutantStack const& other)
{
	std::stack<T>::operator=(other);
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

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return std::stack<T>::c.begin();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	return std::stack<T>::c.end();
}