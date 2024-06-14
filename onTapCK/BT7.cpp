//#include<iostream>
//#include<fstream>
//#include<string>
//using namespace std;
//
//struct ns {
//	int ngay = 0;
//	int thang = 0;
//	int nam = 0;
//};
//
//struct sv {
//	int mssv = 0;
//	string hoVaTen;
//	ns NS;
//	int Toan = 0;
//	int Van = 0;
//	int Anh = 0;
//	int diemTrungBinh = 0;
//	string loaihocluc;
//
//};
//
//struct Node {
//	sv sinhVien;
//	Node* next;
//	Node(sv SV) {
//		this->sinhVien = SV;
//		this->next = NULL;
//	}
//};
//
//struct LinkedList {
//	Node* head;
//	int size;
//	LinkedList() {
//		head = NULL;
//		size = 0;
//	}
//	void addStudent(Node* newStudent) {
//		if (head == NULL) {
//			head = newStudent;
//			size++;
//			return;
//		}
//		else {
//			Node* temp = head;
//			while (temp->next != NULL) {
//				temp = temp->next;
//			}
//			newStudent->next = temp->next;
//			temp->next = newStudent;
//			newStudent->next = NULL;
//		}
//		size++;
//	}
//	void release() {
//		Node* temp = head;
//		while (temp != NULL) {
//			Node* cur = temp;
//			temp = temp->next;
//			delete cur;
//		}
//		head = NULL;
//		size = 0;
//	}
//	void show() {
//		Node* temp = head;
//		while (temp != NULL) {
//			cout << temp->sinhVien.mssv << " " << temp->sinhVien.hoVaTen << " " << temp->sinhVien.NS.ngay
//				<< "/" << temp->sinhVien.NS.thang << "/" << temp->sinhVien.NS.nam << " "
//				<< temp->sinhVien.Toan << " " << temp->sinhVien.Van << " " << temp->sinhVien.Anh << endl;
//			temp = temp->next;
//		}
//		cout << endl;
//	}
//	void show2() {
//		Node* temp = head;
//		while (temp != NULL) {
//			cout << temp->sinhVien.mssv << " " << temp->sinhVien.hoVaTen << " " << temp->sinhVien.NS.ngay
//				<< "/" << temp->sinhVien.NS.thang << "/" << temp->sinhVien.NS.nam << " "
//				<< temp->sinhVien.Toan << " " << temp->sinhVien.Van << " " << temp->sinhVien.Anh
//				<< " " << temp->sinhVien.diemTrungBinh << " " << temp->sinhVien.loaihocluc << endl;
//			temp = temp->next;
//		}
//		cout << endl;
//	}
//};
//string normalize(string& name) {
//	string res;
//	bool flag = 1;
//	for (int i = 0; i < name.size(); i++) {
//		if (isspace(name[i])) {
//			res += name[i];
//			flag = 1;
//		}
//		else {
//			if (flag) {
//				res += toupper(name[i]);
//				flag = 0;
//			}
//			else res += tolower(name[i]);
//		}
//	}
//	return res;
//}
//void readDataOfStudent(string fileName, LinkedList& list, sv SV) {
//	fstream ifile;
//	ifile.open(fileName, ios::in);
//	if (ifile.eof()) {
//		cout << "File is not found!";
//		return;
//	}
//	while (!ifile.eof()) {
//		ifile >> SV.mssv;
//		ifile.seekg(1, 1);
//		getline(ifile, SV.hoVaTen, '-');
//		SV.hoVaTen = normalize(SV.hoVaTen);
//		ifile >> SV.NS.ngay;
//		ifile.seekg(1, 1);
//		ifile >> SV.NS.thang;
//		ifile.seekg(1, 1);
//		ifile >> SV.NS.nam;
//		ifile.seekg(1, 1);
//		ifile >> SV.Toan;
//		ifile.seekg(1, 1);
//		ifile >> SV.Van;
//		ifile.seekg(1, 1);
//		ifile >> SV.Anh;
//		string dummy;
//		getline(ifile, dummy);
//
//		Node* newStudent = new Node(SV);
//		list.addStudent(newStudent);
//	}
//	ifile.close();
//}
//void classifyList(LinkedList& list) {
//	Node* temp = list.head;
//	while (temp != NULL) {
//		int average = (temp->sinhVien.Toan + temp->sinhVien.Van + temp->sinhVien.Anh) / 3;
//		temp->sinhVien.diemTrungBinh = average;
//		if (temp->sinhVien.diemTrungBinh < 5)
//			temp->sinhVien.loaihocluc = "yeu";
//		if (temp->sinhVien.diemTrungBinh >= 5 && temp->sinhVien.diemTrungBinh < 6.5)
//			temp->sinhVien.loaihocluc = "trung binh";
//		if (temp->sinhVien.diemTrungBinh >= 6.5 && temp->sinhVien.diemTrungBinh < 8)
//			temp->sinhVien.loaihocluc = "kha";
//		if (temp->sinhVien.diemTrungBinh >= 8 && temp->sinhVien.diemTrungBinh < 9)
//			temp->sinhVien.loaihocluc = "gioi";
//		if (temp->sinhVien.diemTrungBinh >= 9 && temp->sinhVien.diemTrungBinh <= 10)
//			temp->sinhVien.loaihocluc = "xuat sac";
//		temp = temp->next;
//	}
//}
//void sortList(LinkedList& list) {
//	if (list.head == NULL || list.head->next == NULL)
//		return;
//	Node* pivot = list.head;
//	list.head = list.head->next;
//	pivot->next = NULL;
//
//	LinkedList l1, l2;
//	l1.head = l2.head = NULL;
//	Node* p = list.head;
//	while (p != NULL) {
//		Node* next = p->next;
//		p->next = NULL;
//		if (p->sinhVien.mssv <= pivot->sinhVien.mssv)
//			l1.addStudent(p);
//		else l2.addStudent(p);
//		p = next;
//	}
//	sortList(l1);
//	sortList(l2);
//	if (l1.head != NULL) {
//		list.head = l1.head;
//		Node* temp = l1.head;
//		while (temp->next != NULL)
//			temp = temp->next;
//		temp->next = pivot;
//	}
//	else list.head = pivot;
//	if (l2.head != NULL) {
//		pivot->next = l2.head;
//	}
//}
//Node* getNodeAtIndex(Node* head, int index) {
//	Node* current = head;
//	int count = 0;
//	while (current != NULL && count < index) {
//		current = current->next;
//		count++;
//	}
//	return current;
//}
//Node* binarySearch(Node* head, int target, int size) {
//	int left = 0;
//	int right = size - 1;
//
//	while (left <= right) {
//		int mid = left + (right - left) / 2;
//		Node* midNode = getNodeAtIndex(head, mid);
//
//		if (midNode == NULL) {
//			return NULL;
//		}
//
//		if (midNode->sinhVien.mssv == target) {
//			return midNode;
//		}
//		else if (midNode->sinhVien.mssv < target) {
//			left = mid + 1;
//		}
//		else {
//			right = mid - 1;
//		}
//	}
//
//	return NULL;
//}
//
//void deleteStudent(LinkedList& list, int k) {
//	Node* temp = list.head;
//	if (list.head != NULL && list.head->sinhVien.mssv == k) {
//		list.head = list.head->next;
//		delete temp;
//		list.size--;
//		return;
//	}
//	temp = list.head;
//	while (temp != NULL && temp->next != NULL) {
//		if (temp->next->sinhVien.mssv == k) {
//			Node* toDelete = temp->next;
//			temp->next = temp->next->next;
//			delete toDelete;
//			list.size--;
//		}
//		else temp = temp->next;		
//	}
//}
//
//void deleteOrInsert(LinkedList& list, int k) {
//	
//
//}
//void binarySearch(LinkedList& list, int k) {
//
//}
//void swapStudents(LinkedList& list, int mssv) {
//	if (list.head == NULL || list.head->next == NULL) return;
//
//	Node* firstPrev = NULL;
//	Node* secondPrev = NULL;
//	Node* first = NULL;
//	Node* second = NULL;
//	Node* temp = list.head;
//
//	// Finding the first node with the given mssv
//	while (temp != NULL && first == NULL) {
//		if (temp->next != NULL && temp->next->sinhVien.mssv == mssv) {
//			firstPrev = temp;
//			first = temp->next;
//		}
//		temp = temp->next;
//	}
//
//	temp = list.head;
//	// Finding the second node with the given mssv
//	while (temp != NULL && second == NULL) {
//		if (temp->next != NULL && temp->next->sinhVien.mssv == mssv && temp->next != first) {
//			secondPrev = temp;
//			second = temp->next;
//		}
//		temp = temp->next;
//	}
//
//	// If either of the nodes is not found, return
//	if (first == NULL || second == NULL) return;
//
//	// Swap the nodes
//	if (firstPrev != NULL) {
//		firstPrev->next = second;
//	}
//	else {
//		list.head = second;
//	}
//
//	if (secondPrev != NULL) {
//		secondPrev->next = first;
//	}
//	else {
//		list.head = first;
//	}
//
//	Node* tempNext = first->next;
//	first->next = second->next;
//	second->next = tempNext;
//}
//void convert(int n, string& s) {
//	if (n == 0)
//		return;
//	convert(n / 2, s);
//	if (n % 2 == 0)
//		s += '0';
//	else s += '1';
//}
//int convert2(int idx, string& s) {
//	if (idx >= s.size())
//		return 0;
//	int bit = s[idx] - '0';
//	int sum = bit * pow(2, s.size() - 1 - idx);
//	return sum + convert2(idx + 1, s);
//}
//
//string convert3(int n, string& s) {
//	string res;
//	string arr = "0123456789ABCDEF";
//	if (n == 0)
//		return "";
//	int bit = n % 16;
//	return convert3(n / 16, s) + arr[bit];
//}
//string convert4(int n, string& s) {
//	string res;
//	if (n == 0)
//		return "";
//	int bit = n % 8;
//	return convert3(n / 8, s) + to_string(bit);
//}
//int main() {
//
//	string fileName = "data.txt";
//	LinkedList list;
//	sv SV;
//
//	readDataOfStudent(fileName, list, SV);
//	list.show();
//	/*classifyList(list);
//	list.show2();
//
//	sortList(list);
//	list.show();
//
//	int k = 0; cin >> k;
//	deleteStudent(list, k);
//	list.show();*/
//
//	int mssv = 0;
//	cin >> mssv;
//	swapStudents(list, mssv);
//	list.show();
//
//	Node* result = binarySearch(list.head, mssv, list.size);
//
//	if (result != NULL) {
//		cout << "Found student: " << result->sinhVien.hoVaTen << endl;
//	}
//	else {
//		cout << "Student not found." << endl;
//	}
//
//
//	list.release();
//
//	/*int n;
//	string s;
//	cin >> n;
//	decimalToBinary(n, s);
//	cout << s;*/
//	return 0;
//}
#include<iostream>
using namespace std;
int main() {
	int a[10] = { 7,6,9,1,2,4,2,6,3,1 };
	int* p = a;
	p = p + 1;
	*p = *p + 1;
	cout << *p;
	p += 1;
	*p += 1;
	cout << p;
	/**(p += 1);
	cout << p;*/
}