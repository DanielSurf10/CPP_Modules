#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iterator>
#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

template <typename Container>
class PmergeMe {

	private:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

	public:
		static void sort(typename Container::iterator first, typename Container::iterator last, int order, Container& vec);
		static bool compare(typename Container::iterator a, typename Container::iterator b);
		static typename Container::iterator	find_position(typename Container::iterator reference_value, typename Container::iterator first, typename Container::iterator last, int order);
		static typename Container::iterator get_element_at(typename Container::iterator begin, int index);
};

template <typename Container>
PmergeMe<Container>::PmergeMe() {}

template <typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe& other) {
	(void) other;
}

template <typename Container>
PmergeMe<Container>& PmergeMe<Container>::operator=(const PmergeMe& other) {
	(void) other;
	return (*this);
}

template <typename Container>
PmergeMe<Container>::~PmergeMe() {}

template<typename Container>
typename Container::iterator PmergeMe<Container>::get_element_at(typename Container::iterator begin, int index) {
	typename Container::iterator it = begin;
	std::advance(it, index);
	return it;
}

template <typename Container>
void PmergeMe<Container>::sort(typename Container::iterator first, typename Container::iterator last, int order, Container& vec) {

	// Cache all the differences between a Jacobsthal number and its
	// predecessor that fit in 64 bits, starting with the difference
	// between the Jacobsthal numbers 4 and 3 (the previous ones are
	// unneeded)
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
//
// 	static const unsigned long long jacobsthal[] = {
// 		0ULL, 1ULL, 1ULL, 3ULL, 5ULL, 11ULL, 21ULL, 43ULL, 85ULL, 171ULL, 341ULL,
// 		683ULL, 1365ULL, 2731ULL, 5461ULL, 10923ULL, 21845ULL, 43691ULL, 87381ULL,
// 		174763ULL, 349525ULL, 699051ULL, 1398101ULL, 2796203ULL, 5592405ULL, 11184811ULL,
// 		22369621ULL, 44739243ULL, 89478485ULL
// 	};

	int size = std::floor(std::distance(first, last) / (order));
	if (size < 2)
		return;

	// Quando há um elemento que não consegue formar um grupo de tamanho 'order'
	// no final
	bool has_stray = (size % 2 != 0);

	// Agrupar os elementos em grupos de tamanho 'order'

	// typename Container::iterator end = has_stray ? last - order : last;
	// typename Container::iterator end = first + ((order * size) - (has_stray * order));
	typename Container::iterator end = PmergeMe<Container>::get_element_at(first, order * size - (has_stray ? order : 0));

	for (typename Container::iterator it = first; it != end; std::advance(it, order * 2)) {
		if (PmergeMe<Container>::compare(PmergeMe<Container>::get_element_at(it, order - 1), PmergeMe<Container>::get_element_at(it, (order * 2) - 1))) {
			std::swap_ranges(it, PmergeMe<Container>::get_element_at(it, order), PmergeMe<Container>::get_element_at(it, order));
		}
	}

	// Ordenar recursivamente os grupos de pares até que não seja mais possível
	// dividir em grupos

	PmergeMe<Container>::sort(first, end, order * 2, vec);

	Container main_chain;
	std::vector<std::pair<Container, size_t> > pend_chain;

	main_chain.insert(main_chain.end(), first, PmergeMe::get_element_at(first, order));
	main_chain.insert(main_chain.end(), PmergeMe::get_element_at(first, order), PmergeMe::get_element_at(first, order * 2));

	for (typename Container::iterator it = PmergeMe::get_element_at(first, order * 2); it != end; std::advance(it, order * 2)) {
		main_chain.insert(main_chain.end(), PmergeMe::get_element_at(it, order), PmergeMe::get_element_at(it, order * 2));

		std::pair<Container, size_t> pend_pair = std::make_pair(Container(it, PmergeMe::get_element_at(it, order)), (main_chain.size() / order) - 1);
		pend_chain.push_back(pend_pair);
	}

	if (has_stray && std::distance(end, last) >= order) {
		std::pair<Container, size_t> pend_pair = std::make_pair(Container(end, PmergeMe::get_element_at(end, order)), (main_chain.size() / order) - 1);
		pend_chain.push_back(pend_pair);
	}

	unsigned int jacobsthal_index = 0;
	while (true) {
		unsigned long long jacobsthal_value = jacobsthal_diff[jacobsthal_index];
		if (jacobsthal_value > static_cast<unsigned int>(std::distance(pend_chain.begin(), pend_chain.end())))
			break;

		while (jacobsthal_value > 0) {
			typename std::vector<std::pair<Container, size_t> >::iterator it = pend_chain.begin();
			std::advance(it, jacobsthal_value - 1);
			typename Container::iterator	insertion_point = PmergeMe::find_position(it->first.begin(), main_chain.begin(), PmergeMe::get_element_at(main_chain.end(), -order), order);
			main_chain.insert(insertion_point, it->first.begin(), it->first.end());
			it = pend_chain.erase(it);
			jacobsthal_value--;
		}

		jacobsthal_index++;
	}

	while (!pend_chain.empty()) {
		typename std::vector<std::pair<Container, size_t> >::iterator	last_item_in_pend = --(pend_chain.end());
		// typename Container::iterator	insertion_point = PmergeMe::find_position(last_item_in_pend->first.begin(), main_chain.begin(), PmergeMe::get_element_at(main_chain.begin(), last_item_in_pend->second * order), order);

		typename Container::iterator	insertion_point = PmergeMe::find_position(last_item_in_pend->first.begin(), main_chain.begin(), PmergeMe::get_element_at(main_chain.end(), -order), order);

		main_chain.insert(insertion_point, last_item_in_pend->first.begin(), last_item_in_pend->first.end());

		pend_chain.pop_back();
	}

	std::copy(main_chain.begin(), PmergeMe::get_element_at(main_chain.begin(), main_chain.size()), first);
}

