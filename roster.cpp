#include "roster.h"
#include "student.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "networkStudent.h"
#include "degree.h"

using std::cout;
using std::cerr;

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
			cerr << "Invalid Book Type! Exiting Now.\n";
			exit(-1);
		}
		int rhs = studentData[lastIndex].find(",");
		//classRosterArray[lastIndex]->setstudentID(studentData[lastIndex].substr(0, rhs));
		string id = studentData[lastIndex].substr(0, rhs);
		int lhs = rhs + 1;
		int rhs = studentData[lastIndex].find(",", lhs);
		string fName = studentData[lastIndex].substr(lhs, rhs);

		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		string lName = studentData[lastIndex].substr(lhs, rhs);

		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		string eMail = studentData[lastIndex].substr(lhs, rhs);

		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		int age = stoi(studentData[lastIndex].substr(lhs, rhs));

		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		int days1 = stoi(studentData[lastIndex].substr(lhs, rhs));

		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		int days2 = stoi(studentData[lastIndex].substr(lhs, rhs));

		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		int days3 = stoi(studentData[lastIndex].substr(lhs, rhs));

		add(id, fName, lName, eMail, age, days1, days2, days3, classRosterArray[lastIndex]->getDegreeType());
	}
}

void roster::remove(string studentID)
{
	string ID;
	cout << "Enter the student ID you wish to delete: " << endl;
	cin >> ID;
	for (int i = 0; i < numStudents; ++i) {
		if (studentData[i] == ID) {
			swap(studentData[i], studentData[numStudents - 1]);
			
		}
		else {
			cout << "Such a student with this ID was not found.";
		}
	}
}

bool roster::remove(string studentID)
{
	return false;
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


roster::~roster()
{
}

int main() {
	return 0;
}
