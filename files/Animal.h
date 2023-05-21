#ifndef ANIMAL_H_
#define ANIMAL_H_
#include <string.h>
#include <iostream>
using namespace std;

class Animal {
protected:
	int _age;
	float _price;
	int _ageOfDeath;
public:
	Animal();//constructor
	virtual ~Animal()=0;//destructor
	float getPrice()const{return this->_price;}; //returns the price of the animal
	friend class Farm;//animal gives permission to the abstract class of Farm to access animals fields..
};

#endif /* ANIMAL_H_ */