template <typename Container>
typename Container::iterator	PmergeMe<Container>::find_position(typename Container::iterator reference_value, typename Container::iterator first, typename Container::iterator last, int order) {
// 	typename Container::iterator	mid;
// 	typename Container::value_type	mid_value;
// 	unsigned int distance;
//
// 	reference_value = PmergeMe::get_element_at(reference_value, order - 1);
//
// 	size_t dis;
// 	while ((dis = std::distance(last, first)) != 0 && *first < *last) {
// 		distance = std::distance(first, last) / (2 * order);
// 		mid = PmergeMe::get_element_at(first, distance * order);
// 		mid_value = *(PmergeMe::get_element_at(mid, order - 1));
//
// 		if (*mid == *reference_value)
// 			return (mid);
// 		else if (mid_value > *reference_value)
// 			last = PmergeMe::get_element_at(mid, -order);
// 		else
// 			first = PmergeMe::get_element_at(mid, order);
// 	}
//
// 	if (dis == 0) {
// 		distance = std::distance(first, last) / (2 * order);
// 		mid = PmergeMe::get_element_at(first, distance * order);
// 		mid_value = *(PmergeMe::get_element_at(mid, order - 1));
//
// 		if (*mid == *reference_value)
// 			return (mid);
// 		else if (mid_value > *reference_value)
// 			last = PmergeMe::get_element_at(mid, -order);
// 		else
// 			first = PmergeMe::get_element_at(mid, order);
// 	}
// 	return (first);

	int	idx_first = 0;
	int	idx_last = std::distance(first, last) / order;
	int	idx_mid;

	typename Container::value_type mid_value;
	reference_value = PmergeMe::get_element_at(reference_value, order - 1);

	while (idx_first <= idx_last) {
		idx_mid = (idx_first + idx_last) / 2;
		mid_value = *(PmergeMe::get_element_at(first, idx_mid * order + order - 1));

		if (mid_value == *reference_value)
			return (PmergeMe::get_element_at(first, idx_mid * order + order));
		else if (mid_value > *reference_value)
			idx_last = idx_mid - 1;
		else
			idx_first = idx_mid + 1;
	}

	return (PmergeMe::get_element_at(first, idx_first * order));
}

template <typename Container>
bool PmergeMe<Container>::compare(typename Container::iterator a, typename Container::iterator b) {
	if (*b < *a)
		return true;
	return false;
}


#endif
