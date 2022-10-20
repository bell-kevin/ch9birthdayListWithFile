// ch9birthdayListWithFile.cpp : This file contains the 'main' function.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

//3 string variables, "firstName", "lastName", and "birthday"
class BirthdayPerson
{
public:
	string firstName;
	string lastName;
	string birthday;
};

//function prototypes
void displayData(BirthdayPerson[], int);
void sortDataByLastName(BirthdayPerson[], int);
void sortDataByBirthday(BirthdayPerson[], int);
void readData(BirthdayPerson[], int);

BirthdayPerson birthdayList[10];
ifstream inputFile;
ofstream outputFile;
int main()
{
	cout << "Chapter 9 Birthday Lists with a File by Kevin Bell\n\n";
	// 10-element array of class objects
	// read in the data from a file	
	readData(birthdayList, 10);
	// display the data in the array
	displayData(birthdayList, 10);
	cout << endl;
	// sort the data in the array by last name
	sortDataByLastName(birthdayList, 10);
	cout << "Sorted list by last name\n";
	// display the data in the array
	displayData(birthdayList, 10);
	cout << endl;
	// sort the data in the array by birthday in ascending order
	sortDataByBirthday(birthdayList, 10);
	cout << "Sorted list by birthday\n";
	// display the data in the array
	displayData(birthdayList, 10);
	cout << endl;
	// close the file
	inputFile.close();
	system("pause");
	return 0;
} // end main

// 4 functions

// function 1
// function read in the data from a file and store it in the array
void readData(BirthdayPerson[], int)
{
	// read in the data from a file	
	inputFile.open("birthdays.txt");
	// check if file opened successfully
	if (inputFile.fail())
	{
		cout << "Error opening file. Program terminating \n";
		exit(1);
	}
	else {
		cout << "Original list\n";
	} // end else

	// store the data in the array
	for (int i = 0; i < 10; i++)
	{
		inputFile >> birthdayList[i].firstName;
		inputFile >> birthdayList[i].lastName;
		inputFile >> birthdayList[i].birthday;
	} // end for
} // end readData
	
	
// function 2
// sort the data in the array by last name in ascending order
void sortDataByLastName(BirthdayPerson birthdayList[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (birthdayList[i].lastName > birthdayList[j].lastName)
			{
				BirthdayPerson temp = birthdayList[i];
				birthdayList[i] = birthdayList[j];
				birthdayList[j] = temp;
			} // end if
		} // end for
	} // end for
} // end sortDataByLastName

// function 3
// sort the data in the array by birthday in ascending order
void sortDataByBirthday(BirthdayPerson birthdayList[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (birthdayList[i].birthday > birthdayList[j].birthday)
			{
				BirthdayPerson temp = birthdayList[i];
				birthdayList[i] = birthdayList[j];
				birthdayList[j] = temp;
			} // end if
		} // end for
	} // end for
} // end sortDataByBirthday


// function 4
// display the data in the array
void displayData(BirthdayPerson birthdayList[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << setw(10) << left << birthdayList[i].firstName;
		cout << setw(10) << left << birthdayList[i].lastName;
		cout << setw(10) << left << birthdayList[i].birthday << endl;
	} // end for
} // end displayData
