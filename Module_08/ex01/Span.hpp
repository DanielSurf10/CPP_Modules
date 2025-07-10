#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iostream>

class Span {
	private:
		std::vector<int>	numbers;
		unsigned int		maxSize;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span &other);
		Span& operator=(const Span &other);
		~Span();

		const std::vector<int>&	getNumbers() const;

		void	addNumber(int number);
		void	addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int		shortestSpan() const;
		int		longestSpan() const;

		void	fillRandom();
};

std::ostream &operator<<(std::ostream &os, const Span &span);

#endif
