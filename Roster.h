#pragma once

#include "Student.h"
#include "Degree.h"
#include <iostream>
#include <string>

using namespace std;

class Roster
{
public:
	Roster(int numStudents);
	void parseAdd(string row);
	void add(string studentID, string firstName, string lastName, string email, int age, int day1, int day2, int day3, DEGREE_PROGRAM degreeProgram);
	void printAll();
	void averageDays();
	void printByDegree(int degreeProgram);
	void remove(string studentID);
	void printInvalidEmails();
	~Roster();
	int originalCapacity;	//original number of students
	int capacity;	//current number of students
	int index;	//position in roster
	Student** classRosterArray;
};

