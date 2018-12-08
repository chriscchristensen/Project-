#pragma once
#include "student.h"
class securityStudent :public Student {



	public:
		securityStudent();
		securityStudent(string studentID, string firstName, string lastName, string email, int age, int numDays[3], DegreeType type);
		~securityStudent();
		DegreeType getDegreeType();
		void setDegreeType(DegreeType b);
		void print();
};

