#ifndef FARM_H_
#define FARM_H_
#include "Animal.h"
#include <vector>
#include <map>

enum priceOfProd{chickenProd=1,sheepProd=2,cowProd=3};

class Farm {
	static int count;
protected:
	int _Id;
	float _Money;
	int _priceOfProd;
	vector<Farm*> subscribers;
	vector <Animal*> _listOfAnimals;
	map<string, int>_prods;

public:
	Farm();
	virtual ~Farm();
	int getId()const;

	//dictionary gets sets
	void setProductValue(string key, int val){this->_prods.find(key)->second+=val;}//increase the value of prod when the farm buys prod
	int getCountOfProd(string key)const{return this->_prods.find(key)->second;};//get the count of prod of a farm
	int getpriceOfProd()const{return this->_priceOfProd;}//get the price of prod of a farm

	//money set
	void setMoney(int val){this->_Money+=val;}//increase the money count of a farm when it sells a prod to other farm

	virtual void buyAnimal()=0;//buy animal depends on the money count of the farm. this func is pure virtual - implemented by children
	virtual void buyProd(Farm* f)=0;//buy product of other farm. this func is pure virtual - implemented by children
	void removeAnimals();//remove from farm animals which age is equals to death age
	virtual void printFarm()const=0;//prints the info about the farm
	int getProd()const;//gets the amount of prod a farm produce.
	virtual void setProd()=0; //sets the prod amount of a farm. this func is pure virtual - implemented by children. this func is pure virtual - implemented by children
	void yearsOfAnimals();//update ages of animals in farm to be 1 year older.

	//these funcs informs a farm in the market about the kind of the new farm by calling to the specific subject func which implemented only in farms of specific kind - the kind of which the new farm want the
	//products of. these funcs are pure virtual - implemented by children
	virtual void cowFarmObserver(Farm* f)=0;//get type
	virtual void sheepFarmObserver(Farm* f)=0;
	virtual void chickenFarmObserver(Farm* f)=0;

	//these funcs adds a new farm to subscribers list if the new farm was sent to them. these funcs are pure virtual - implemented by children
	virtual void cowFarmSubject(Farm* f)=0;//want to-handle
	virtual void sheepFarmSubject(Farm* f)=0;
	virtual void chickenFarmSubject(Farm* f)=0;
	friend class Market;//market if friend class of farm - farm gives market the permission to use its fields
};

#endif /* FARM_H_ */
