#pragma once

#include <string>

using namespace std;

class contact
{
public:
	contact();
	~contact();
	contact(string name, string firstName, int age, int phoneNb);
	string getName();
	string getFirstName();
	int getAge();
	int getPhoneNb();
	void setName(string name);
	void setFirstName(string firstName);
	void setAge(int age);
	void setPhoneNb(int phoneNb);
	string makeCSV();

private:
	string name;
	string firstName;
	int age;
	int phoneNb;
};

