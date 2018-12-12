#include "roster.h"
#include <iostream>
#include "student.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "networkStudent.h"
#include "degree.h"

using std::cout;
using std::cerr;
using std::swap;

roster::roster()
{
	this->capacity = 0;
	this->lastIndex = -1;
	this->classRosterArray = nullptr;
}

roster::roster(int capacity)
{
	this->capacity = capacity;
	this->lastIndex = -1;
	this->classRosterArray = new Student*[capacity];
}

void roster::parseAdd(string datarow)
{
	if (lastIndex < capacity) {
		lastIndex++;
		if (datarow[datarow.length()-1] == 'Y') {
			this->classRosterArray[lastIndex] = new securityStudent();
			classRosterArray[lastIndex]->setDegreeType(SECURITY);
		}
		else if (datarow[datarow.length() - 1] == 'E') {
			this->classRosterArray[lastIndex] = new softwareStudent();
			classRosterArray[lastIndex]->setDegreeType(SOFTWARE);
		}
		else if (datarow[datarow.length() - 1] == 'K') {
			this->classRosterArray[lastIndex] = new networkStudent();
			classRosterArray[lastIndex]->setDegreeType(NETWORKING);
		}
		else {
			cerr << "Invalid Degree Type! Exiting Now.\n";
			exit(-1);
		}
		int rhs = studentData[lastIndex].find(",");
		string id = studentData[lastIndex].substr(0, rhs);
		int lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		string fName = studentData[lastIndex].substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		string lName = studentData[lastIndex].substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		string eMail = studentData[lastIndex].substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		int age = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		int days1 = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		int days2 = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		int days3 = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

		add(id, fName, lName, eMail, age, days1, days2, days3, classRosterArray[lastIndex]->getDegreeType());
	}
}

void roster::print_All()
{
	for (int i = 0; i <= this->lastIndex; i++) (this->classRosterArray)[i]->print();
	cout << endl;
}

void roster::remove(string studentID)
{
	cout << "Deleting student ID: " << studentID << endl;
	for (int i = 0; i < numStudents; ++i) {
		if (studentID == classRosterArray[i]->getstudentID())
		{
			delete (classRosterArray[i]);
			classRosterArray[i] = classRosterArray[lastIndex];
			lastIndex--;
			cout << endl;
			for (int i = 0; i <= this->lastIndex; i++) (this->classRosterArray)[i]->print();
			break;
		}
		else {
			cout << "Student not found. " << endl;
			break;
		}
	}
}

void roster::add(string studenID, string firstName, string lastName, string email, int age, int d1, int d2, int d3, DegreeType type)
{
	classRosterArray[lastIndex]->setstudentID(studenID);
	classRosterArray[lastIndex]->setfirstName(firstName);
	classRosterArray[lastIndex]->setlastName(lastName);
	classRosterArray[lastIndex]->setemail(email);
	classRosterArray[lastIndex]->setage(age);
	int days[3];
	days[0] = d1;
	days[1] = d2;
	days[2] = d3;
	classRosterArray[lastIndex]->setNumDays(days);
}

void roster::printInvalidEmail()
{
	for (int i = 0; i < numStudents; ++i) {
		string email = classRosterArray[i]->getemail();
		if (email.find('@') == -1 || email.find('.') == -1 || email.find(' ') != -1)
		{
			cout << "Invalid Email\t" << email << endl;
		}
	}
	cout << endl;
}

void roster::printDaysInCourse(string studentID)
{
	for (int i = 0; i < numStudents; ++i) {
		if (studentID == classRosterArray[i]->getstudentID())
		{
			int* numDays = classRosterArray[i]->getNumDays();
			cout << studentID << "\t" << (numDays[0] + numDays[1] + numDays[2]) / 3 << endl;
		}
	}
}

void roster::printByDegreeProgram(int DegreeType)
{
	cout << endl;
	for (int i = 0; i < numStudents; ++i) {
		int currentDegree = classRosterArray[i]->getDegreeType();
		if (DegreeType == currentDegree) {
			classRosterArray[i]->print();
		}
	}
	cout << endl;
}


roster::~roster()
{

}

int main() {
	cout << "Scripting and Programming - Applications - C867. Language used is C++. My student ID is 000791308. My name is Chris Christensen \n";
	roster *ros = new roster(5);
	for (int i = 0; i < ros->capacity; ++i) {
		ros->parseAdd(studentData[i]);
	}
	ros->print_All();
	ros->printInvalidEmail();
	for (int i = 0; i < ros->capacity; ++i) {
		ros->printDaysInCourse(ros->classRosterArray[i]->getstudentID());
	}
	ros->printByDegreeProgram(SOFTWARE);
	ros->remove("A1");
	ros->remove("A1");
	system("pause");
	return 0;
}
