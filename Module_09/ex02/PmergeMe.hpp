#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iterator>
#include <iostream>
#include <cmath>
#include <vector>
#include <deque>
#include <set>
#include <ctime>
#include <stdexcept>

// template <typename Container>
class PmergeMe {

	private:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

	public:

		template <typename Container>
		static Container validateAndProcessInput(char **input, int &elements);

		template <typename Container>
		static void printSequence(const Container &seq);

		static void sort_vector(std::vector<int>::iterator first, std::vector<int>::iterator last, int order);
		static bool compare_vector(std::vector<int>::iterator a, std::vector<int>::iterator b);
		static std::vector<int>::iterator findInsertionPoint_vector(std::vector<int>& main_chain, int reference_value, size_t limit, int order);
		static void displayTime_vector(std::vector<int> seq, const std::string &containerName);

		static void sort_deque(std::deque<int>::iterator first, std::deque<int>::iterator last, int order);
		static bool compare_deque(std::deque<int>::iterator a, std::deque<int>::iterator b);
		static std::deque<int>::iterator findInsertionPoint_deque(std::deque<int>& main_chain, int reference_value, size_t limit, int order);
		static void displayTime_deque(std::deque<int> seq, const std::string &containerName);

};

template <typename Container>
Container PmergeMe::validateAndProcessInput(char **input, int &elements) {
	Container numbers;
	std::set<typename Container::value_type> seenNumbers;

	for (int i = 1; i < elements; ++i) {
		int num = atoi(input[i]);
		if (num <= 0) {
			throw std::invalid_argument(
				"Number must be positive or not double signal.");
		}
		if (!seenNumbers.insert(num).second) {
			std::cout << "Duplicate number detected: " << num << std::endl;
			throw std::invalid_argument("Duplicate number detected.");
		}
		numbers.push_back(num);
	}
	return numbers;
}

template <typename Container>
void PmergeMe::printSequence(const Container &seq) {
	typename Container::const_iterator it;
	for (it = seq.begin(); it != seq.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

#endif
