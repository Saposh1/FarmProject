#include "Market.h"

Market:: ~Market(){
	int i;
	for(i=0;i<(int)this->_farms.size();i++)
	{
		delete this->_farms[i];
	}
}
void Market::farmNew(){
	int cows, sheeps,chickens;
	cout << "How many new cow farms will be added this year?" << endl;
	cin >> cows;
	try{
		if(cows <0)
		{
			throw cowEX();
		}
	}
	catch (exception& e)
	{
		cout << e.what();
		return this->farmNew();
	}

	cout << "How many new sheep farms will be added this year?" << endl;
	cin >> sheeps;
	try{
		if(sheeps <0)
		{
			throw sheepEX();
		}
	}
	catch (exception& e)
	{
		cout << e.what();
		return this->farmNew();
	}
	cout << "How many new chicken farms will be added this year?" << endl;
	cin >> chickens;
	try{
		if(chickens <0)
		{
			throw chickenEX();
		}
	}
	catch (exception& e)
	{
		cout << e.what();
		return this->farmNew();
	}
	cout << "----Adding new farms to market----" << endl;
	int i;
	//adding cow farms
	for(i=0;i<cows;i++)
	{
		CowsFarm* new1= new CowsFarm();
		if (new1 == nullptr)
		{
			delete this;
			exit(0);
		}
		this->_farms.push_back(new1);
		int j;
		for (j=0;j<(int)this->_farms.size();j++)//observers and subjects
		{
			new1->cowFarmObserver(this->_farms[j]);
			this->_farms[j]->sheepFarmObserver(new1);
		}
	}
	//adding sheep farm
	for(i=0;i<sheeps;i++)
	{
		SheepsFarm* new2= new SheepsFarm();
		if (new2 == nullptr)
		{
			delete this;
			exit(0);
		}
		this->_farms.push_back(new2);
		int j;
		for (j=0;j<(int)this->_farms.size();j++)//observers and subjects
		{
			new2->sheepFarmObserver(this->_farms[j]);
			this->_farms[j]->chickenFarmObserver(new2);
		}
	}
	//adding chicken farms
	for(i=0;i<chickens;i++)
	{
		ChickensFarm* new3= new ChickensFarm();
		if (new3 == nullptr)
		{
			delete this;
			exit(0);
		}
		this->_farms.push_back(new3);
		int j;
		for (j=0;j<(int)this->_farms.size();j++)//observers and subjects
		{
			new3->chickenFarmObserver(this->_farms[j]);
			this->_farms[j]->cowFarmObserver(new3);
		}
	}
}

void Market::marketDay()
{
	cout << "----Begin Market----" << endl;
	int i,j;
	for(i=0;i<(int)this->_farms.size();i++)
	{
		for(j=0;j<(int)this->_farms[i]->subscribers.size();j++)
		{
			this->_farms[i]->subscribers[j]->buyProd(this->_farms[i]);
		}
	}
	cout << "----Buy Animals----" << endl;
	for(i=0;i<(int)this->_farms.size();i++)
	{
		this->_farms[i]->buyAnimal();
	}
}

void Market::printMarketFarms()const
{
	cout << "----Market Farms----" << endl;
	int i;
	for(i=0;i<(int)this->_farms.size();i++)
	{
		this->_farms[i]->printFarm();
	}
}

void Market::nextYear()
{
	cout << "----Creating new farms----" << endl;
	this->farmNew();
	int i;
	for (i=0;i<(int)this->_farms.size();i++)
	{
		this->_farms[i]->setProd();
	}
	this->marketDay();
	for (i=0;i<(int)this->_farms.size();i++)
	{
		this->_farms[i]->_Money+=10;
		this->_farms[i]->yearsOfAnimals();
	}
	this->_year++;
}

void Market::fastForwardYears()
{
	int z;
	cout<<"How many years to fast forward?"<<endl;
	cin >> z;
	int j=0;
	while(j<z)
	{
		int i;
		for (i=0;i<(int)this->_farms.size();i++)
		{
			this->_farms[i]->setProd();
		}
		this->marketDay();
		for (i=0;i<(int)this->_farms.size();i++)
		{
			this->_farms[i]->_Money+=10;
			this->_farms[i]->yearsOfAnimals();
		}
		this->_year++;
		j++;
	}
}
