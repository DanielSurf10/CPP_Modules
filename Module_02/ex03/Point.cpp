#include "Fixed.hpp"
#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(Fixed x, Fixed y) : x(x), y(y)
{
}

Point::Point(const Point& other) : x(other.x), y(other.y)
{
}

Point&	Point::operator=(const Point& other)
{
	if (this != &other)
	{
		this->x.setRawBits(other.x.getRawBits());
		this->y.setRawBits(other.y.getRawBits());
	}
	return (*this);
}

Point::~Point()
{
}

Fixed	Point::get_x() const
{
	return (this->x);
}

Fixed	Point::get_y() const
{
	return (this->y);
}
