#pragma once
#include "student.h"
#include <string>
#include <iostream>

using std::string;

const int numStudents = 5;

string studentData[numStudents]{
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Chris,Christensen,cchri117@wgu.edu,31,30,12,15, SOFTWARE"
};
class roster
{
public:
	int lastIndex;
	int capacity;
	Student** classRosterArray;
	roster();
	roster(int capacity);
	void parseAdd(string datarow);
	void print_All();
	bool remove(string studentID);
	void add(string studenID, string firstName, string lastName, string email, int age, int d1,int d2, int d3, DegreeType type);
	~roster();
};

