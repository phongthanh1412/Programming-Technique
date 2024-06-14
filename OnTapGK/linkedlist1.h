#pragma once

#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;

struct Student {

	string name;
	int day;
	int month;
	int year;
	int age;
	int mathScore;
	int literatureScore;
	int englishScore;
	int averageScore;
	Student* next;
	Student(string name, int day, int month, int year, int mathScore, int literatureScore, int englishScore) {
		this->name = name;
		this->day = day;
		this->month = month;
		this->year = year;
		this->mathScore = mathScore;
		this->literatureScore = literatureScore;
		this->englishScore = englishScore;
	}

};

struct StudentList {

	Student* head = NULL;
	int size = 0;

	void addStudent(Student* newStudent);

	void sortByName();

	void readData();

	void writeDataToFile(StudentList& studentlist);

	void readDataFromBin(StudentList& studentlist);

	void printList();

	void deleteMemory();

};