#include <exception>
#include <iostream>
using namespace std;

class sheepEX : public exception
{
public:
	virtual const char* what() const throw()
	{
		return "Insert valid number of sheep farms\n";
	}
};

class cowEX : public exception
{
public:
	virtual const char* what() const throw()
	{
		return "Insert valid number of cow farms\n";
	}
};

class chickenEX : public exception
{
public:
	virtual const char* what() const throw()
	{
		return "Insert valid number of chicken farms\n";
	}
};
