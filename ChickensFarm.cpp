#include "ChickensFarm.h"

ChickensFarm::ChickensFarm():Farm(){
	this->_priceOfProd=chickenProd;
	int i;
	for (i=0; i<3; i++)
	{
		Chicken* chicken=new Chicken();
		if (chicken == nullptr)
		{
			//delete all the created animals until now
			for (int i=0; i<(int)this->_listOfAnimals.size(); i++)
			{
				delete this->_listOfAnimals[i];
			}
			exit(0);
		}
		this->_listOfAnimals.push_back(chicken);
	}
}

void ChickensFarm::buyProd(Farm* f)
{
	if (f->getCountOfProd("Wool")!=0)
	{
		//subscriber keeps buying till he has no money or till our
		//farm is out of prods
		int sumOfBought=0;
		while(this->_Money>=f->getpriceOfProd() && f->getCountOfProd("Wool")>0)
			{
				this->_Money-=f->getpriceOfProd();
				f->setProductValue("Wool", -1);
				f->setMoney(f->getpriceOfProd());
				this->_prods["Wool"]+=1;
				sumOfBought++;
			}
			if (sumOfBought!=0)
			{
				std::cout << "Chicken farm(" << this->_Id << ") bought " << sumOfBought << " wool for " << sumOfBought*f->getpriceOfProd() << " dollars from Sheep farm(" << f->getId() << ")" << std::endl;
			}
		}
}

void ChickensFarm::buyAnimal()
{
	int amount=0;
	float price=0;
	if(this->_listOfAnimals.size()==0)//no animals in farm
	{
		Chicken* cs=new Chicken();
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
		Chicken* chicken=new Chicken();
		if (chicken == nullptr)
		{
			//delete all the created animals until now
			for (int i=0; i<(int)this->_listOfAnimals.size(); i++)
			{
				delete this->_listOfAnimals[i];
			}
			exit(0);
		}
		this->_listOfAnimals.push_back(chicken);
		this->_Money-=price;
		amount+=1;
	}
	if(amount != 0)
	{
		cout << "Chicken farm(" << this->_Id << ") bought " << amount << " chickens for " << amount*price <<" dollars" << endl;
	}
}

void ChickensFarm::printFarm()const{
	cout << "Farm Id: " << this->_Id << ", type: Chicken Farm, Money: " << this->_Money << ", Animals: " << this->_listOfAnimals.size() << " chickens, Products: Milk[" << this->_prods.find("Milk")->second << "], Wool[" << this->_prods.find("Wool")->second << "], Eggs[" << this->_prods.find("Eggs")->second << "]" << endl;
}

void ChickensFarm::chickenFarmSubject(Farm* f)
{
	this->subscribers.push_back(f);
	cout << "Chicken farm(" << this->_Id << ") Added Cow farm(" << f->getId() << ") to his client list" << endl;
}

