#include "SheepsFarm.h"

SheepsFarm::SheepsFarm():Farm(){
	int i;
	for (i=0;i<3;i++)
	{
		Sheep* sheep=new Sheep();
		if (sheep == nullptr)
		{
			//delete all the created animals until now
			for (int i=0; i<(int)this->_listOfAnimals.size(); i++)
			{
				delete this->_listOfAnimals[i];
			}
			exit(0);
		}
		this->_listOfAnimals.push_back(sheep);
	}
	this->_priceOfProd=sheepProd;
}

void SheepsFarm::buyProd(Farm* f)
{
	if (f->getCountOfProd("Milk")!=0)
	{
		//subscriber keeps buying till he has no money or till our
		//farm is out of prods
		int sumOfBought=0;
		while(this->_Money>=f->getpriceOfProd() && f->getCountOfProd("Milk")>0)
			{
				this->_Money-=f->getpriceOfProd();
				f->setProductValue("Milk", -1);
				f->setMoney(f->getpriceOfProd());
				this->_prods["Milk"]+=1;
				sumOfBought++;
			}
			if (sumOfBought!=0)
			{
				std::cout << "Sheep farm(" << this->_Id << ") bought " << sumOfBought << " milk for " << sumOfBought*f->getpriceOfProd() << " dollars from Cow farm(" << f->getId() << ")" << std::endl;
			}
		}
}

void SheepsFarm::buyAnimal()
{
	int amount=0;
	float price=0;
	if(this->_listOfAnimals.size()==0)//no animals in farm
	{
		Sheep* cs=new Sheep();
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
		Sheep* sheep=new Sheep();
		if (sheep == nullptr)
		{
			//delete all the created animals until now
			for (int i=0; i<(int)this->_listOfAnimals.size(); i++)
			{
				delete this->_listOfAnimals[i];
			}
			exit(0);
		}
		this->_listOfAnimals.push_back(sheep);
		this->_Money-=price;
		amount+=1;
	}
	if(amount != 0)
	{
		cout << "Sheep farm(" << this->getId() << ") bought " << amount << " sheeps for " << amount*price <<" dollars" << endl;
	}
}

void SheepsFarm::printFarm()const{
	cout << "Farm Id: " << this->getId() << ", type: Sheep farm, Money: " << this->_Money << ", Animals: " << this->_listOfAnimals.size() << " sheep, Products: Milk[" << this->_prods.find("Milk")->second << "], Wool[" << this->_prods.find("Wool")->second << "], Eggs[" << this->_prods.find("Eggs")->second << "]" << endl;
}

void SheepsFarm::sheepFarmSubject(Farm* f)
{
	this->subscribers.push_back(f);
	cout << "Sheep farm(" << this->_Id << ") Added Chicken farm(" << f->getId() << ") to his client list" << endl;
}

