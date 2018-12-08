#pragma once

#include <iostream>
#include <string>
#include "degree.h"
#include <array>
using std::string;

class Student
{
protected:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int numDays[3];
	DegreeType degreeStudy;
public:
	Student();
	Student(string studentID, string firstName, string lastName, string email, int age, int numDays[3], DegreeType type);
	string getstudentID();
	string getFirstName();
	string getlastName();
	string getemail();
	int getage();
	int* getNumDays();
	virtual DegreeType getDegreeType() = 0;


	void setstudentID(string studentID);
	void setfirstName(string firstName);
	void setlastName(string lastName);
	void setemail(string email);
	void setage(int age);
	void setNumDays(int numDays[]);
	virtual void setDegreeType(DegreeType b) = 0;
	virtual void print() = 0;
	~Student();
};
