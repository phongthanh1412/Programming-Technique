#include<iostream>
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
	int averageScore;
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

	void scanStudent(Student* head) {
		Student* cur = head;
		if (cur == NULL)
			return;
		cout << cur->name << " " << cur->gender << " " << cur->date << "/" << cur->month << "/" << cur->year
			<< " " << cur->mathScore << " " << cur->literatureScore << " " << cur->englishScore << endl;
		scanStudent(cur->next);
	}

	void release() {
		Student* temp = head;
		while (temp != NULL) {
			Student* cur = temp;
			delete cur;
			temp = temp->next;
		}
		head = NULL;
		size = 0;
	}

};

void createListStudent(string filename, StudentList& list) {
	fstream ifile;
	ifile.open(filename, ios::in);
	if (ifile.eof()) {
		cout << "Error! File is not found!";
		return;
	}

	char c;
	string line, name, gender;
	int date, month, year, mathScore, literatureScore, englishScore;

	while (getline(ifile, line)) {
		stringstream iss(line);
		iss >> name >> gender >> date >> c >> month >> c >> year >> mathScore >> literatureScore >> englishScore;

		Student* newStudent = new Student(name, gender, date, month, year, mathScore, literatureScore, englishScore);
		list.addStudent(newStudent);
	}
	ifile.close();
}

void createArray1D(int*& A, int& sizeOfArray, StudentList& list) {
	sizeOfArray = list.size;
	A = new int[sizeOfArray];
	Student* temp = list.head;
	int i = 0;
	while (temp != NULL && i < sizeOfArray) {
		A[i] = temp->mathScore + temp->literatureScore + temp->englishScore;
		i++;
		temp = temp->next;
	}
}

void printArr(int* A, int idx, int sizeOfArray, StudentList& list) {
	sizeOfArray = list.size;
	if (idx >= sizeOfArray)
		return;
	cout << A[idx] << " ";
	return printArr(A, idx + 1, sizeOfArray, list);
}

int findMax(int* A, int idx, int sizeOfArray, int maxi) {
	if (sizeOfArray == 1)
		return maxi;
	if (idx >= sizeOfArray)
		return maxi;
	if (A[idx + 1] > maxi)
		maxi = A[idx + 1];
	return findMax(A, idx + 1, sizeOfArray, maxi);
}

void releaseArray(int* A) {
	delete[]A;
}

int main() {
	int* A = NULL;
	int sizeOfArray = 0;
	StudentList list;
	createListStudent("data.txt", list);
	cout << "Danh sach cac sinh vien la: \n";
	list.scanStudent(list.head);
	cout << endl;

	createArray1D(A, sizeOfArray, list);
	cout << "Mang A gom cac diem sinh vien la: ";
	printArr(A, 0, sizeOfArray, list);
	cout << endl;

	int maxi = A[0];
	cout << "Diem lon nhat trong mang A la: ";
	cout << findMax(A, 0, sizeOfArray, maxi);
	cout << endl;

	releaseArray(A);
	list.release();
	return 0;
}