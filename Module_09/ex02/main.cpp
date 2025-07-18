#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "PmergeMe.hpp"

inline int get_jacobsthal_index(int n);

int main() {
	// Example usage of PmergeMe
	std::vector<int> vec;
	std::vector<int> vec2;
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

	int arr[] = {719163,7882,7382,4243,4435,3160,902,3418,363,1775,815,7405,6041,2939,7176,3787,1556,7698,7395,4557,8652,6343,5354,889,7694,8270,2569,6806,9347,9093,5559,4863,6975,2941,9106,1410,2453,9,4829,9168,8136,5644,6573,529,4935,3749,4316,2843,7800,8063,3752,2804,759,9106,3693,8453,3729,6262,5260,3076,5355,819,7939,2330,112,3398,93,8918,9759,4922,4438};
	vec.insert(vec.end(), std::begin(arr), std::end(arr));

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
		std::cout << "\n\nERROR: Vector is not sorted! ";
		std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;
		return (0);
	} else {
		std::cout << "Vector is sorted successfully!" << std::endl;
		return (0);
	}

// 	for (int i = 1; i < 11000; i++) {
// 		static int seed = 0;
// 		srand(time(NULL) + seed++);
// 		for (int j = 0; j < i; j++) {
// 			vec.push_back(rand() % 10000);  // Random numbers between 0 and 99
// 		}
// 		vec2 = vec;  // Copy the vector to vec2 for comparison
// 		// std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
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
// 			std::copy(vec2.begin(), vec2.end(), std::ostream_iterator<int>(std::cout, " "));
// 			std::cout << std::endl;
// 			return (0);
// 		}
//
// 		if (i % 100 == 0)
// 			std::cout << i << std::endl;
//
// 		vec.clear();
// 	}

	return 0;
}
