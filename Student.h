#pragma once
#include <string>
#include "Degree.h"

using namespace std;

class Student
{
public:
	Student();
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setAge(int age);
	void setCompletionDays(int day1, int day2, int day3);
	void setDegreeProgram(int degreeProgram);
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getCompletionDays();
	int getDegreeProgram ();
	void print();

private:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int* completionDays;
	int degreeProgram;
};

