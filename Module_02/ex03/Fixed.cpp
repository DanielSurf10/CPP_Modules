#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0)
{
}

Fixed::Fixed(const int value)
{
	this->fixedPointValue = value * (1 << Fixed::fractionalBits);

	// Similar to
	// this->fixedPointValue = value * (pow(2, Fixed::fractionalBits));
}

Fixed::Fixed(const float value)
{
	this->fixedPointValue = roundf(value * (1 << Fixed::fractionalBits));
}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->fixedPointValue = other.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
}

int	Fixed::operator>(const Fixed& other)
{
	return (this->fixedPointValue > other.getRawBits());
}

int	Fixed::operator<(const Fixed& other)
{
	return (this->fixedPointValue < other.getRawBits());
}

int	Fixed::operator>=(const Fixed& other)
{
	return (this->fixedPointValue >= other.getRawBits());
}

int	Fixed::operator<=(const Fixed& other)
{
	return (this->fixedPointValue <= other.getRawBits());
}

int	Fixed::operator==(const Fixed& other)
{
	return (this->fixedPointValue == other.getRawBits());
}

int	Fixed::operator!=(const Fixed& other)
{
	return (this->fixedPointValue != other.getRawBits());
}

Fixed	Fixed::operator+(const Fixed& other)
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed	Fixed::operator-(const Fixed& other)
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed	Fixed::operator*(const Fixed& other)
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/(const Fixed& other)
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;

	this->fixedPointValue++;
	return(tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;

	this->fixedPointValue--;
	return(tmp);
}

Fixed	&Fixed::operator++(void)
{
	this->fixedPointValue++;
	return (*this);
}

Fixed	&Fixed::operator--(void)
{
	this->fixedPointValue--;
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return (this->fixedPointValue);
}

void	Fixed::setRawBits(int const raw)
{
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

Fixed&	Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

Fixed&	Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

const Fixed&	Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

const Fixed&	Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}
