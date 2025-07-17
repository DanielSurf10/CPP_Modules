#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "PmergeMe.hpp"

int main() {
	// Example usage of PmergeMe
	std::vector<int> vec;
	vec.push_back(7);
	vec.push_back(3);
	vec.push_back(5);
	vec.push_back(1);
	vec.push_back(9);
	vec.push_back(2);
	vec.push_back(6);
	vec.push_back(4);
	vec.push_back(8);
	vec.push_back(14);
	vec.push_back(13);
	vec.push_back(12);
	vec.push_back(11);
	vec.push_back(10);
	std::vector<int>::iterator begin = vec.begin();
	std::vector<int>::iterator end = vec.end();
	PmergeMe<std::vector<int> >::sort(begin, end, 1);

	bool isSorted = true;
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end() - 1; ++it) {
		if (*it > *(it + 1)) {
			isSorted = false;
			break;
		}
	}
	if (!isSorted) {
		std::cout << "ERROR: Vector is not sorted! ";
		std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;
		return (0);
	}

	for (int i = 1; i < 11000; i++) {
		static int seed = 0;
		srand(time(NULL) + seed++);
		for (int j = 0; j < i; j++) {
			vec.push_back(rand() % 10000);  // Random numbers between 0 and 99
		}
		PmergeMe<std::vector<int> >::sort(vec.begin(), vec.end(), 1);
		// std::cout << i << " Sorted vector: ";
		// std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));

		bool isSorted = true;
		for (std::vector<int>::iterator it = vec.begin(); it != vec.end() - 1; ++it) {
			if (*it > *(it + 1)) {
				isSorted = false;
				break;
			}
		}
		if (!isSorted) {
			std::cout << "ERROR: Vector is not sorted! " << i;
			std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
			std::cout << std::endl;
			return (0);
		}

		if (i % 100 == 0)
			std::cout << i << std::endl;

		vec.clear();
	}

	return 0;
}
