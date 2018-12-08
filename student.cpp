#pragma once

#include "Student.h"
#include <iostream>
using namespace std;

Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = 0;
	for (int i = 0; i < 3; ++i) {
		numDays[i] = 0;
	}
}

Student::Student(string studentID, string firstName, string lastName, string email, int age, int numDays[3], DegreeType type)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < 3; ++i) {
		this->numDays[i] = numDays[i];
	}
}

string Student::getstudentID()
{
	return studentID;
}

string Student::getFirstName()
{
	return firstName;
}

string Student::getlastName()
{
	return lastName;
}

string Student::getemail()
{
	return email;
}

int Student::getage()
{
	return age;
}

int* Student::getNumDays()
{
	return this->numDays;
}

void Student::setstudentID(string studentID)
{
	this->studentID = studentID;
}

void Student::setfirstName(string firstName)
{
	this->firstName = firstName;
}

void Student::setlastName(string lastName)
{
	this->lastName = lastName;
}

void Student::setemail(string email)
{
	this->email = email;
}

void Student::setage(int age)
{
	this->age = age;
}

void Student::setNumDays(int numDays[])
{
	for (int i = 0; i < 3; ++i) {
		this->numDays[i] = numDays[i];
	}
}
void Student::print()
{
	cout << studentID << "\t";
	cout << firstName << "\t";
	cout << lastName << "\t";
	cout << email << "\t";
	cout << age << "\t";
	cout << numDays[0] << "\t";
	cout << numDays[1] << "\t";
	cout << numDays[2] << "\t";
}

Student::~Student()
{
	//Don't worry about this. 
}
