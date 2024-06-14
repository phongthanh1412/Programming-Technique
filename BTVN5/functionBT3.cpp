#include"functionBT3.h"

using namespace std;

Student::Student(string name, string gender, int day, int month, int year, int mathScore, int literatureScore, int englishScore) {
    this->name = name;
    this->gender = gender;
    this->day = day;
    this->month = month;
    this->year = year;
    this->mathScore = mathScore;
    this->literatureScore = literatureScore;
    this->englishScore = englishScore;
}

void StudentList::addStudent(Student* newStudent) {
	if (ll2 == NULL) {
		ll2 = newStudent;
	}
	else {
		Student* temp = ll2;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newStudent;
	}
	newStudent->next = NULL;
	size++;
}
void StudentList::readFileData() {
	ifstream ifile("data2.txt");
	if (!ifile.is_open()) {
		cout << "Error! File is not found!\n";
		return;
	}

	string line;
	while (getline(ifile, line)) {
		stringstream iss(line);
		string name, gender;
		char c;
		int day, month, year, mathScore, literatureScore, englishScore;

		iss >> name >> gender >> day >> c >> month >> c >> year >> mathScore >> literatureScore >> englishScore;

		cout << name << " " << gender << " " << day << "/" << month << "/" << year << " " << mathScore << " " << literatureScore
			<< " " << englishScore << endl;

		float average = (float)(mathScore + literatureScore + englishScore) / 3;
		average = (int)(average * 4 + 0.5);
		average /= 4;

		Student* newStudent = new Student(name, gender, day, month, year, mathScore, literatureScore, englishScore);
		newStudent->averageScore = average;
		addStudent(newStudent);

	}
	ifile.close();
}

void StudentList::findAgeAndGrade(StudentList& studentList) {

	Student* current = studentList.ll2;
	while (current != NULL) {
		int age = 2024 - current->year;
		float average = (float)(current->mathScore + current->literatureScore + current->englishScore) / 3;
		average = (int)(average * 4 + 0.5);
		average /= 4;


		cout << "Sinh vien " << current->name << " co tuoi la " << age << " va "
			<< "diem trung binh la " << average << endl;

		current = current->next;
	}
}

void StudentList::insertSortedByName() {
	if (ll2 == NULL || ll2->next == NULL) {
		return;
	}
	Student* sorted = NULL;
	Student* cur = ll2;
	while (cur != NULL) {
		Student* next = cur->next;
		if (sorted == NULL || cur->name <= sorted->name) {
			cur->next = sorted;
			sorted = cur;
		}
		else {
			Student* temp = sorted;
			while (temp->next != NULL && temp->next->name < cur->name) {
				temp = temp->next;
			}
			cur->next = temp->next;
			temp->next = cur;
		}
		cur = next;
	}
	ll2 = sorted;
}
void StudentList::insertSortedByAverage() {
	if (ll2 == NULL || ll2->next == NULL) {
		return;
	}
	Student* sorted = NULL;
	Student* cur = ll2;
	while (cur != NULL) {
		Student* next = cur->next;
		if (sorted == NULL || cur->averageScore <= sorted->averageScore) {
			cur->next = sorted;
			sorted = cur;
		}
		else {
			Student* temp = sorted;
			while (temp->next != NULL && temp->next->averageScore < cur->averageScore) {
				temp = temp->next;
			}
			cur->next = temp->next;
			temp->next = cur;
		}
		cur = next;
	}
	ll2 = sorted;
}

void StudentList::findStudent(StudentList& studentlist) {
	StudentList filterList;
	Student* temp = studentlist.ll2;
	while (temp != NULL) {
		if (temp->averageScore > 8 && temp->mathScore > 7 && temp->literatureScore > 7 && temp->englishScore > 7) {
			Student* ll2 = new Student(temp->name, temp->gender, temp->day, temp->month, temp->year,
				temp->mathScore, temp->literatureScore, temp->englishScore);
			filterList.addStudent(ll2);
		}
		temp = temp->next;
	}
	studentlist.ll2 = filterList.ll2;
}

void StudentList::printList() {
	Student* current = ll2;
	while (current != NULL) {
		cout << current->name << " " << current->gender << " " << current->day << "/" << current->month << "/" << current->year
			<< " " << current->mathScore << " " << current->literatureScore << " " << current->englishScore << endl;
		current = current->next;
	}
	cout << endl;
}
void StudentList::deleteMemory() {
	Student* current = ll2;
	while (current != NULL) {
		Student* nextStudent = current->next;
		delete current;
		current = nextStudent;
	}
	ll2 = NULL;
	size = 0;
}