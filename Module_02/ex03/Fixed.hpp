#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		static const int	fractionalBits = 8;
		int					fixedPointValue;

	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();

		int		operator>(const Fixed& other);
		int		operator<(const Fixed& other);
		int		operator>=(const Fixed& other);
		int		operator<=(const Fixed& other);
		int		operator==(const Fixed& other);
		int		operator!=(const Fixed& other);

		Fixed	operator+(const Fixed& other);
		Fixed	operator-(const Fixed& other);
		Fixed	operator*(const Fixed& other);
		Fixed	operator/(const Fixed& other);
		Fixed	operator++(int);
		Fixed	operator--(int);
		Fixed	&operator++(void);
		Fixed	&operator--(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;

		static			Fixed& min(Fixed &a, Fixed &b);
		static			Fixed& max(Fixed &a, Fixed &b);
		static const	Fixed& min(const Fixed &a, const Fixed &b);
		static const	Fixed& max(const Fixed &a, const Fixed &b);
};

std::ostream	&operator<<(std::ostream &oStream, const Fixed &nbr);

#endif
