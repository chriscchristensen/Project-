#include "networkStudent.h"



networkStudent::networkStudent()
{
	degreeStudy = NETWORKING;
}

networkStudent::networkStudent(string studentID, string firstName, string lastName, string email, int age, int numDays[3], DegreeType type)
{
	degreeStudy = NETWORKING;
}


networkStudent::~networkStudent()
{
}

DegreeType networkStudent::getDegreeType()
{
	return DegreeType();
}

void networkStudent::setDegreeType(DegreeType b)
{
	degreeStudy = NETWORKING;
}

void networkStudent::print()
{
	this->Student::print();
	std::cout << "Networking";
}
