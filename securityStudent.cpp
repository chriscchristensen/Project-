#include "securityStudent.h"



securityStudent::securityStudent()
{
	degreeStudy = SECURITY;
}

securityStudent::securityStudent(string studentID, string firstName, string lastName, string email, int age, int numDays[3], DegreeType type)
{
	degreeStudy = SECURITY;
}


securityStudent::~securityStudent()
{
}

DegreeType securityStudent::getDegreeType()
{
	return DegreeType();
}

void securityStudent::setDegreeType(DegreeType b)
{
	degreeStudy = SECURITY;
}

void securityStudent::print()
{
	this->Student::print();
	std::cout << "Security";
}
