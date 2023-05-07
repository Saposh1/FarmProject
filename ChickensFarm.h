#ifndef CHICKENSFARM_H_
#define CHICKENSFARM_H_
#include "Farm.h"
#include "Chicken.h"

class ChickensFarm:
		public Farm {
public:
	ChickensFarm();//constructor
	virtual ~ChickensFarm(){}//destructor
	virtual void buyAnimal();//buy chickens. the amount of chickens depends on the money count the farm owns
	virtual void buyProd(Farm* f);//buying a prod from a different farm. the prod count depends on the money count the farm owns and the prod amount the different farm owns
	virtual void printFarm()const;//prints the farm info
	virtual void setProd(){this->_prods["Eggs"]+=this->getProd();}//sets the products of the farm.

	//observers
	virtual void cowFarmObserver(Farm* f){}//get type
	virtual void sheepFarmObserver(Farm* f){}
	virtual void chickenFarmObserver(Farm* f){f->sheepFarmSubject(this);}
	virtual void cowFarmSubject(Farm* f){}//want to-handle
	virtual void sheepFarmSubject(Farm* f){}
	virtual void chickenFarmSubject(Farm* f);
};

#endif /* CHICKENSFARM_H_ */
