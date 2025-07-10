#include "Span.hpp"
#include <iostream>

int main() {

	// Test cases for the Span class
	std::cout << "Testing Span class..." << std::endl;

	std::cout << std::endl;

	// Test case 1: Adding numbers and calculating spans
	std::cout << "Test case 1: Adding numbers and calculating spans" << std::endl;
	try {
		Span span(5);

		span.addNumber(1);
		span.addNumber(3);
		span.addNumber(7);
		span.addNumber(9);
		span.addNumber(2);

		std::cout << "Numbers: " << span << std::endl;

		std::cout << "Shortest Span: " << span.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << span.longestSpan() << std::endl;

	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	// Test case 2: Adding more numbers than the maximum size
	std::cout << "Test case 2: Adding more numbers than the maximum size" << std::endl;
	try {
		Span span(5);

		span.addNumber(1);
		span.addNumber(3);
		span.addNumber(7);
		span.addNumber(9);
		span.addNumber(2);

		std::cout << "Numbers: " << span << std::endl;

		std::cout << "Trying to add another number..." << std::endl;
		span.addNumber(10); // This will throw a length_error

	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	// Test case 3: Calculating spans with not enough numbers
	std::cout << "Test case 3: Calculating spans with not enough numbers" << std::endl;
	try {
		Span span(1);
		span.addNumber(5);

		std::cout << "Numbers: " << span << std::endl;

		std::cout << "Shortest Span: " << span.shortestSpan() << std::endl; // This will throw a logic_error
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	// Test case 4: addRange with valid range
	std::cout << "Test case 4: addRange with valid range" << std::endl;
	try {
		Span span(10);
		int arr[] = {5, 6, 7, 8, 10};
		std::vector<int> numbers(arr, arr + sizeof(arr) / sizeof(int));
		span.addRange(numbers.begin(), numbers.end());

		std::cout << "Numbers: " << span << std::endl;

		std::cout << "Shortest Span after addRange: " << span.shortestSpan() << std::endl;
		std::cout << "Longest Span after addRange: " << span.longestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	// Test case 5: addRange exceeding max size
	std::cout << "Test case 5: addRange exceeding max size" << std::endl;
	try {
		Span span(5);
		int arr[] = {1, 2, 3, 4, 5, 6};
		std::vector<int> numbers(arr, arr + sizeof(arr) / sizeof(int));
		span.addRange(numbers.begin(), numbers.end()); // This will throw a length_error
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	// Test case 6: fillRandom with valid range
	std::cout << "Test case 6: fillRandom with valid range" << std::endl;
	try {
		Span span(10);
		span.fillRandom();

		std::cout << "Numbers: " << span << std::endl;

		std::cout << "Shortest Span after fillRandom: " << span.shortestSpan() << std::endl;
		std::cout << "Longest Span after fillRandom: " << span.longestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	// Test case 7: fillRandom with max size of 0
	std::cout << "Test case 7: fillRandom with max size of 0" << std::endl;
	try {
		Span span(0);
		span.fillRandom(); // This will not throw an exception, but will not fill any numbers
		std::cout << "Numbers after fillRandom with max size 0: " << span << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	// Test case 8: 10,000 random numbers
	std::cout << "Test case 8: 10,000 random numbers" << std::endl;
	try {
		Span span(10000);
		span.fillRandom();
		std::cout << "Numbers after filling 10,000 random numbers: " << span << std::endl;
		std::cout << "Shortest Span after filling 10,000 random numbers: " << span.shortestSpan() << std::endl;
		std::cout << "Longest Span after filling 10,000 random numbers: " << span.longestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	return (0);
}
