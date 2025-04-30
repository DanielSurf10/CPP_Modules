#ifndef DATA_HPP
# define DATA_HPP

class Data
{
	private:
		int value;

	public:
		Data();
		Data(int i);
		Data(const Data &src);
		~Data();
		Data	&operator=(const Data &rhs);

		int		getValue() const;
		void	setValue(int i);
};

#endif
