#include "whatever.hpp"
#include <iostream>

#define NL std::cout << std::endl;

void intTest(void) {
	int a = 2;
	int b = 3;

	NL;
	std::cout << "Initial value of a: " << a << std::endl;
	std::cout << "Initial value of b: " << b << std::endl;

	NL;
	std::cout << "Swaping values of 'a' and 'b'." << std::endl;
	::swap(a, b);

	std::cout << "Value of a after swap: " << a << std::endl;
	std::cout << "Value of b after swap: " << b << std::endl;

	NL;

	std::cout << "Min value between 'a' and 'b'" << std::endl;

	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	NL;

	std::cout << "Max value between 'a' and 'b'" << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
	NL;
}

void strTest(void) {
	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << "Initial value of c: " << c << std::endl;
	std::cout << "Initial value of d: " << d << std::endl;
	NL;

	std::cout << "Swaping values of 'c' and 'd'." << std::endl;
	::swap(c, d);
	std::cout << "Value of c after swap: " << c << std::endl;
	std::cout << "Value of d after swap: " << d << std::endl;
	NL;

	std::cout << "Min value between 'c' and 'd'" << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	NL;

	std::cout << "Max value between 'c' and 'd'" << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
}

void subjectTest(void) {
	NL;
	std::cout << "Test provided by subject" << std::endl;
	int a = 2;
	int b = 3;
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
}

int main(void) {
	intTest();
	strTest();
	subjectTest();
	return 0;
}

// !OTHER TESTS

// class Awesome
// {
// 	public:
// 		Awesome(void) : _n(0) {}
// 		Awesome( int n ) : _n( n ) {}
// 		Awesome & operator= (Awesome & a) { _n = a._n; return *this; }
// 		bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
// 		bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
// 		bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
// 		bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
// 		bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
// 		bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
// 		int get_n() const { return _n; }
// 	private:
// 		int _n;
// };

// std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o; }

// int main(void)
// {
// 	Awesome a(2), b(4);
// 	swap(a, b);
// 	std::cout << a << " " << b << std::endl;
// 	std::cout << max(a, b) << std::endl;
// 	std::cout << min(a, b) << std::endl;
// 	return (0);
// }
