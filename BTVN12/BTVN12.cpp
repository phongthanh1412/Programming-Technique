#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct Student {

	string name;
	string gender;
	int date = 0;
	int month = 0;
	int year = 0;
	int mathScore = 0;
	int literatureScore = 0;
	int englishScore = 0;

};

struct Node {

	Student s;
	Node* next;
	Node(Student s) {
		this->s = s;
		this->next = NULL;
	}
};

struct StudentList {

	Node* head;
	int size;
	StudentList() {
		head = NULL;
		size = 0;
	}
	void addStudent(Node* newStudent) {
		if (head == NULL) {
			head = newStudent;
			size++;
			return;
		}
		Node* temp = head;
		while (temp->next != NULL)
			temp = temp->next;
		newStudent->next = temp->next;
		temp->next = newStudent;
		newStudent->next = NULL;
		size++;
	}
	void addHead(Node* newStudent) {
		if (head == NULL) {
			head = newStudent;
			size++;
			return;
		}
		else {
			newStudent->next = head;
			head = newStudent;
			size++;
		}
	}
	void release() {
		Node* temp = head;
		while (temp != NULL) {
			Node* cur = temp;
			temp = temp->next;
			delete cur;
		}
		head = NULL;
		size = 0;
	}
};

void createList(string filename, StudentList& list, Student s) {
	fstream ifile;
	ifile.open(filename, ios::in);
	if (ifile.eof()) {
		cout << "File is not found!";
		return;
	}

	string name, gender;
	int date, month, year, mathScore, literatureScore, englishScore;
	string line;
	size_t pos = 0, start = 0;
	while (getline(ifile, line)) {
		// tach ten
		pos = line.find(' ', start);
		s.name = line.substr(start, pos - start);
		start = pos + 1;
		// gioi tinh
		pos = line.find(' ', start);
		s.gender = line.substr(start, pos - start);
		start = pos + 1;
		// ngay
		pos = line.find('/', start);
		s.date = stoi(line.substr(start, pos - start));
		start = pos + 1;
		// thang
		pos = line.find('/', start);
		s.month = stoi(line.substr(start, pos - start));
		start = pos + 1;
		//nam
		pos = line.find(' ', start);
		s.year = stoi(line.substr(start, pos - start));
		start = pos + 1;
		//diem toan
		pos = line.find(' ', start);
		s.mathScore = stoi(line.substr(start, pos - start));
		start = pos + 1;
		//diem van
		pos = line.find(' ', start);
		s.literatureScore = stoi(line.substr(start, pos - start));
		start = pos + 1;
		//diem anh
		pos = line.find(' ', start);
		s.englishScore = stoi(line.substr(start, pos - start));
		start = pos + 1;

		Node* newStudent = new Node(s);
		list.addStudent(newStudent);

	}
	ifile.close();
}
void show(Node* head) {
	Node* temp = head;
	if (head == NULL)
		return;
	cout << temp->s.name << " " << temp->s.gender << " " << temp->s.date << "/" << temp->s.month << "/" << temp->s.year << " " <<
		temp->s.mathScore << " " << temp->s.literatureScore << " " << temp->s.englishScore << endl;
	return show(head->next);
	cout << endl;
}
void deleteNode(StudentList& list, int k) {
	Node* temp = list.head;
	if (k == 1) {
		list.head = list.head->next;
		delete temp;
		list.size--;
		return;
	}
	else if (k == list.size) {
		while (temp->next->next != NULL)
			temp = temp->next;
		temp->next = NULL;
		delete temp->next;
		list.size--;
	}
	int cnt = 1;
	while (cnt < k - 1 && temp->next != NULL) {
		temp = temp->next;
		cnt++;
	}
	if (temp->next != NULL) {
		Node* toDelete = temp->next;
		temp->next = toDelete->next;
		delete toDelete;
		list.size--;
	}
}
void findDateOfStudent(StudentList& list, Student s, int today) {
	int cnt = 0;
	Node* temp = list.head;
	while (temp != NULL) {
		if (temp->s.date == today) {
			cout << temp->s.name << " " << temp->s.gender << " " << temp->s.date << "/" << temp->s.month << "/" << temp->s.year << " " <<
				temp->s.mathScore << " " << temp->s.literatureScore << " " << temp->s.englishScore << endl;
			cnt++;
		}
		temp = temp->next;
	}
	if (cnt == 0)
		cout << "--> Khong co sinh vien co ngay sinh trung voi ngay " << today << "\n";
}
void deleteYearOfStudent(StudentList& list) {
	Node* cur = list.head;
	if (list.head != NULL && list.head->s.year > 2005) {
		list.head = list.head->next;
		delete cur;
		list.size--;
	}
	Node* temp = list.head;
	while (temp != NULL && temp->next != NULL) {
		if (temp->next->s.year > 2005) {
			Node* toDelete = temp->next;
			temp->next = toDelete->next;
			delete toDelete;
			list.size--;
		}
		else temp = temp->next;
	}
}
void quickSort(StudentList& list) {
	if (list.head == NULL || list.head->next == NULL)
		return;
	Node* pivot = list.head;
	list.head = list.head->next;
	pivot->next = NULL;

	StudentList l1, l2;
	l1.head = l2.head = NULL;
	Node* p = list.head;
	while (p != NULL) {
		Node* next = p->next;
		p->next = NULL;
		if (p->s.mathScore <= pivot->s.mathScore)
			l1.addHead(p);
		else l2.addHead(p);
		p = next;
	}
	quickSort(l1);
	quickSort(l2);
	if (l1.head != NULL) {
		list.head = l1.head;
		Node* temp = l1.head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = pivot;
	}
	else list.head = pivot;

	if (l2.head != NULL) {
		pivot->next = l2.head;
	}

}
int main() {
	StudentList list, list1, list2;
	Student s;
	string filename = "data.txt";
	createList(filename, list, s);
	cout << "Danh sach ban dau:\n";
	show(list.head);

	createList(filename, list1, s);
	int k = 0;
	cout << "Nhap vi tri can xoa: ";
	cin >> k;
	deleteNode(list1, k);
	cout << "Danh sach sau khi xoa node thu " << k << ":\n";
	show(list1.head);

	int today = 0;
	cout << "Nhap ngay: ";
	cin >> today;
	cout << "Danh sach sinh vien co ngay sinh trung voi ngay " << today << " la\n";
	findDateOfStudent(list, s, today);

	createList(filename, list2, s);
	cout << "Danh sach sau khi xoa sinh vien co nam sinh lon hon 2005 la:\n";
	deleteYearOfStudent(list2);
	show(list2.head);

	cout << "Danh sach sinh vien sau khi sap xep tang dan theo diem Toan la:\n";
	quickSort(list);
	show(list.head);

	list2.release();
	list1.release();
	list.release();
	return 0;
}