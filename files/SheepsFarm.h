#ifndef SHEEPSFARM_H_
#define SHEEPSFARM_H_
#include "Farm.h"
#include "Sheep.h"

class SheepsFarm:
		public Farm {
public:
	SheepsFarm();
	virtual ~SheepsFarm(){}
	virtual void buyAnimal();
	virtual void buyProd(Farm* f);
	virtual void printFarm()const;
	virtual void setProd(){this->_prods["Wool"]+=this->getProd();}
	virtual void cowFarmObserver(Farm* f){}//get type
	virtual void sheepFarmObserver(Farm* f){f->cowFarmSubject(this);}
	virtual void chickenFarmObserver(Farm* f){}
	virtual void cowFarmSubject(Farm* f){}//want to-handle
	virtual void sheepFarmSubject(Farm* f);
	virtual void chickenFarmSubject(Farm* f){}
};

#endif /* SHEEPSFARM_H_ */
