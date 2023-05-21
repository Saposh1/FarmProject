#ifndef MARKET_H_
#define MARKET_H_
#include "SheepsFarm.h"
#include "ChickensFarm.h"
#include "CowsFarm.h"
#include "Exceptions.h"

class Market {
	int _year;
	vector<Farm*>_farms;
public:
	Market(){this->_year=0;}//constructor
	virtual ~Market();//destructor
	int getYear()const{return this->_year;}//return the current year
	void nextYear();//pass one year of market - creating new farms, updating products of each farm,
	//business between farms and raising all animal ages in one year. dead animals are to remove also.
	void fastForwardYears();//passing given years of market
	void printMarketFarms()const;// print all the farms in market
	void farmNew();// creating new farms of given count
	void marketDay();// making business between farms in market

};

#endif /* MARKET_H_ */
