#include "stdafx.h"
#include "contact.h"
#include <sstream>
#include <iostream>


contact::contact()
{
}


contact::~contact()
{
}

contact::contact(int id, string name, string firstName, int age, int phoneNb) {
	this->id = id;
	this->name = name;
	this->firstName = firstName;
	this->age = age;
	this->phoneNb = phoneNb;
}

int contact::getId() {
	return id;
}
string contact::getName() {
	return name;
}

string contact::getFirstName() {
	return firstName;
}

int contact::getAge() {
	return age;
}

int contact::getPhoneNb() {
	return phoneNb;
}

void contact::setId(int id) {
	this->id = id;
}

void contact::setName(string name) {
	this->name = name;
}

void contact::setFirstName(string firstName) {
	this->firstName = firstName;
}

void contact::setAge(int age) {
	this->age = age;
}

void contact::setPhoneNb(int phoneNb) {
	this->phoneNb = phoneNb;
}

string contact::makeCSV() {
	stringstream sstm;
	sstm << id << "," << name << "," << firstName << "," << age << "," << phoneNb;
	return sstm.str();
}