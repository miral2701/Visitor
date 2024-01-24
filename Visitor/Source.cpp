#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class House;
class Fabric;
class Banck;

class Insurance 
{
public:
	virtual void VisitHouse(House* p) =0;
	virtual void VisitFabric(Fabric* f) =0;
	virtual void VisitBanck(Banck* b) =0;

};

class Building abstract
{
	string builder;
public:
	virtual void Accept(Insurance* visitor)abstract;

	string GetBuilder()
	{ 
		return builder;
	}
	void SetBuilder(string Producer)
	{
		builder = Producer;
	}
};

class House: public Building
{
	int floorCount;
public:
	
	int GetFloorCount()
	{
		return floorCount;
	}
	void SetFloorCount(int c)
	{
		floorCount = c;
	}
	void Accept(Insurance* visitor) 
	{
		visitor->VisitHouse(this);
	}
};

class Fabric : public Building
{
	string owner;
public:

	string GetOwner()
	{
		return owner;
	}
	void SetOwner(string c)
	{
		owner= c;
	}
	void Accept(Insurance* visitor) 
	{
		visitor->VisitFabric(this);
	}
};

class Banck : public Building
{
	int money;
public:

	int GetMoney()
	{
		return money;
	}
	void SetMoney(int c)
	{
		money = c;
	}
	void Accept(Insurance* visitor) 
	{
		visitor->VisitBanck(this);
	}
};


class MedicalInsurance : public Insurance
{
public:
	void VisitHouse(House* p) override
	{
		cout << "MedicalInsurance for house with "<<p->GetFloorCount()<<" floors"<<endl;
	}
	void VisitFabric(Fabric* p) override
	{
		cout << "MedicalInsurance for fabric with " << p->GetOwner() << " owner"<<endl;
	}void VisitBanck(Banck* p)override 
	{
		cout << "MedicalInsurance for banck with " << p->GetMoney() << " money"<<endl;
	}
};

class BurglaryInsurance : public Insurance
{
public:
	void VisitHouse(House* p) 
	{
		cout << "BurglaryInsurance  for house with " << p->GetFloorCount() << " floors"<<endl;
	}
	void VisitFabric(Fabric* p) 
	{
		cout << "BurglaryInsurance  for fabric with " << p->GetOwner() << " owner"<<endl;
	}void VisitBanck(Banck* p) 
	{
		cout << "BurglaryInsurance  for banck with " << p->GetMoney() << " money"<<endl;
	}
};

class NatureDisasterInsurance : public Insurance
{
public:
	void VisitHouse(House* p) 
	{
		cout << "NatureDisasterInsurance  for house with " << p->GetFloorCount() << " floors"<<endl;
	}
	void VisitFabric(Fabric* p) 
	{
		cout << "NatureDisasterInsurance for fabric with " << p->GetOwner() << " owner"<<endl;
	}void VisitBanck(Banck* p) 
	{
		cout << "NatureDisasterInsurance  for banck with " << p->GetMoney() << " money"<<endl;
	}
};
class Insurancer
{
	vector<Building*> houses;
public:
	void Add(Building* d)
	{
		houses.push_back(d);
	}
	void Remove(Building* d)
	{
		auto iter = find(houses.begin(), houses.end(), d);
		if(iter != houses.end())
			houses.erase(iter);
	}
	void Accept(Insurance* a)
	{
		for(Building* d : houses)
			d->Accept(a);
	}
};

int main()
{
	Insurancer* i = new Insurancer();
	House* house = new House();
	house->SetBuilder("Kador");
	house->SetFloorCount(2);

	Fabric* fabric = new Fabric();
	fabric->SetBuilder("Kador");
	fabric->SetOwner("Mira");

	Banck* banck = new Banck();
	banck->SetBuilder("Kador");
	banck->SetMoney(100403);

	i->Add(house);
	i->Add(fabric);
	i->Add(banck);

	Insurance* ins = new MedicalInsurance();
	i->Accept(ins);

	

	delete house;
	delete fabric;
	delete banck;
	delete ins;

	system("pause");
}
