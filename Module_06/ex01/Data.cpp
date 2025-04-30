#include "Data.hpp"

Data::Data() : value(0) {}

Data::Data(int i) : value(i) {}

Data::Data(const Data &src) : value(src.value) {}

Data::~Data() {}

Data &Data::operator=(const Data &rhs)
{
	if (this != &rhs)
		this->value = rhs.value;
	return *this;
}

int Data::getValue() const
{
	return this->value;
}

void Data::setValue(int i)
{
	this->value = i;
}
