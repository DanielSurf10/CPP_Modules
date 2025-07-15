#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
	(void) other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	(void) other;
	return (*this);
}

PmergeMe::~PmergeMe() {}

void PmergeMe::displayTime_vector(std::vector<int> seq, const std::string &containerName) {
	std::cout << "Processing sequence with std::" << containerName << std::endl;
	std::cout << "Sequence: ";
	PmergeMe::printSequence(seq);
	clock_t start = clock();
	PmergeMe::sort_vector(seq.begin(), seq.end(), 1);
	clock_t end = clock();
	std::cout << "Sorted sequence: ";
	PmergeMe::printSequence(seq);
	double timeInSeconds = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << seq.size()
			<< " elements with" << " std::" << containerName
			<< ": " << (timeInSeconds * 1000.0) << " us" << std::endl;
}

void PmergeMe::displayTime_deque(std::deque<int> seq, const std::string &containerName) {
	std::cout << "Processing sequence with std::" << containerName << std::endl;
	std::cout << "Sequence: ";
	PmergeMe::printSequence(seq);
	clock_t start = clock();
	PmergeMe::sort_deque(seq.begin(), seq.end(), 1);
	clock_t end = clock();
	std::cout << "Sorted sequence: ";
	PmergeMe::printSequence(seq);
	double timeInSeconds = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << seq.size()
			<< " elements with" << " std::" << containerName
			<< ": " << (timeInSeconds * 1000.0) << " us" << std::endl;
}


void PmergeMe::sort_deque(std::deque<int>::iterator first, std::deque<int>::iterator last, int order) {
	static const unsigned long long jacobsthal_diff[] = {
		2ULL, 2ULL, 6ULL, 10ULL, 22ULL, 42ULL, 86ULL, 170ULL, 342ULL, 682ULL, 1366ULL,
		2730ULL, 5462ULL, 10922ULL, 21846ULL, 43690ULL, 87382ULL, 174762ULL, 349526ULL, 699050ULL,
		1398102ULL, 2796202ULL, 5592406ULL, 11184810ULL, 22369622ULL, 44739242ULL, 89478486ULL,
		178956970ULL, 357913942ULL, 715827882ULL, 1431655766ULL, 2863311530ULL, 5726623062ULL,
		11453246122ULL, 22906492246ULL, 45812984490ULL, 91625968982ULL, 183251937962ULL,
		366503875926ULL, 733007751850ULL, 1466015503702ULL, 2932031007402ULL, 5864062014806ULL,
		11728124029610ULL, 23456248059222ULL, 46912496118442ULL, 93824992236886ULL, 187649984473770ULL,
		375299968947542ULL, 750599937895082ULL, 1501199875790165ULL, 3002399751580331ULL,
		6004799503160661ULL, 12009599006321322ULL, 24019198012642644ULL, 48038396025285288ULL,
		96076792050570576ULL, 192153584101141152ULL, 384307168202282304ULL, 768614336404564608ULL,
		1537228672809129216ULL, 3074457345618258432ULL, 6148914691236516864ULL
	};

	int size = std::floor(std::distance(first, last) / (order));
	if (size < 2)
		return;

	bool has_stray = (size % 2 != 0);

	std::deque<int>::iterator end;

	end = first + ((order * size) - (has_stray * order));

	for (std::deque<int>::iterator it = first; it != end; it += (order * 2)) {
		if (PmergeMe::compare_deque(it + (order - 1), it + ((order * 2) - 1))) {
			std::swap_ranges(it, it + order, it + order);
		}
	}

	PmergeMe::sort_deque(first, end, order * 2);

	std::deque<int>	main_chain;
	std::deque<int>	pend_chain;
	main_chain.insert(main_chain.end(), first, first + order);
	main_chain.insert(main_chain.end(), first + order, first + (order * 2));

	for (std::deque<int>::iterator it = first + (order * 2); it != end; it += (order * 2)) {
		main_chain.insert(main_chain.end(), it + order, it + (order * 2));
		pend_chain.insert(pend_chain.end(), it, it + order);
	}

	if (has_stray && std::distance(end, last) >= order)
		pend_chain.insert(pend_chain.end(), end, end + order);

	int	k = 0;
	while (true) {
		std::size_t dist = jacobsthal_diff[k];

		if (dist >= pend_chain.size() / order)
			break;

		std::deque<int>::iterator it = (pend_chain.begin() + (dist * order)) - 1;

		while (dist > 0) {
			std::deque<int>::iterator insertion_point = PmergeMe::findInsertionPoint_deque(main_chain, *it, (main_chain.size() / order) - 1, order);

			std::deque<int>::iterator temp_it = it - order + 1;
			std::size_t insert_distance = std::distance(temp_it, it + 1);

			for (std::deque<int>::iterator elem_it = temp_it; elem_it != it + 1; elem_it++) {
				insertion_point = main_chain.insert(insertion_point, *elem_it);
				insertion_point++;
			}

			std::deque<int>::iterator erase_start = it - order + 1;
			std::deque<int>::iterator erase_end = it + 1;
			std::deque<int>::iterator shift_from = erase_end;
			std::deque<int>::iterator shift_to = erase_start;

			for (std::deque<int>::iterator src = shift_from; src != pend_chain.end(); ++src, ++shift_to) {
				*shift_to = *src;
			}

			std::size_t elements_to_remove = std::distance(erase_start, erase_end);
			pend_chain.resize(pend_chain.size() - elements_to_remove);

			it -= order;
			dist--;
		}

		k++;
	}

	while (!pend_chain.empty()) {
		std::deque<int>::iterator it = pend_chain.end() - 1;
		std::deque<int>::iterator insertion_point = PmergeMe::findInsertionPoint_deque(main_chain, *it, (main_chain.size() / order) - 1, order);
		main_chain.insert(insertion_point, it + 1 - order, it + 1);
		pend_chain.erase(it + 1 - order, it + 1);
	}


	std::size_t main_chain_size = main_chain.size();
	std::copy(main_chain.begin(), main_chain.begin() + main_chain_size, first);
}

