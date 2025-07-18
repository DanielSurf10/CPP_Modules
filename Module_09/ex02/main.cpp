#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <deque>
#include "PmergeMe.hpp"

inline int get_jacobsthal_index(int n);

int main() {
	// Example usage of PmergeMe
	std::deque<int> vec;
	std::deque<int> vec2;
	// vec.push_back(7);
	// vec.push_back(3);
	// vec.push_back(5);
	// vec.push_back(1);
	// vec.push_back(9);
	// vec.push_back(2);
	// vec.push_back(6);
	// vec.push_back(4);
	// vec.push_back(8);
	// vec.push_back(14);
	// vec.push_back(13);
	// vec.push_back(12);
	// vec.push_back(11);
	// vec.push_back(10);

	// 6049 435 6372 48 4502 2624 3150 65 1124
	// vec.push_back(6049);
	// vec.push_back(435);
	// vec.push_back(6372);
	// vec.push_back(48);
	// vec.push_back(4502);
	// vec.push_back(2624);
	// vec.push_back(3150);
	// vec.push_back(65);
	// vec.push_back(1124);

// 	int arr[] = {8008,5882,8250,1640,2994,9559,5750,9559,8419,4497,6889,6680,3980,8675,7624};
// 	vec.insert(vec.end(), std::begin(arr), std::end(arr));
//
// 	std::deque<int>::iterator begin = vec.begin();
// 	std::deque<int>::iterator end = vec.end();
// 	PmergeMe<std::deque<int> >::sort(begin, end, 1, vec);
//
//
// 	bool isSorted = true;
// 	for (std::deque<int>::iterator it = vec.begin(); it != vec.end() - 1; ++it) {
// 		if (*it > *(it + 1)) {
// 			isSorted = false;
// 			break;
// 		}
// 	}
// 	if (!isSorted) {
// 		std::cout << "\n\nERROR: Vector is not sorted! ";
// 		std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
// 		std::cout << std::endl;
// 		return (0);
// 	} else {
// 		std::cout << "Vector is sorted successfully!" << std::endl;
// 		return (0);
// 	}

	for (int i = 1; i < 11000; i++) {
		for (int a = 0; a < 1; a++) {
			static int seed = 0;
			srand(time(NULL) + seed++);
			for (int j = 0; j < i; j++) {
				vec.push_back(rand() % 10000);  // Random numbers between 0 and 99
			}
			vec2 = vec;  // Copy the vector to vec2 for comparison
			// std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
			PmergeMe<std::deque<int> >::sort(vec.begin(), vec.end(), 1, vec);
			// std::cout << i << " Sorted vector: ";

			bool isSorted = true;
			for (std::deque<int>::iterator it = vec.begin(); it != vec.end() - 1; ++it) {
				if (*it > *(it + 1)) {
					isSorted = false;
					break;
				}
			}
			if (!isSorted) {
				std::cout << "ERROR: Vector is not sorted! " << i << " - ";
				std::copy(vec2.begin(), vec2.end(), std::ostream_iterator<int>(std::cout, " "));
				std::cout << std::endl;
				return (0);
			}

			vec.clear();
		}
		if (i % 100 == 0)
			std::cout << i << std::endl;
	}

// 	for (int i = 1; i < 100; i++) {
// 		static int seed = 0;
// 		srand(time(NULL) + seed++);
// 		for (int j = 0; j < 7; j++) {
// 			vec.push_back(rand() % 10000);  // Random numbers between 0 and 99
// 		}
// 		vec2 = vec;  // Copy the vector to vec2 for comparison
// 		std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
// 		PmergeMe<std::vector<int> >::sort(vec.begin(), vec.end(), 1);
// 		// std::cout << i << " Sorted vector: ";
//
// 		bool isSorted = true;
// 		for (std::vector<int>::iterator it = vec.begin(); it != vec.end() - 1; ++it) {
// 			if (*it > *(it + 1)) {
// 				isSorted = false;
// 				break;
// 			}
// 		}
// 		if (!isSorted) {
// 			std::cout << "ERROR: Vector is not sorted! " << i;
// 			// std::copy(vec2.begin(), vec2.end(), std::ostream_iterator<int>(std::cout, " "));
// 			std::cout << std::endl;
// 			return (0);
// 		}
//
// 		if (i % 100 == 0)
// 			std::cout << i << std::endl;
//
// 		vec.clear();
// 	}

	return (0);
}
