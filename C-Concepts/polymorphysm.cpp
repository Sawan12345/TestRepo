// Polymorphism example.
// 

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;


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
	vector<Employee*> emps;
	Employee emp1("Sawan", 60);
	Manager emp2("Vani", 8000, true);
	Employee *emp1Ptr;
	Employee *emp2Ptr;
	emp1Ptr = &emp1;
	emp2Ptr = &emp2;
	emps.push_back(emp1Ptr);
	emps.push_back(emp2Ptr);

	for (int i = 0; i < emps.size(); ++i)
	{
		cout << emps[i]->grossPay(40) << endl;
	}
	return 0;
}
