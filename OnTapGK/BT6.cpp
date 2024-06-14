#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;

struct Student {

	string name;
	string gender;
	int date;
	int month;
	int year;
	int age;
	int mathScore;
	int literatureScore;
	int englishScore;
	float averageScore;
	Student* next;
	Student(string name, string gender, int date, int month, int year, int mathScore, int literatureScore, int englishScore) {
		this->name = name;
		this->gender = gender;
		this->date = date;
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
			size++;
		}
		else {
			Student* temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			newStudent->next = temp->next;
			temp->next = newStudent;
		}
		newStudent->next = NULL;
		size++;
	}
	void findAgeAndGrade(StudentList& studentlist) {
		Student* temp = studentlist.head;
		while (temp != NULL) {
			int age = 2024 - temp->year;
			float average = (float)(temp->mathScore + temp->literatureScore + temp->englishScore) / 3;
			average = (int)(average * 4 + 0.5);
			average /= 4;
			cout << "Sinh vien " << temp->name << " co tuoi la " << age
				<< " va co diem trung binh la " << average << endl;
			temp->averageScore = average;
			temp = temp->next;
		}
	}
	void sortByName() {
		if (head == NULL || head->next == NULL)
			return;
		Student* temp = head;
		Student* sorted = NULL;
		while (temp != NULL) {
			Student* nextNode = temp->next;
			if (sorted == NULL || temp->name <= sorted->name) {
				temp->next = sorted;
				sorted = temp;
			}
			else {
				Student* temp2 = sorted;
				while (temp2->next != NULL && temp->name > temp2->next->name)
					temp2 = temp2->next;
				temp->next = temp2->next;
				temp2->next = temp;

			}
			temp = nextNode;
		}
		head = sorted;
		cout << "Danh sach sau khi sap xep tang dan theo ten (name) la:\n";
	}
	void sortByAverage() {
		if (head == NULL || head->next == NULL)
			return;
		Student* temp = head;
		Student* sorted = NULL;
		while (temp != NULL) {
			Student* nextNode = temp->next;
			if (sorted == NULL || temp->averageScore <= sorted->averageScore) {
				temp->next = sorted;
				sorted = temp;
			}
			else {
				Student* temp2 = sorted;
				while (temp2->next != NULL && temp->averageScore > temp2->next->averageScore)
					temp2 = temp2->next;
				temp->next = temp2->next;
				temp2->next = temp;

			}
			temp = nextNode;
		}
		head = sorted;
		cout << "Danh sach sau khi sap xep tang dan theo diem trung binh (average) la:\n";
	}

	void readData() {
		fstream ifile;
		ifile.open("data2.txt", ios::in);
		if (ifile.eof()) {
			cout << "Error! File is not found!";
			return;
		}
		string line;
		while (getline(ifile, line)) {
			char c;
			string name, gender;
			int  date, month, year, mathScore, literatureScore, englishScore;
			stringstream iss(line);
			iss >> name >> gender >> date >> c >> month >> c >> year >> mathScore >> literatureScore >> englishScore;
			Student* newStudent = new Student(name, gender, date, month, year, mathScore, literatureScore, englishScore);
			addStudent(newStudent);
			
		}
	}
	void filterStudentList(StudentList& studentlist) {
		StudentList filterList;
		Student* temp = studentlist.head;
		while (temp != NULL) {
			if (temp->averageScore > 8 && temp->mathScore > 7 && temp->literatureScore > 7 && temp->englishScore > 7) {
				Student* ll2 = new Student(temp->name, temp->gender, temp->date, temp->month, temp->year,
					temp->mathScore, temp->literatureScore, temp->englishScore);
				filterList.addStudent(ll2);
			}
			temp = temp->next;
		}
		studentlist.head = filterList.head;
		cout << "Danh sach sau khi loc la:\n";
	}
	void printList() {
		Student* temp = head;
		while (temp != NULL) {
			cout << temp->name << " " << temp->gender << " " << temp->date << "/" << temp->month << "/" << temp->year << " " <<
				temp->mathScore << " " << temp->literatureScore << " " << temp->englishScore << endl;
			temp = temp->next;
		}
		cout << endl;
	}
	void deleteMemory() {
		Student* temp = head;
		while (temp != NULL) {
			Student* cur = temp->next;
			delete temp;
			temp = cur;
		}
		head = NULL;
		size = 0;
	}
};
int main() {
	StudentList myStudent;
	myStudent.readData();
	myStudent.printList();
	myStudent.findAgeAndGrade(myStudent);
	myStudent.sortByName();
	myStudent.printList();
	myStudent.sortByAverage();
	myStudent.printList();
	myStudent.filterStudentList(myStudent);
	myStudent.printList();

	myStudent.deleteMemory();
	return 0;
}