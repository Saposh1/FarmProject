#ifndef COWSFARM_H_
#define COWSFARM_H_
#include "Farm.h"
#include "Cow.h"

class CowsFarm:
		public Farm {
public:
	CowsFarm();//constructor
	virtual ~CowsFarm(){}//destructor
	virtual void buyAnimal();//
	virtual void buyProd(Farm* f);
	virtual void printFarm()const;
	virtual void setProd(){this->_prods["Milk"]+=this->getProd();}

	//observers and subjects lists
	virtual void cowFarmObserver(Farm* f){f->chickenFarmSubject(this);}//cow farm wants to add to the client list of chicken farms
	virtual void sheepFarmObserver(Farm* f){}
	virtual void chickenFarmObserver(Farm* f){}
	virtual void cowFarmSubject(Farm* f);//want to-handle
	virtual void sheepFarmSubject(Farm* f){}
	virtual void chickenFarmSubject(Farm* f){}
};


#endif /* COWSFARM_H_ */
