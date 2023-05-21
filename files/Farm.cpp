#include "Farm.h"

int Farm::count=0;

Farm::Farm()
{
	++count;
	this->_Id=count;
	this->_Money=10;
	this->_prods["Eggs"]=0;
	this->_prods["Wool"]=0;
	this->_prods["Milk"]=0;
	this->_priceOfProd=0;
}

Farm::~Farm()
{
	count--;
	int i;
	for(i=0;i<(int)this->_listOfAnimals.size();i++)
	{
		delete this->_listOfAnimals[i];
	}
}
int Farm::getProd()const
{
	int totalProd=0;
	for (int i=0; i<(int)this->_listOfAnimals.size();i++)
	{
		totalProd+=this->_listOfAnimals[i]->_age;
	}
	return totalProd;
}

int Farm::getId()const
{
	return this->_Id;
}

void Farm::removeAnimals()
{
	int i=0;
	vector<Animal*>::iterator it;
	while(i<(int)this->_listOfAnimals.size())
	{
		if(this->_listOfAnimals[i]->_age==this->_listOfAnimals[i]->_ageOfDeath)
		{
			it=this->_listOfAnimals.begin();
			while(it!=this->_listOfAnimals.end())
			{
				if(*it==this->_listOfAnimals[i])
				{
					delete this->_listOfAnimals[i];
					this->_listOfAnimals.erase(it);
					i--;
					break;
				}
				it++;
			}
		}
		i++;
	}
}

void Farm::yearsOfAnimals()
{
	int i;
	for(i=0;i<(int)this->_listOfAnimals.size();i++)
	{
		this->_listOfAnimals[i]->_age+=1;
	}
	this->removeAnimals();
}
