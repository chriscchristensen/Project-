#include "softwareStudent.h"



softwareStudent::softwareStudent()
{
	degreeStudy = SOFTWARE;
}

softwareStudent::softwareStudent(string studentID, string firstName, string lastName, string email, int age, int numDays[3], DegreeType type)
{
	degreeStudy = SOFTWARE;
}


softwareStudent::~softwareStudent()
{
}

DegreeType softwareStudent::getDegreeType()
{
	return DegreeType();
}

void softwareStudent::setDegreeType(DegreeType b)
{
	degreeStudy = SOFTWARE;
}

void softwareStudent::print()
{
	this->Student::print();
	std::cout << "Software";
}
