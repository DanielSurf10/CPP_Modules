#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <deque>
#include <sstream>
#include "PmergeMe.hpp"

// int main() {
// 	// Example usage of PmergeMe
// 	std::deque<int> vec;
// 	std::deque<int> vec2;
// 	// vec.push_back(7);
// 	// vec.push_back(3);
// 	// vec.push_back(5);
// 	// vec.push_back(1);
// 	// vec.push_back(9);
// 	// vec.push_back(2);
// 	// vec.push_back(6);
// 	// vec.push_back(4);
// 	// vec.push_back(8);
// 	// vec.push_back(14);
// 	// vec.push_back(13);
// 	// vec.push_back(12);
// 	// vec.push_back(11);
// 	// vec.push_back(10);
//
// 	// 6049 435 6372 48 4502 2624 3150 65 1124
// 	// vec.push_back(6049);
// 	// vec.push_back(435);
// 	// vec.push_back(6372);
// 	// vec.push_back(48);
// 	// vec.push_back(4502);
// 	// vec.push_back(2624);
// 	// vec.push_back(3150);
// 	// vec.push_back(65);
// 	// vec.push_back(1124);
//
// // 	int arr[] = {8008,5882,8250,1640,2994,9559,5750,9559,8419,4497,6889,6680,3980,8675,7624};
// // 	vec.insert(vec.end(), std::begin(arr), std::end(arr));
// //
// // 	std::deque<int>::iterator begin = vec.begin();
// // 	std::deque<int>::iterator end = vec.end();
// // 	PmergeMe<std::deque<int> >::sort(begin, end, 1, vec);
// //
// //
// // 	bool isSorted = true;
// // 	for (std::deque<int>::iterator it = vec.begin(); it != vec.end() - 1; ++it) {
// // 		if (*it > *(it + 1)) {
// // 			isSorted = false;
// // 			break;
// // 		}
// // 	}
// // 	if (!isSorted) {
// // 		std::cout << "\n\nERROR: Vector is not sorted! ";
// // 		std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
// // 		std::cout << std::endl;
// // 		return (0);
// // 	} else {
// // 		std::cout << "Vector is sorted successfully!" << std::endl;
// // 		return (0);
// // 	}
//
// 	for (int i = 1; i < 3000; i++) {
// 		for (int a = 0; a < 10; a++) {
// 			static int seed = 0;
// 			srand(time(NULL) + seed++);
// 			for (int j = 0; j < i; j++) {
// 				vec.push_back(rand() % 10000);  // Random numbers between 0 and 99
// 			}
// 			vec2 = vec;  // Copy the vector to vec2 for comparison
// 			// std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
// 			PmergeMe<std::deque<int> >::sort(vec.begin(), vec.end(), 1, vec);
// 			// std::cout << i << " Sorted vector: ";
//
// 			bool isSorted = true;
// 			for (std::deque<int>::iterator it = vec.begin(); it != vec.end() - 1; ++it) {
// 				if (*it > *(it + 1)) {
// 					isSorted = false;
// 					break;
// 				}
// 			}
// 			if (!isSorted) {
// 				std::cout << "ERROR: Vector is not sorted! " << i << " - ";
// 				std::copy(vec2.begin(), vec2.end(), std::ostream_iterator<int>(std::cout, " "));
// 				std::cout << std::endl;
// 				return (0);
// 			}
//
// 			vec.clear();
// 		}
// 		if (i % 100 == 0)
// 			std::cout << i << std::endl;
// 	}
//
// // 	for (int i = 1; i < 100; i++) {
// // 		static int seed = 0;
// // 		srand(time(NULL) + seed++);
// // 		for (int j = 0; j < 7; j++) {
// // 			vec.push_back(rand() % 10000);  // Random numbers between 0 and 99
// // 		}
// // 		vec2 = vec;  // Copy the vector to vec2 for comparison
// // 		std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
// // 		PmergeMe<std::vector<int> >::sort(vec.begin(), vec.end(), 1);
// // 		// std::cout << i << " Sorted vector: ";
// //
// // 		bool isSorted = true;
// // 		for (std::vector<int>::iterator it = vec.begin(); it != vec.end() - 1; ++it) {
// // 			if (*it > *(it + 1)) {
// // 				isSorted = false;
// // 				break;
// // 			}
// // 		}
// // 		if (!isSorted) {
// // 			std::cout << "ERROR: Vector is not sorted! " << i;
// // 			// std::copy(vec2.begin(), vec2.end(), std::ostream_iterator<int>(std::cout, " "));
// // 			std::cout << std::endl;
// // 			return (0);
// // 		}
// //
// // 		if (i % 100 == 0)
// // 			std::cout << i << std::endl;
// //
// // 		vec.clear();
// // 	}
//
// 	return (0);
// }


int main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " <numbers...>" << std::endl;
		return 1;
	}

	std::vector<int> vec;
	for (int i = 1; i < argc; ++i) {

		std::string input = argv[i];

		// validar se só tem números inteiros positivos
		if (input.empty()) {
			std::cerr << "Empty input is not allowed." << std::endl;
			return (1);
		}

		if (input.find_first_not_of("0123456789") != std::string::npos) {
			std::cerr << "Invalid input: " << input << std::endl;
			return (1);
		}

		int value;
		std::string valuestr = std::string(argv[i]);
		std::istringstream iss(valuestr);
		iss >> value;

		if (iss.fail() || !iss.eof()) {
			std::cerr << "Invalid input: " << valuestr << std::endl;
			return 1;
		}

		if (value < 0) {
			std::cerr << "Negative numbers are not allowed: " << value << std::endl;
			return 1;
		}

		vec.push_back(value);
	}

	// Copiar o vetor para uma deque
	std::deque<int> vec_deque(vec.begin(), vec.end());

	std::cout << "Before sorting: ";
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	clock_t startVec = clock();
	PmergeMe<std::vector<int> >::sort(vec.begin(), vec.end(), 1, vec);
	clock_t endVec = clock();

	std::cout << "After sorting: ";
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	// Verificar se o vetor está ordenado
	bool isSorted = true;
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end() - 1; ++it) {
		if (*it > *(it + 1)) {
			isSorted = false;
			break;
		}
	}
	if (!isSorted) {
		std::cerr << "Error: Vector is not sorted!" << std::endl;
		std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cerr, " "));
		std::cerr << std::endl;
		return (1);
	}

	clock_t startDeq = clock();
	PmergeMe<std::deque<int> >::sort(vec_deque.begin(), vec_deque.end(), 1, vec_deque);
	clock_t endDeq = clock();
	isSorted = true;
	for (std::deque<int>::iterator it = vec_deque.begin(); it != vec_deque.end() - 1; ++it) {
		if (*it > *(it + 1)) {
			isSorted = false;
			break;
		}
	}
	if (!isSorted) {
		std::cerr << "Error: Deque is not sorted!" << std::endl;
		std::copy(vec_deque.begin(), vec_deque.end(), std::ostream_iterator<int>(std::cerr, " "));
		std::cerr << std::endl;
		return (1);
	}

	double vec_time = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000.0;
	double deq_time = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000.0;
	std::cout << "Time taken for vector sort: " << vec_time << " microseconds" << std::endl;
	std::cout << "Time taken for deque sort: " << deq_time << " microseconds" << std::endl;
	std::cout << "Size: " << vec.size() << std::endl;

	return (0);
}
