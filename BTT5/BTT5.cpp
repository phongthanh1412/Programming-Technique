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
	void addStudent(Student* newStudent) {
		if (head == NULL) {
			head = newStudent;
		}
		else {
			Student* temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = newStudent;
		}
		newStudent->next = NULL;
		size++;
	}

	void readFileData() {
		ifstream ifile("data.txt");
		if (!ifile.is_open()) {
			cout << "Error! File is not found!\n";
			return;
		}

		string line;
		while (getline(ifile, line)) {
			stringstream iss(line);
			string name;
			char c;
			int day, month, year, mathScore, literatureScore, englishScore;

			iss >> name >> day >> c >> month >> c >> year >> mathScore >> literatureScore >> englishScore;

			cout << name << " " << day << "/" << month << "/" << year  << " " << mathScore << " " << literatureScore
				<< " " << englishScore << endl;

			Student* newStudent = new Student(name, day, month, year, mathScore, literatureScore, englishScore);
			addStudent(newStudent);
		}
		ifile.close();
	}

	void insertSortedByName(Student*& sorted, Student* newStudent) {
		if (sorted == NULL || sorted->name >= newStudent->name) {
			newStudent->next = sorted;
			sorted = newStudent;
		}
		else {
			Student* current = sorted;
			while (current->next != NULL && current->next->name < newStudent->name) {
				current = current->next;
			}
			newStudent->next = current->next;
			current->next = newStudent;
		}
	}
	void sortByName() {
		if (head == NULL || head->next == NULL) {
			return;
		}

		Student* sorted = NULL;
		Student* current = head;

		while (current != NULL) {
			Student* nextStudent = current->next;
			insertSortedByName(sorted, current);
			current = nextStudent;
		}

		head = sorted;
	}
	void writeResultToFile(StudentList& studentList) {
		ofstream ofile("result.txt");
		if (!ofile.is_open()) {
			cout << "Error! File is not found!\n";
			return;
		}

		Student* current = studentList.head;
		while (current != NULL) {
			float average = (current->mathScore + current->literatureScore + current->englishScore) / 3;
			if (average < 5) {
				ofile << current->name << " " << current->day << "/" << current->month << "/" << current->year << " "
					<< current->mathScore << " " << current->literatureScore << " " << current->englishScore << endl;
				cout << current->name << " " << current->day << "/" << current->month << "/" << current->year << " "
					<< current->mathScore << " " << current->literatureScore << " " << current->englishScore << endl;
			}
			current = current->next;
		}

		ofile.close();
	}

	void printList() {
		Student* current = head;
		while (current != NULL) {
			cout << current->name << " " << current->day << "/" << current->month << "/" << current->year
				 << " " << current->mathScore << " " << current->literatureScore << " " << current->englishScore << endl;
			current = current->next;
		}
		cout << endl;
	}
	void deleteMemory() {
		Student* current = head;
		while (current != NULL) {
			Student* nextStudent = current->next;
			delete current;
			current = nextStudent;
		}
		head = NULL;
		size = 0;
	}
};

int main() {
	StudentList mystudent;
	fstream ifile;
	mystudent.readFileData();
	mystudent.sortByName();
	cout << "Danh sach sau khi sap xep tang dan theo ten (name) la: \n";
	mystudent.printList();
	mystudent.writeResultToFile(mystudent);
	mystudent.deleteMemory();
	return 0;
}