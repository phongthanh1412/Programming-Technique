#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct Node {
	int stuID; //mã số sinh viên
	double average; //điểm trung bình
	Node* next;
};

struct List {
	Node* head;
};

void init(List& l) {
	l.head = NULL;
}

Node* createNode(double val, int stuID) {
	Node* newNode = new Node;
	newNode->stuID = stuID;
	newNode->average = val;
	newNode->next = NULL;
	return newNode;
}

void addTail(List& l, Node* newNode) {
	if (l.head == NULL) {
		l.head = newNode;
		return;
	}
	else {
		Node* temp = l.head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		newNode->next = temp->next;
		temp->next = newNode;
		newNode->next = NULL;
	}
}
void readStudents(string fileName, List& list) {
	fstream ifile;
	ifile.open(fileName, ios::in);
	if (ifile.eof()) {
		cout << "File is not found!";
		return;
	}
	int stuID;
	double average;
	while (!ifile.eof()) {
		ifile >> stuID;
		ifile.seekg(1, 1);
		ifile >> average;
		Node* newNode = createNode(average, stuID);
		addTail(list, newNode);
	}
	ifile.close();
}
int count(List list) {
	Node* temp = list.head;
	int cnt = 0;
	while (temp != NULL && temp->next != NULL) {
		if (temp->average == temp->next->average)
			cnt++;
		temp = temp->next;
	}
	return cnt;
}
void writeFailedStudents(List list) {
	fstream ofile;
	ofile.open("result.bin", ios::out | ios::binary);
	if (ofile.eof()) {
		cout << "File is not found!";
		return;
	}
	Node* temp = list.head;
	while (temp != NULL) {
		if (temp->average < 5) {
			ofile.write((char*)&temp->stuID, sizeof(temp->stuID));
			ofile.write((char*)&temp->average, sizeof(temp->average));
		}
		temp = temp->next;
	}
	ofile.close();
}
void readFailedStudents(List& list1) {
	fstream ifile;
	ifile.open("result.bin", ios::in | ios::binary);
	if (!ifile.is_open()) {
		cout << "File could not be opened!" << endl;
		return;
	}

	int stuID;
	double average;

	// Đọc dữ liệu lần đầu tiên trước khi vào vòng lặp
	ifile.read((char*)&stuID, sizeof(stuID));
	ifile.read((char*)&average, sizeof(average));

	while (!ifile.eof()) {
		Node* newNode = createNode(average, stuID);
		addTail(list1, newNode);

		// Đọc dữ liệu cho lần tiếp theo
		ifile.read((char*)&stuID, sizeof(stuID));
		ifile.read((char*)&average, sizeof(average));
	}

	ifile.close();
}

void show(List l) {
	Node* temp = l.head;
	while (temp != NULL) {
		cout << temp->stuID << " " << temp->average << endl;
		temp = temp->next;
	}
}

void release(List& l) {
	Node* temp = l.head;
	while (temp != NULL) {
		Node* cur = temp;
		temp = temp->next;
		delete cur;
	}
	l.head = NULL;
}
int main() {
	string fileName = "data.txt";
	List list, list1;
	init(list);
	readStudents(fileName, list);
	cout << "So sinh vien ban dau: \n";
	show(list);
	cout << "So luong sinh vien co diem tb bang diem tb sinh vien phia sau: ";
	cout << count(list);
	cout << endl;
	writeFailedStudents(list);

	init(list1);
	readFailedStudents(list1);
	cout << "So sinh vien co diem tb nho hon 5: \n";
	show(list1);

	release(list1);
	release(list);
	return 0;
}