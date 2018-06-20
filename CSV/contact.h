#pragma once

#include <string>

using namespace std;

class contact
{
public:
	contact();
	~contact();
	contact(int id, string name, string firstName, int age, int phoneNb);
	int getId();
	string getName();
	string getFirstName();
	int getAge();
	int getPhoneNb();
	void setId(int id);
	void setName(string name);
	void setFirstName(string firstName);
	void setAge(int age);
	void setPhoneNb(int phoneNb);
	string makeCSV();

private:
	int id;
	string name;
	string firstName;
	int age;
	int phoneNb;
};

