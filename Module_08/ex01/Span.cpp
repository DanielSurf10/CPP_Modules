#include "Span.hpp"

Span::Span() : maxSize(0) {}

Span::Span(unsigned int n) : maxSize(n) {}

Span::Span(const Span &other) :
	numbers(other.numbers), maxSize(other.maxSize) {}

Span& Span::operator=(const Span &other) {
	if (this != &other) {
		this->numbers = other.numbers;
		this->maxSize = other.maxSize;
	}
	return (*this);
}

Span::~Span() {}

const std::vector<int>& Span::getNumbers() const {
	return this->numbers;
}

void Span::addNumber(int number) {
	if (this->numbers.size() >= maxSize)
		throw std::length_error("Span is full");
	this->numbers.push_back(number);
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (std::distance(begin, end) + this->numbers.size() > maxSize)
		throw std::length_error("Span is full");
	this->numbers.insert(this->numbers.end(), begin, end);
}

int Span::shortestSpan() const {
	if (this->numbers.size() < 2)
		throw std::logic_error("Not enough numbers to find a span");

	std::vector<int> sortedNumbers = this->numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());

	int minSpan = sortedNumbers[1] - sortedNumbers[0];
	for (size_t i = 1; i < sortedNumbers.size(); i++) {
		int span = sortedNumbers[i] - sortedNumbers[i - 1];

		if (span < minSpan)
			minSpan = span;
	}
	return (minSpan);
}

int Span::longestSpan() const {
	if (this->numbers.size() < 2)
		throw std::logic_error("Not enough numbers to find a span");

	int min = *std::min_element(this->numbers.begin(), this->numbers.end());
	int max = *std::max_element(this->numbers.begin(), this->numbers.end());

	return (max - min);
}

void Span::fillRandom() {
	this->numbers.clear();

	srand(time(NULL));

	for (unsigned int i = 0; i < this->maxSize; i++) {
		int randomNumber = rand() % 100;
		this->addNumber(randomNumber);
	}
}

std::ostream &operator<<(std::ostream &os, const Span &span) {

	unsigned int size = span.getNumbers().size();
	if (size > 20)
		size = 20;

	os << "[";
	for (size_t i = 0; i < size; i++) {
		os << span.getNumbers()[i];
		if (i < span.getNumbers().size() - 1)
			os << ", ";
	}

	if (span.getNumbers().size() > 20)
		os << "... ";
	os << "]";
	return (os);
}
