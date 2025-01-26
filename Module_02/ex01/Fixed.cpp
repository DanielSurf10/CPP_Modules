#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedPointValue = value * (1 << Fixed::fractionalBits);

	// Similar to
	// this->fixedPointValue = value * (pow(2, Fixed::fractionalBits));
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedPointValue = roundf(value * (1 << Fixed::fractionalBits));
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy Constructor Called" << std::endl;
	*this = other;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &other)
		this->fixedPointValue = other.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	return (this->fixedPointValue);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixedPointValue = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float) this->fixedPointValue / (1 << Fixed::fractionalBits));
}

int	Fixed::toInt(void) const
{
	return (this->fixedPointValue >> Fixed::fractionalBits);
}

std::ostream&	operator<<(std::ostream &out, Fixed const &value)
{
	out << value.toFloat();
	return (out);
}
