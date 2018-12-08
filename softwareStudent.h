#pragma once
#include "student.h"
class softwareStudent :public Student {



public:
	softwareStudent();
	softwareStudent(string studentID, string firstName, string lastName, string email, int age, int numDays[3], DegreeType type);
	~softwareStudent();
	DegreeType getDegreeType();
	void setDegreeType(DegreeType b);
	void print();
};
