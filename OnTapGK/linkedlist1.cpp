#include"linkedlist1.h"

using namespace std;

void StudentList::addStudent(Student* newStudent) {
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
void StudentList::sortByName() {
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
			while (temp2->next != NULL && temp->name > temp2->next->name) {
				temp2 = temp2->next;
			}
			temp->next = temp2->next;
			temp2->next = temp;
		}
		temp = nextNode;
	}
	head = sorted;
	cout << "Danh sach sau khi sap xep tang dan theo ten (name) la:\n";
}
void StudentList::readData() {
	fstream ifile;
	ifile.open("data.txt", ios::in);
	if (!ifile.is_open()) {
		cout << "Error! File is not found!";
		return;
	}
	string line;
	while (getline(ifile, line)) {
		char c;
		string name;
		int day, month, year, mathScore, literatureScore, englishScore;
		stringstream iss(line);
		iss >> name >> day >> c >> month >> c >> year >> mathScore >> literatureScore >> englishScore;
		Student* newStudent = new Student(name, day, month, year, mathScore, literatureScore, englishScore);
		addStudent(newStudent);

		cout << name << " " << day << "/" << month << "/" << year << " "
			<< mathScore << " " << literatureScore << " " << englishScore << endl;
	}
	ifile.close();
}
void StudentList::writeDataToFile(StudentList& studentlist) {
	fstream ofile;
	ofile.open("result.bin", ios::binary | ios::out);
	if (!ofile.is_open()) {
		cout << "Error! File is not found!";
		return;
	}
	Student* cur = studentlist.head;
	cout << "Danh sach sau khi loc la:\n";
	while (cur != NULL) {

		ofile.write((char*)cur, sizeof(Student));
		float average = (cur->mathScore + cur->literatureScore + cur->englishScore) / 3;

		if (average < 5) {
			/*ofile << cur->name << " " << cur->day << "/" << cur->month << "/" << cur->year << " "
				<< cur->mathScore << " " << cur->literatureScore << " " << cur->englishScore << endl;*/
			cout << cur->name << " " << cur->day << "/" << cur->month << "/" << cur->year << " "
				<< cur->mathScore << " " << cur->literatureScore << " " << cur->englishScore << endl;
		}
		cur = cur->next;

	}
	ofile.close();
}
void StudentList::readDataFromBin(StudentList& studentlist) {
	fstream ifile;
	ifile.open("result.bin", ios::binary | ios::in);
	if (!ifile.is_open()) {
		cout << "Error! File is not found!";
		return;
	}
	Student* cur = studentlist.head;
	cout << "Danh sach sau khi loc la:\n";
	while (ifile.read((char*)cur, sizeof(Student))) {

		float average = (cur->mathScore + cur->literatureScore + cur->englishScore) / 3;

		if (average < 5) {
			
			cout << cur->name << " " << cur->day << "/" << cur->month << "/" << cur->year << " "
				<< cur->mathScore << " " << cur->literatureScore << " " << cur->englishScore << endl;
		}
		cur = cur->next;

	}
	ifile.close();
}

void StudentList::printList() {
	Student* temp = head;
	while (temp != NULL) {
		cout << temp->name << " " << temp->day << "/" << temp->month << "/" << temp->year << " "
			<< temp->mathScore << " " << temp->literatureScore << " " << temp->englishScore << endl;
		temp = temp->next;
	}
}
void StudentList::deleteMemory() {
	Student* temp = head;
	while (temp != NULL) {
		Student* cur = temp->next;
		delete temp;
		temp = cur;
	}
	head = NULL;
	size = 0;
}