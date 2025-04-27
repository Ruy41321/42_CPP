#include <PmergeMe.hpp>
#include <iostream>
#include <ctime>

int main(int argc, char **argv){
	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " <numbers>" << std::endl;
		return 1;
	}

	std::vector<int> vec;
	std::list<int> lst;

	for (int i = 1; i < argc; ++i) {
		int num = std::atoi(argv[i]);
		if (num < 0) {
			std::cerr << "Error: Negative numbers are not allowed." << std::endl;
			return 1;
		}
		if (std::find(vec.begin(), vec.end(), num) != vec.end()) {
            std::cerr << "Error: Duplicate number detected: " << num << std::endl;
            return 1;
        }
		vec.push_back(num);
		lst.push_back(num);
	}
	std::cout << "Before: " << PmergeMe::VectorToStr(vec) << std::endl;

	std::vector<int> vecCopy(vec);
	clock_t startVec = clock();
	PmergeMe::mergeInsertSortVector(vec);
    clock_t endVec = clock();
	double durationVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000; // Microsecondi

    clock_t startList = clock();
    PmergeMe::mergeInsertSortList(lst);
    clock_t endList = clock();
    double durationList = static_cast<double>(endList - startList) / CLOCKS_PER_SEC * 1000000; // Microsecondi

	std::cout << "After: " << PmergeMe::ListToStr(lst) << std::endl;

    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " 
              << durationVec << " us" << std::endl;
    std::cout << "Time to process a range of " << lst.size() << " elements with std::list: " 
              << durationList << " us" << std::endl;

	
	// 		  int is_vec_sorted = 1;
	// 		  for (size_t i = 1; i < vec.size(); ++i) {
	// 			  if (vec[i] < vec[i - 1]) {
	// 				  is_vec_sorted = 0;
	// 				  break;
	// 			  }
	// 		  }
	// 		  int is_sorted_list = 1;
	// 		  for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it) {
	// 			  std::list<int>::const_iterator next_it = it;
	// 			  ++next_it;
	// 			  if (next_it != lst.end() && *it > *next_it) {
	// 				  is_sorted_list = 0;
	// 				  break;
	// 			  }
	// 		  }
	// std::cout << "\nAre numbers from both process sorted? -> " << (is_sorted_list && is_vec_sorted? "yes" : "no") << std::endl;

	return 0;
}