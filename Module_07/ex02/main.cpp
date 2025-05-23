#include "Array.hpp"
#include <iostream>

int main() {
	// Test default constructor
	std::cout << "Testing default constructor:" << std::endl;
	Array<int> arr1;
	std::cout << "arr1 size: " << arr1.size() << std::endl; // Expected: 0

	// Test constructor with size
	std::cout << "\nTesting constructor with size:" << std::endl;
	unsigned int n = 5;
	Array<int> arr2(n);
	std::cout << "arr2 size: " << arr2.size() << std::endl; // Expected: 5
	for (std::size_t i = 0; i < arr2.size(); ++i) {
		std::cout << "arr2[" << i << "] = " << arr2[i]
							<< std::endl; // Expected: 0 (default initialization)
	}

	// Test copy constructor
	std::cout << "\nTesting copy constructor:" << std::endl;
	Array<int> arr3(arr2);
	std::cout << "arr3 size: " << arr3.size() << std::endl; // Expected: 5
	for (std::size_t i = 0; i < arr3.size(); ++i) {
		std::cout << "arr3[" << i << "] = " << arr3[i]
							<< std::endl; // Expected: 0
	}

	// Test assignment operator
	std::cout << "\nTesting assignment operator:" << std::endl;
	Array<int> arr4;
	arr4 = arr2;
	std::cout << "arr4 size: " << arr4.size() << std::endl; // Expected: 5
	for (std::size_t i = 0; i < arr4.size(); ++i) {
		std::cout << "arr4[" << i << "] = " << arr4[i]
							<< std::endl; // Expected: 0
	}

	// Test modifying one array does not affect the copied array
	std::cout << "\nTesting modifying one array does not affect the copied array:"
			<< std::endl;
	arr2[0] = 42;
	std::cout << "arr2[0] = " << arr2[0] << std::endl; // Expected: 42
	std::cout << "arr3[0] = " << arr3[0] << std::endl; // Expected: 0

	// Test out-of-bounds access
	std::cout << "\nTesting out-of-bounds access:" << std::endl;
	try {
		std::cout << arr2[10] << std::endl; // Should throw an exception
	} catch (const std::out_of_range &e) {
		std::cerr << "Exception caught: " << e.what()
							<< std::endl; // Expected: out_of_range exception
	}

	// Test const array
	std::cout << "\nTesting const array:" << std::endl;
	const Array<int> arr5(3);
	std::cout << "arr5 size: " << arr5.size() << std::endl; // Expected: 3
	for (std::size_t i = 0; i < arr5.size(); ++i) {
		std::cout << "arr5[" << i << "] = " << arr5[i]
							<< std::endl; // Expected: 0
	}

	// Test print all elements
	std::cout << "\nTesting print all elem of array:" << std::endl;
	Array<int> arr6(4);
	std::cout << "arr6 size: " << arr6.size() << std::endl; // Expected: 4
	for (std::size_t i = 0; i < arr6.size(); ++i) {
		arr6[i] = i;
	}
	std::cout << "arr6 = " << arr6
							<< std::endl; // Expected: 0 - 3;

	// Test print all elements
	std::cout << "\nTesting print all elem of char array:" << std::endl;
	Array<char> arr7(4);
	std::cout << "arr7 size: " << arr7.size() << std::endl; // Expected: 4
	for (std::size_t i = 0; i < arr7.size(); ++i) {
		arr7[i] = 'A' + i;
	}
	std::cout << "arr7 = " << arr7 << std::endl; // Expected: A - D;

	return 0;
}
