#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "PmergeMe.hpp"

int main(int argc, char **argv) {

	if (argc < 2) {
		std::cerr << "Testing with various vector sizes." << std::endl;

		std::deque<int> vec;

		for (int i = 1; i < 11000; i++) {
			static int seed = 0;
			srand(time(NULL) + seed++);
			for (int j = 0; j < i; j++) {
				vec.push_back(rand() % 10000);  // Random numbers between 0 and 99
			}
			PmergeMe::sort_deque(vec.begin(), vec.end(), 1);
			// std::cout << i << " Sorted deque: ";
			// std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));

			bool isSorted = true;
			for (std::deque<int>::iterator it = vec.begin(); it != vec.end() - 1; ++it) {
				if (*it > *(it + 1)) {
					isSorted = false;
					break;
				}
			}
			if (!isSorted) {
				std::cout << "ERROR: deque is not sorted! " << i;
				std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
				std::cout << std::endl;
				return (0);
			}

			if (i % 100 == 0)
				std::cout << i << std::endl;

			vec.clear();
		}
	}

	try {
		std::vector<int> vector_nums = PmergeMe::validateAndProcessInput<std::vector<int> >(argv, argc);
		PmergeMe::displayTime_vector(vector_nums, "vector");
	}
	catch(const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}

	try {
		std::deque<int> deque_nums = PmergeMe::validateAndProcessInput<std::deque<int> >(argv, argc);
		PmergeMe::displayTime_deque(deque_nums, "deque");
	}
	catch(const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}


	return 0;
}
