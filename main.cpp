#include <iostream>
#include <string>
#include "Roster.h"

using namespace std;

int main()
{
	cout << "C867: Scripting & Programming Applications, C++" << endl;
	cout << "Shantel Johnson, 001344693\n" << endl;

	const int NumStudents = 5;

	const string studentData[NumStudents] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
		"A5,Shantel,Johnson,sjo1403@wgu.edu,24,28,30,32,SOFTWARE" };

	Roster* classRoster = new Roster(NumStudents);

	for (int i = 0; i < NumStudents; i++)
		classRoster->parseAdd(studentData[i]);

	classRoster->printAll();

	classRoster->printInvalidEmails();

	classRoster->averageDays();

	classRoster->printByDegree(SOFTWARE);

	classRoster->remove("A3");

	classRoster->printAll();

	classRoster->remove("A3");

	return 0;
}
