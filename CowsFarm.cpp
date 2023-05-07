#include "CowsFarm.h"


CowsFarm::CowsFarm(): Farm(){
	int i;
	for (i=0;i<3;i++)
	{
		Cow* cow=new Cow();
		if (cow == nullptr)
		{
			//delete all the created animals until now
			for (int i=0; i<(int)this->_listOfAnimals.size(); i++)
			{
				delete this->_listOfAnimals[i];
			}
			exit(0);
		}
		this->_listOfAnimals.push_back(cow);
	}
	this->_priceOfProd=cowProd;
}

void CowsFarm::buyProd(Farm* f)
{
	if (f->getCountOfProd("Eggs")!=0)
	{
		//subscriber keeps buying till he has no money or till our
		//farm is out of prods
		int sumOfBought=0;
		while(this->_Money>=f->getpriceOfProd() && f->getCountOfProd("Eggs")>0)
			{
				this->_Money-=f->getpriceOfProd();
				f->setProductValue("Eggs", -1);
				f->setMoney(f->getpriceOfProd());
				this->_prods["Eggs"]+=1;
				sumOfBought++;
			}
			if (sumOfBought!=0)
			{
				std::cout << "Cow farm(" << this->_Id << ") bought " << sumOfBought << " eggs for " << sumOfBought*f->getpriceOfProd() << " dollars from Chicken farm(" << f->getId() << ")" << std::endl;
			}
		}
}


void CowsFarm::buyAnimal()
{
	int amount=0;
	float price=0;
	if(this->_listOfAnimals.size()==0)//no animals in farm
	{
		Cow* cs=new Cow();
		if (cs == nullptr)
		{
			//delete all the created animals until now
			for (int i=0; i<(int)this->_listOfAnimals.size(); i++)
			{
				delete this->_listOfAnimals[i];
			}
			exit(0);
		}
		price=cs->getPrice();
		delete cs;
	}
	else//there are animals in farm
	{
		price=this->_listOfAnimals[0]->getPrice();
	}
	while(this->_Money>=price)
	{
		Cow* cow=new Cow();
		if (cow == nullptr)
		{
			//delete all the created animals until now
			for (int i=0; i<(int)this->_listOfAnimals.size(); i++)
			{
				delete this->_listOfAnimals[i];
			}
			exit(0);
		}
		this->_listOfAnimals.push_back(cow);
		this->_Money-=price;
		amount+=1;
	}
	if(amount != 0)
	{
		cout << "Cow farm(" << this->getId() << ") bought " << amount << " cows for " << amount*price <<" dollars" << endl;
	}
}

void CowsFarm::printFarm()const{
	cout << "Farm Id: " << this->getId() << ", type: Cow farm, Money: " << this->_Money << ", Animals: " << this->_listOfAnimals.size() << " cows, Products: Milk[" << this->_prods.find("Milk")->second << "], Wool[" << this->_prods.find("Wool")->second << "], Eggs[" << this->_prods.find("Eggs")->second << "]" << endl;
}

void CowsFarm::cowFarmSubject(Farm* f)
{
	this->subscribers.push_back(f);
	cout << "Cow farm(" << this->_Id << ") Added Sheep farm(" << f->getId() << ") to his client list" << endl;
}

