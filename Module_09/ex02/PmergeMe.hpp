#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iterator>
#include <iostream>
#include <cmath>

template <typename Container>
class PmergeMe {

	private:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

	public:
		static void sort(typename Container::iterator first, typename Container::iterator last, int order);
		static bool compare(typename Container::iterator a, typename Container::iterator b);
		static typename Container::iterator findInsertionPoint(Container& main_chain, typename Container::value_type reference_value, size_t limit, int order);
};

template <typename Container>
PmergeMe<Container>::PmergeMe() {}

template <typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe& other){}

template <typename Container>
PmergeMe<Container>& PmergeMe<Container>::operator=(const PmergeMe& other) {
	(void) other;
	return (*this);
}

template <typename Container>
PmergeMe<Container>::~PmergeMe() {}

template <typename Container>
void PmergeMe<Container>::sort(typename Container::iterator first, typename Container::iterator last, int order) {

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

	int size = std::floor(std::distance(first, last) / (order));					// Calcula o tamanho do grupo de elementos
	if (size < 2)																	// Se o tamanho for menor que 2, não há nada a ordenar
		return;

	// Quando há um elemento que não consegue formar um grupo de tamanho 'order'
	// no final
	bool has_stray = (size % 2 != 0);												// Se o tamanho for ímpar, há um elemento a mais
	// bool has_odd = std::distance(first + order * size, last) != 0;

	// Agrupar os elementos em grupos de tamanho 'order'

	// typename Container::iterator end = has_stray ? last - order : last;				// Se tiver um elemento a mais, não o considera
	typename Container::iterator end;

	// if (has_stray || has_odd)
	// 	end = first + order * (size - (1 * !has_odd));
	// else
	// 	end = last;

	end = first + ((order * size) - (has_stray * order));

	for (typename Container::iterator it = first; it != end; it += (order * 2)) {	// Itera sobre o container, pulando de dois em dois grupos de tamanho 'order'
		if (PmergeMe::compare(it + (order - 1), it + ((order * 2) - 1))) {				// Compara os dois últimos elementos do grupo atual
			std::swap_ranges(it, it + order, it + order);									// Troca os dois grupos de tamanho 'order' se necessário
		}
	}

	// Ordenar recursivamente os grupos de pares até que não seja mais possível
	// dividir em grupos

	PmergeMe<Container>::sort(first, end, order * 2);

	// Separa main chain e elementos pend (pendentes)

	Container	main_chain;
	Container	pend_chain;
	main_chain.insert(main_chain.end(), first, first + order);
	main_chain.insert(main_chain.end(), first + order, first + (order * 2));

	for (typename Container::iterator it = first + (order * 2); it != end; it += (order * 2)) {
		main_chain.insert(main_chain.end(), it + order, it + (order * 2));
		pend_chain.insert(pend_chain.end(), it, it + order);
	}

	// Coloca os elementos que não formaram pares na pend chain
	if (has_stray && std::distance(end, last) >= order)
		pend_chain.insert(pend_chain.end(), end, end + order);

	// Inserção binária na main chain

	int	k = 0;
	while (true) {
		std::size_t dist = jacobsthal_diff[k];

		if (dist >= pend_chain.size() / order)
			break;

		typename Container::iterator it = (pend_chain.begin() + (dist * order)) - 1;

		while (dist > 0) {
			typename Container::iterator insertion_point = PmergeMe::findInsertionPoint(main_chain, *it, (main_chain.size() / order) - 1, order);

			main_chain.insert(insertion_point, it - order + 1, it + 1);
			pend_chain.erase(it - order + 1, it + 1);

			it -= order;
			dist--;
		}

		k++;
	}

	while (!pend_chain.empty()) {
		typename Container::iterator it = pend_chain.end() - 1;
		typename Container::iterator insertion_point = PmergeMe::findInsertionPoint(main_chain, *it, (main_chain.size() / order) - 1, order);
		main_chain.insert(insertion_point, it + 1 - order, it + 1);
		pend_chain.erase(it + 1 - order, it + 1);
	}

	// sobreescrever os elementos de first a last usando a main_chain.
	std::size_t main_chain_size = main_chain.size();
	std::copy(main_chain.begin(), main_chain.begin() + main_chain_size, first);
}

template <typename Container>
bool PmergeMe<Container>::compare(typename Container::iterator a, typename Container::iterator b) {
	if (*b < *a)
		return true;
	return false;
}

template <typename Container>
typename Container::iterator PmergeMe<Container>::findInsertionPoint(Container& main_chain, typename Container::value_type reference_value, size_t limit, int order) {

	int	left = 0;
	int	right = limit;

	while (left <= right) {
		int	mid = left + (right - left) / 2;
		typename Container::value_type	group_max = main_chain[(mid + 1) * order - 1];

		if (group_max == reference_value)
			return main_chain.begin() + (mid * order);
		else if (group_max < reference_value)
			left = mid + 1;
		else
			right = mid - 1;
	}

	return main_chain.begin() + (left * order);
}

#endif