bool PmergeMe::compare_deque(std::deque<int>::iterator a, std::deque<int>::iterator b) {
	if (*b < *a)
		return true;
	return false;
}

std::deque<int>::iterator PmergeMe::findInsertionPoint_deque(std::deque<int>& main_chain, int reference_value, size_t limit, int order) {

	int	left = 0;
	int	right = limit;

	while (left <= right) {
		int	mid = left + (right - left) / 2;
		int	group_max = main_chain[(mid + 1) * order - 1];

		if (group_max == reference_value)
			return main_chain.begin() + (mid * order);
		else if (group_max < reference_value)
			left = mid + 1;
		else
			right = mid - 1;
	}

	return main_chain.begin() + (left * order);
}

void PmergeMe::sort_vector(std::vector<int>::iterator first, std::vector<int>::iterator last, int order) {
	static const unsigned long long jacobsthal_diff[] = {
		2ULL, 2ULL, 6ULL, 10ULL, 22ULL, 42ULL, 86ULL, 170ULL, 342ULL, 682ULL, 1366ULL,
		2730ULL, 5462ULL, 10922ULL, 21846ULL, 43690ULL, 87382ULL, 174762ULL, 349526ULL, 699050ULL,
		1398102ULL, 2796202ULL, 5592406ULL, 11184810ULL, 22369622ULL, 44739242ULL, 89478486ULL,
		178956970ULL, 357913942ULL, 715827882ULL, 1431655766ULL, 2863311530ULL, 5726623062ULL,
		11453246122ULL, 22906492246ULL, 45812984490ULL, 91625968982ULL, 183251937962ULL,
		366503875926ULL, 733007751850ULL, 1466015503702ULL, 2932031007402ULL, 5864062014806ULL,
		11728124029610ULL, 23456248059222ULL, 46912496118442ULL, 93824992236886ULL, 187649984473770ULL,
		375299968947542ULL, 750599937895082ULL, 1501199875790165ULL, 3002399751580331ULL,
		6004799503160661ULL, 12009599006321322ULL, 24019198012642644ULL, 48038396025285288ULL,
		96076792050570576ULL, 192153584101141152ULL, 384307168202282304ULL, 768614336404564608ULL,
		1537228672809129216ULL, 3074457345618258432ULL, 6148914691236516864ULL
	};

	int size = std::floor(std::distance(first, last) / (order));
	if (size < 2)
		return;

	bool has_stray = (size % 2 != 0);

	std::vector<int>::iterator end;

	end = first + ((order * size) - (has_stray * order));

	for (std::vector<int>::iterator it = first; it != end; it += (order * 2)) {
		if (PmergeMe::compare_vector(it + (order - 1), it + ((order * 2) - 1))) {
			std::swap_ranges(it, it + order, it + order);
		}
	}

	PmergeMe::sort_vector(first, end, order * 2);

	std::vector<int>	main_chain;
	std::vector<int>	pend_chain;
	main_chain.insert(main_chain.end(), first, first + order);
	main_chain.insert(main_chain.end(), first + order, first + (order * 2));

	for (std::vector<int>::iterator it = first + (order * 2); it != end; it += (order * 2)) {
		main_chain.insert(main_chain.end(), it + order, it + (order * 2));
		pend_chain.insert(pend_chain.end(), it, it + order);
	}

	if (has_stray && std::distance(end, last) >= order)
		pend_chain.insert(pend_chain.end(), end, end + order);

	int	k = 0;
	while (true) {
		std::size_t dist = jacobsthal_diff[k];

		if (dist >= pend_chain.size() / order)
			break;

		std::vector<int>::iterator it = (pend_chain.begin() + (dist * order)) - 1;

		while (dist > 0) {
			std::vector<int>::iterator insertion_point = PmergeMe::findInsertionPoint_vector(main_chain, *it, (main_chain.size() / order) - 1, order);

			main_chain.insert(insertion_point, it - order + 1, it + 1);
			pend_chain.erase(it - order + 1, it + 1);

			it -= order;
			dist--;
		}

		k++;
	}

	while (!pend_chain.empty()) {
		std::vector<int>::iterator it = pend_chain.end() - 1;
		std::vector<int>::iterator insertion_point = PmergeMe::findInsertionPoint_vector(main_chain, *it, (main_chain.size() / order) - 1, order);
		main_chain.insert(insertion_point, it + 1 - order, it + 1);
		pend_chain.erase(it + 1 - order, it + 1);
	}


	std::size_t main_chain_size = main_chain.size();
	std::copy(main_chain.begin(), main_chain.begin() + main_chain_size, first);
}

bool PmergeMe::compare_vector(std::vector<int>::iterator a, std::vector<int>::iterator b) {
	if (*b < *a)
		return true;
	return false;
}

std::vector<int>::iterator PmergeMe::findInsertionPoint_vector(std::vector<int>& main_chain, int reference_value, size_t limit, int order) {

	int	left = 0;
	int	right = limit;

	while (left <= right) {
		int	mid = left + (right - left) / 2;
		int	group_max = main_chain[(mid + 1) * order - 1];

		if (group_max == reference_value)
			return main_chain.begin() + (mid * order);
		else if (group_max < reference_value)
			left = mid + 1;
		else
			right = mid - 1;
	}

	return main_chain.begin() + (left * order);
}
