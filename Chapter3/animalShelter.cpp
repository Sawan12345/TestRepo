// Animal Shelter program
// 

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <queue>

using namespace std;


class Animal{
	int rank;
	string name;
	string type;
public:
	Animal()
	{
		rank = 0;
		name = "";
		type = "";
	}
	Animal(string n,string t){
		rank = 0;
		name = n;
		type = t;
	}
	void setRank(int r)
	{
		rank = r;
	}
	void setName(string s)
	{
		name = s;
	}
	int getRank(){ return rank; }
	string getName() { return name; }
	string getType(){ return type; }
	
};

class Dog : public Animal{
	
public:
	Dog(string name) : Animal(name,string("dog")){}
	

};
class Cat : public Animal{
	
public:
	Cat(string name) : Animal(name,string("cat")){}
	

};

class AnimalShelter{
	queue<Animal*> dogs;
	queue<Animal*> cats;
	int rank=0;
public:
	void enqueue(Animal *a){
		a->setRank(rank++);
		if (a->getType() == "dog")
		{
			dogs.push(a);
		}
		else{
			cats.push(a);
		}
	}
	Animal* dequeueAny(){
		Animal *a;
		if (dogs.empty())
		{
			return dequeueCat();
		}
		if (cats.empty())
		{
			return dequeueDog();
		}
		
		if (dogs.front()->getRank() < cats.front()->getRank())
		{
			 a = dogs.front();
			 dogs.pop();
		}
		else{
			a = cats.front();
			cats.pop();
		}
		return a;
	}

	Animal* dequeueDog(){
		if (!dogs.empty()) 
		{
			Animal *a = dogs.front();
			dogs.pop();
			return a;
		}
		else if (!cats.empty()){
			return dequeueCat();
		}
		else{
			cout << "Shelter is empty at this time, come back later." << endl;
			return NULL;
		}
		
	}
	Animal* dequeueCat(){
		if (!cats.empty())
		{
			Animal *a = cats.front();
			cats.pop();
			return a;
		}
		else if (!dogs.empty()){
			return dequeueDog();
		}
		else{
			cout << "Shelter is empty at this time, come back later." << endl;
			return NULL;
		}

	}

};

class Employee{
protected:
	string name;
	double pay;
public:
	Employee(){
		name = "";
		pay = 0;
	}
	Employee(string n, double p)
	{
		name = n;
		pay = p;
	}
	void setName(string n){
		name = n;
	}
	string getName(){ return name; }
	void setPay(double p)
	{
		pay = p;
	}
	double getPay(){ return pay; }
	string toString()
	{
		stringstream stm;
		stm << name << ":" << pay;
		return stm.str();
	}

	virtual double grossPay(int hours)
	{
		return pay * hours;
	}
};

class Manager : public Employee{
private:
	bool salaried;
public:
	Manager(string name, double pay, bool isSalaried) :Employee(name, pay), salaried(isSalaried){}
	bool getSalaried(){ return salaried; }
	double grossPay(int hours){
		if (salaried)
			return pay;
		else
			return pay*hours;
	}
	string toString(){
		stringstream stm;
		string salary;
		if (salaried)
		{
			salary = "Salaried";
		}
		else
		{
			salary = "Hourly";
		}
		stm << name << ":" << pay << ":" << salary << endl;
		return stm.str();
	}

};

int main()
{
	Dog dog1("moti1");
	Dog dog2("moti2");
	Dog dog3("moti3");
	Dog dog4("moti4");

	Animal* aPtr[8];

	Cat cat1("coti1");
	Cat cat2("coti2");
	Cat cat3("coti3");
	Cat cat4("coti4");

	aPtr[0] = &dog1;
	aPtr[1] = &cat1;
	aPtr[2] = &cat2;
	aPtr[3] = &dog2;
	aPtr[4] = &dog3;
	aPtr[5] = &dog4;
	aPtr[6] = &cat3;
	aPtr[7] = &cat4;

	AnimalShelter sltr;
	sltr.enqueue(aPtr[0]);
	sltr.enqueue(aPtr[1]);
	sltr.enqueue(aPtr[2]);
	sltr.enqueue(aPtr[3]);
	sltr.enqueue(aPtr[4]);
	sltr.enqueue(aPtr[5]);
	sltr.enqueue(aPtr[6]);
	sltr.enqueue(aPtr[7]);


	Animal *get = sltr.dequeueAny();
	cout << get->getName() << get->getRank() << get->getType() << endl;
	get = sltr.dequeueDog();
	cout << get->getName() << get->getRank() << get->getType() << endl;
	get = sltr.dequeueCat();
	cout << get->getName() << get->getRank() << get->getType() << endl;


	return 0;
}
