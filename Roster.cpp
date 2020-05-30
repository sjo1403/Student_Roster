#include "Roster.h"
#include "Student.h"
#include "Degree.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

Roster::Roster(int numStudents)
{
	index = 0;
	originalCapacity = numStudents;
	capacity = numStudents;
	this->classRosterArray = new Student*[capacity];
}

void Roster::parseAdd(string row)
{
		int rhs = row.find(",");	//		set ID			//
		string studentID = row.substr(0, rhs);


		int lhs = rhs + 1;	//		set first name		//
		rhs = row.find(",", lhs);
		string firstName = row.substr(lhs, rhs - lhs);


		lhs = rhs + 1;	//		set last name		//
		rhs = row.find(",", lhs);
		string lastName = row.substr(lhs, rhs - lhs);


		lhs = rhs + 1;	//		set email		//
		rhs = row.find(",", lhs);
		string email = row.substr(lhs, rhs - lhs);


		lhs = rhs + 1;	//		set age		//
		rhs = row.find(",", lhs);
		string ageString = row.substr(lhs, rhs - lhs);
		int age = std::stoi(ageString);


		lhs = rhs + 1;	//		set completionDays[0]		//
		rhs = row.find(",", lhs);
		string day1String = row.substr(lhs, rhs - lhs);
		int day1 = std::stoi(day1String);
		

		lhs = rhs + 1;	//		set completionDays[1]		//
		rhs = row.find(",", lhs);
		string day2String = row.substr(lhs, rhs - lhs);
		int day2 = std::stoi(day2String);

		lhs = rhs + 1;	//		set completionDays[2]		//
		rhs = row.find(",", lhs);
		string day3String = row.substr(lhs, rhs - lhs);
		int day3 = std::stoi(day3String);


		DEGREE_PROGRAM degreeProgram;	//		set degree program		//
		lhs = rhs + 1;
		rhs = row.find(",", lhs);

		if (row.substr(lhs, rhs - lhs) == "SECURITY")
			degreeProgram = SECURITY;

		else if (row.substr(lhs, rhs - lhs) == "NETWORK")
			degreeProgram = NETWORK;

		else
			degreeProgram = SOFTWARE;

		add(studentID, firstName, lastName, email, age, day1, day2, day3, degreeProgram);

		index++;
}

void Roster::add(string studentID, string firstName, string lastName, string email, int age, int day1, int day2, int day3, DEGREE_PROGRAM degreeProgram)
{
		Student* ptrStudent = new Student;
		ptrStudent->setStudentID(studentID);
		ptrStudent->setFirstName(firstName);
		ptrStudent->setLastName(lastName);
		ptrStudent->setEmail(email);
		ptrStudent->setAge(age);
		ptrStudent->setCompletionDays(day1, day2, day3);
		ptrStudent->setDegreeProgram(degreeProgram);

		classRosterArray[index] = ptrStudent;
}

void Roster::printAll()
{
	cout << "Printing all students..." << endl;

	for (int i = 0; i < capacity; i++)
		classRosterArray[i]->print();
}

void Roster::averageDays()
{
	cout << "\nPrinting average days to completion..." << endl;

	for (int i = 0; i < capacity; i++)
	{
		int sum = 0;
		int classes = 3;
		int* daysToComplete = classRosterArray[i]->getCompletionDays();
		string stuID = this->classRosterArray[i]->getStudentID();

		for (int j = 0; j < 3; j++)
			sum += daysToComplete[j];

		cout << "Average course completion time for student " << stuID << " is " << sum / classes << " days." << endl;
	}
		
}

void Roster::printByDegree(int degreeProgram)
{
	cout << "\nPrinting " << degreeString[degreeProgram] << " students..." << endl;	
	for (int i = 0; i < capacity; i++)
	{
		if(this->classRosterArray[i]->getDegreeProgram() == degreeProgram)
		{
			classRosterArray[i]->print();
		}
		
		else
			continue;
	}	
	cout << "\n";
}

void Roster::remove(string studentID)
{
	int IDReturns = 0;	//		if IDreturns is equal to 0, student ID does not exist		//

	for (int i = 0; i < capacity; i++)
	{
		string stuID = classRosterArray[i]->getStudentID();

		if (stuID.find(studentID) != string::npos)

		{
			int maxIndex = capacity - 1;	//		shift elements of array to the left		//
			for (int j = i; j < maxIndex; j++)
			{
				classRosterArray[j] = classRosterArray[j + 1];
			}
			capacity--;

			IDReturns++;
		}

	}
	if (IDReturns == 0)
		cout << "\nError: Student " << studentID << " not found." << endl;
}

void Roster::printInvalidEmails()
{
	cout << "\nPrinting invalid emails..." << endl;
	for (int i = 0; i < capacity; i++)
	{
		string stuEmail = classRosterArray[i]->getEmail();

		if (stuEmail.find(" ") != string::npos)
			cout << stuEmail << " is invalid. Email addresses may not contain spaces." << endl;

		if (stuEmail.find(".") == string::npos)
			cout << stuEmail << " is invalid. Email addresses must contain '.'." << endl;

		if (stuEmail.find("@") == string::npos)
			cout << stuEmail << " is invalid. Email addresses must contain '@'." << endl;
	}
}

Roster::~Roster()
{
	for (int i = 0; i < originalCapacity; i++)
		delete classRosterArray[i];
	
	for (int i = 0; i < originalCapacity; i++)
		classRosterArray[i] = nullptr;
}
