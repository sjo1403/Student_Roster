#include "Student.h"
#include "Degree.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = 0;
	this->completionDays = new int[3];
	for (int i = 0; i < 3; i++) 
		completionDays[i] = 0;
	this->degreeProgram = -1;
}

void Student::setStudentID(string studentID)
{
	this->studentID = studentID;
}

void Student::setFirstName(string firstName)
{
	this->firstName = firstName;
}

void Student::setLastName(string lastName)
{
	this->lastName = lastName;
}

void Student::setEmail(string email)
{
	this->email = email;
}

void Student::setAge(int age)
{
	this->age = age;
}

void Student::setCompletionDays(int day1, int day2, int day3)
{
	this->completionDays = new int [3];
	completionDays[0] = { day1 };
	completionDays[1] = { day2 };
	completionDays[2] = { day3 };
}

void Student::setDegreeProgram(int degreeProgram)
{
	this->degreeProgram = degreeProgram;
}

string Student::getStudentID()
{
	return studentID;
}

string Student::getFirstName()
{
	return firstName;
}

string Student::getLastName()
{
	return lastName;
}

string Student::getEmail()
{
	return email;
}

int Student::getAge()
{
	return age;
}

int* Student::getCompletionDays()
{
	return completionDays;
}

int Student::getDegreeProgram()
{
	return degreeProgram;
}

void Student::print()
{
	cout << left << setw(5) << studentID;
	cout << "First name: " << left << setw(10) << firstName;
	cout << "Last name: " << left << setw(10) << lastName;
	cout << "Email: " << left << setw(25) << email;
	cout << "Age: " << left << setw(5) << age;
	cout << "Days in course: ";
	for (int i = 0; i < 3; i++)
		cout << left << setw(5) << completionDays[i];
	cout << "Degree program: " << left << setw(10) << degreeString[degreeProgram];
	cout << "\n";
}
