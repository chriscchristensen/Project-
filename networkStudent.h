#pragma once
#include "student.h"
class networkStudent :public Student {



public:
	networkStudent();
	networkStudent(string studentID, string firstName, string lastName, string email, int age, int numDays[3], DegreeType type);
	~networkStudent();
	DegreeType getDegreeType();
	void setDegreeType(DegreeType b);
	void print();
};
	

