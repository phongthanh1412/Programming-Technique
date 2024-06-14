#pragma once

#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;

struct Student {
    string name;
    string gender;
    int day;
    int month;
    int year;
    int age;
    int mathScore;
    int literatureScore;
    int englishScore;
    float averageScore;
    Student* next;

    Student(string name, string gender, int day, int month, int year, int mathScore, int literatureScore, int englishScore);
};

struct StudentList {
    Student* ll2 = NULL;
    int size = 0;

    void addStudent(Student* newStudent);

    void readFileData();

    void findAgeAndGrade(StudentList& studentList);

    void insertSortedByName();

    void insertSortedByAverage();

    void findStudent(StudentList& studentlist);

    void printList();

    void deleteMemory();
};
