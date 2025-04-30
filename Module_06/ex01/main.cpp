#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

static void printData(const Data *p) {
	std::cout << "Value: " << p->getValue() << std::endl;
	std::cout << std::endl;
}

int main(void) {
	Data *data = new Data();

	data->setValue(42);

	uintptr_t	ptr;

	std::cout << "Data before serialize" << std::endl;
	printData(data);

	ptr = Serializer::serialize(data);

	std::cout << "Data after serialize" << std::endl;
	printData(data);

	Data	*testData;

	testData = Serializer::deserialize(ptr);
	std::cout << "Data after deserialize" << std::endl;
	printData(testData);

	delete data;

	return (0);
}
