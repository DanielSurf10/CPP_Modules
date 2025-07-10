/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:37:07 by cnatanae          #+#    #+#             */
/*   Updated: 2025/03/02 16:51:54 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

template <typename T>
std::ostream &operator<<(std::ostream &os, MutantStack<T> &mstack) {

	unsigned int size = mstack.size();
	if (size > 30)
		size = 30;

	os << "[";
	typename MutantStack<T>::iterator it = mstack.begin();
	typename MutantStack<T>::iterator ite = mstack.end();

	for (size_t i = 0; i < size && it != ite; i++, it++) {
		os << *it;
		if (i < size - 1)
			os << ", ";
	}
	if (mstack.size() > 30)
		os << ", ... ";
	os << "]";

	return (os);
}

void myTest() {
	std::cout << std::endl;
	std::cout << "========== My test with MutantStack ==========" << std::endl;
	MutantStack<int> mstack;

	// Test pushing elements
	mstack.push(5);
	mstack.push(17);
	mstack.push(10);

	// Test popping elements
	std::cout << "Stack after pushing 5, 17, 10:" << std::endl;
	std::cout << mstack << std::endl;

	// Test pushing and popping mixed with iteration
	for (int i = 0; i < 5; i++) {
		mstack.push(i * 2);
	}
	std::cout << "Stack after pushing 0, 2, 4, 6, 8:" << std::endl;
	std::cout << mstack << std::endl;

	std::cout << "Adding itens to original stack" << std::endl;
	for (int i = 0; i < 15; i++) {
		mstack.push(i * 3);
	}
	std::cout << std::endl;
	// Test copying the stack
	std::cout << "Copying the original stack to another" << std::endl;
	MutantStack<int> copiedStack = mstack;
	std::cout << std::endl;
	std::cout << "Values of original stack" << std::endl;
	std::cout << mstack << std::endl;
	std::cout << "Copied stack:" << std::endl;
	std::cout << copiedStack << std::endl;
}

void subjectTest() {
	std::cout << std::endl;
	std::cout << " === SUBJECT TESTS === " << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

template <typename T>
std::ostream &operator<<(std::ostream &os, std::list<T> &mylist) {

	unsigned int size = mylist.size();
	if (size > 30)
		size = 30;

	os << "[";
	typename std::list<T>::iterator it = mylist.begin();
	typename std::list<T>::iterator ite = mylist.end();

	for (size_t i = 0; i < size && it != ite; i++, it++) {
		os << *it;
		if (i < size - 1)
			os << ", ";
	}
	if (mylist.size() > 30)
		os << ", ... ";
	os << "]";

	return (os);
}

void myTestList(void) {
	std::cout << std::endl;
	std::cout << "========== My test with List ==========" << std::endl;
	std::list<int> mylist; // Use std::list instead of MutantStack

	// Test pushing elements
	mylist.push_back(5);
	mylist.push_back(17);
	mylist.push_back(10);

	// Test popping elements
	std::cout << "\033[32mStack after pushing 5, 17, 10:\033[0m" << std::endl;
	std::cout << mylist << std::endl;

	// Test pushing and popping mixed with iteration
	for (int i = 0; i < 5; ++i) {
		mylist.push_back(i * 2);
	}
	std::cout << "\033[32mStack after pushing 0, 2, 4, 6, 8:\033[0m" << std::endl;
	std::cout << mylist << std::endl;

	std::cout << "\033[31mAdding items to the original stack\033[0m" << std::endl;
	for (int i = 0; i < 15; ++i) {
		mylist.push_back(i * 3);
	}
	std::cout << std::endl;

	// Test copying the stack
	std::cout << "\033[35mCopying the original stack to another\033[0m"
						<< std::endl;
	std::list<int> copiedList = mylist;
	std::cout << std::endl;

	std::cout << "\033[32mValues of the original stack\033[0m" << std::endl;
	std::cout << mylist << std::endl;
	std::cout << "\033[33mCopied stack:\033[0m" << std::endl;
	std::cout << copiedList << std::endl;
}

void listTest(void) {
	std::cout << std::endl;
	std::cout << " === LIST TESTS === " << std::endl;
	std::list<int> mylist; // Use std::list instead of MutantStack

	// Test pushing elements
	mylist.push_back(5);
	mylist.push_back(17);

	// Test top, pop, and size
	std::cout << mylist.back() << std::endl;
	mylist.pop_back();
	std::cout << mylist.size() << std::endl;

	// Test pushing more elements
	mylist.push_back(3);
	mylist.push_back(5);
	mylist.push_back(737);
	mylist.push_back(0);

	// Iterate over the list
	std::list<int>::iterator it = mylist.begin();
	std::list<int>::iterator ite = mylist.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
}

int main() {
	myTest();
	myTestList();
	subjectTest();
	listTest();

	return (0);
}
