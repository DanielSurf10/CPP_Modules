#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		MutantStack();
		MutantStack(const MutantStack<T>& other);
		MutantStack<T>& operator=(const MutantStack<T>& other);
		~MutantStack();

		iterator		begin();
		iterator		end();
		const_iterator	begin() const;
		const_iterator	end() const;
};

#include "MutantStack.tpp"

#endif
