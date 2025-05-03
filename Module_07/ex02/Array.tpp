#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

template <typename T>
Array<T>::Array() :
	_size(0),
	array(new T[0]())
{
}

template <typename T>
Array<T>::Array(unsigned int n) :
	_size(n),
	array(new T[n]())
{
}

template <typename T>
Array<T>::Array(const Array &src) :
	_size(src._size),
	array(new T[src._size])
{
	for (unsigned int i = 0; i < this->_size; i++)
		array[i] = src.array[i];
}

template <typename T>
Array<T>::~Array()
{
	delete[] array;
}

template <typename T>
Array<T>	&Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		delete[] array;
		this->_size = other._size;
		this->array = new T[this->_size];
		for (unsigned int i = 0; i < this->_size; i++)
			this->array[i] = other.array[i];
	}
	return (*this);
}

template <typename T>
T	&Array<T>::operator[](unsigned int index) throw(std::out_of_range)
{
	if (index >= this->_size)
		throw std::out_of_range("Index out of range");
	return (this->array[index]);
}

template <typename T>
const T	&Array<T>::operator[](unsigned int index) const throw(std::out_of_range)
{
	if (index >= this->_size)
		throw std::out_of_range("Index out of range");
	return (this->array[index]);
}

template <typename T>
unsigned int	Array<T>::size() const
{
	return (this->_size);
}

template <typename T>
std::ostream	&operator<<(std::ostream &out, const Array<T> &array)
{
	unsigned int n = array.size();

	out << "ARRAY ( ";

	for (unsigned int i = 0; i < n; i++) {
		out << array[i];
		if (i != n - 1)
			out << " - ";
	}
	out << " )";
	return (out);
}

#endif
