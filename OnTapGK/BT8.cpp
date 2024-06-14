#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;
struct Node {
	int stuID;
	double average;
	Node* next;

	Node(int stuID, double average) {
		this->stuID = stuID;
		this->average = average;
		this->next = NULL;
	}
};
struct List {
	Node* head = NULL;
	int size = 0;
	void addStudent(Node* newStudent) {
		if (head == NULL) {
			head = newStudent;
			size++;
		}
		else {
			Node* temp = head;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = newStudent;
			temp = temp->next;
		}
		newStudent->next = NULL;
		size++;
	}
	int count(List list) {
		Node* temp = list.head;
		int cnt = 0;
		while (temp->next != NULL) {
			if (temp->average == temp->next->average)
				cnt++;
			temp = temp->next;
		}
		return cnt;
	}
	void readData() {
		fstream ifile;
		ifile.open("data3.txt", ios::in);
		if (ifile.eof()) {
			cout << "Error! File is not found!";
			return;
		}
		string line;
		while (getline(ifile, line)) {
			stringstream iss(line);
			int stuID;
			double average;
			iss >> stuID >> average;
			Node* newStudent = new Node(stuID, average);
			addStudent(newStudent);

			//cout << stuID << " " << average << endl;
		}
		ifile.close();
	}
	void writeData(List list) {
		fstream ofile;
		ofile.open("result3.txt", ios::out | ios::binary);
		if (ofile.eof()) {
			cout << "Error! File is not found!";
			return;
		}
		Node* temp = list.head;
		//ofile << "Cac sinh vien co diem trung binh nho hon 5:\n";
		cout << "Cac sinh vien co diem trung binh nho hon 5:\n";
		int cnt = 0;
		while (temp != NULL) {
			if (temp->average < 5) {
				cnt++;
			}
			temp = temp->next;
		}
		ofile.write((char*)&cnt, sizeof(int));
		temp = list.head;
		while (temp != NULL) {
			if (temp->average < 5) {
				ofile.write((char*)temp, sizeof(Node));
				//ofile << temp->stuID << " " << temp->average << endl;
				//cout << temp->stuID << " " << temp->average << endl;
			}
			temp = temp->next;
		}
		ofile.close();
	}
	void readDataFromBinaryFile(List list) {
		fstream ifile("result3.txt", ios::binary | ios::in);
		if (!ifile.is_open()) {
			cout << "Error! Error! File is not found!" << endl;
			return;
		}
		
		int cnt;
		ifile.read((char*)(&cnt), sizeof(int));

		cout << "So sinh vien co diem trung binh nho hon 5: " << cnt << endl;
		for (int i = 0; i < cnt; ++i) {
			Node* temp = list.head;
			ifile.read((char*)(temp), sizeof(Node));
			cout << " " << temp->stuID << " " << temp->average << endl;
		}

		ifile.close();
	}

	void deleteMemory() {
		Node* temp = head;
		while (temp != NULL) {
			Node* cur = temp->next;
			delete temp;
			temp = cur;
		}
		head = NULL;
		size = 0;
	}
};
int main() {
	List list;
	list.readData();
	/*int cnt = list.count(list);
	cout << cnt << endl;*/
	list.writeData(list);
	list.readDataFromBinaryFile(list);

	list.deleteMemory();
	return 0;
}