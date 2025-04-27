#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <cassert>

class PmergeMe {
public:
	PmergeMe();
	PmergeMe(const PmergeMe &src);
	PmergeMe &operator=(const PmergeMe &src);
	~PmergeMe();

	static std::string VectorToStr(const std::vector<int> &vec);
	static std::string ListToStr(const std::list<int> &lst);
	static void mergeInsertSortVector(std::vector<int> &vec);
	static void mergeInsertSortList(std::list<int> &lst);
};

#endif