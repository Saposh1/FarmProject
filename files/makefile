CPP_FARM:farmMarket.o Animal.o Chicken.o Cow.o Sheep.o Farm.o CowsFarm.o SheepsFarm.o ChickensFarm.o Market.o
		g++ farmMarket.o Animal.o Chicken.o Cow.o Sheep.o Farm.o CowsFarm.o SheepsFarm.o ChickensFarm.o Market.o -o CPP_FARM
farmMarket.o:farmMarket.cpp Market.h 
		g++ -c farmMarket.cpp
Animal.o:Animal.cpp
		g++ -c Animal.cpp
Chicken.o:Chicken.cpp Animal.h
		g++ -c Chicken.cpp
Cow.o:Cow.cpp Animal.h
		g++ -c Cow.cpp
Sheep.o:Sheep.cpp Animal.h
		g++ -c Sheep.cpp
Farm.o:Farm.cpp Animal.h
		g++ -c Farm.cpp
CowsFarm.o:CowsFarm.cpp Farm.h Cow.h
		g++ -c CowsFarm.cpp
SheepsFarm.o:SheepsFarm.cpp Farm.h Sheep.h
		g++ -c SheepsFarm.cpp
ChickensFarm.o:ChickensFarm.cpp Farm.h Chicken.h
		g++ -c ChickensFarm.cpp
Market.o:Market.cpp CowsFarm.h SheepsFarm.h ChickensFarm.h Exceptions.h
		g++ -c Market.cpp
clean:
		rm -f *.o
