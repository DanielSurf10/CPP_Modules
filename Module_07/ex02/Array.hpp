#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
	private:
		unsigned int	_size;
		T				*array;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array &src);
		~Array();

		Array	&operator=(const Array &other);
		T		&operator[](unsigned int index) throw(std::out_of_range);
		const T	&operator[](unsigned int index) const throw(std::out_of_range);

		unsigned int	size() const;
};

template <typename T>
std::ostream	&operator<<(std::ostream &out, const Array<T> &rhs);

# include "Array.tpp"

#endif
