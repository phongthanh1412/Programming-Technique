#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct ns {
	int ngay = 0;
	int thang = 0;
	int nam = 0;
};

struct sv {
	int mssv = 0;
	string hoVaTen;
	ns NS;
	int Toan = 0;
	int Van = 0;
	int Anh = 0;
	int diemTrungBinh = 0;
	string loaihocluc;

};

struct Node {
	sv sinhVien;
	Node* next;
	Node(sv SV) {
		this->sinhVien = SV;
		this->next = NULL;
	}
};

struct LinkedList {
	Node* head;
	int size;
	LinkedList() {
		head = NULL;
		size = 0;
	}
	void addStudent(Node* newStudent) {
		if (head == NULL) {
			head = newStudent;
			size++;
			return;
		}
		else {
			Node* temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			newStudent->next = temp->next;
			temp->next = newStudent;
			newStudent->next = NULL;
		}
		size++;
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
	void show() {
		Node* temp = head;
		while (temp != NULL) {
			cout << temp->sinhVien.mssv << " " << temp->sinhVien.hoVaTen << " " << temp->sinhVien.NS.ngay
				<< "/" << temp->sinhVien.NS.thang << "/" << temp->sinhVien.NS.nam << " "
				<< temp->sinhVien.Toan << " " << temp->sinhVien.Van << " " << temp->sinhVien.Anh << endl;
			temp = temp->next;
		}
		cout << endl;
	}
	void show2() {
		Node* temp = head;
		while (temp != NULL) {
			cout << temp->sinhVien.mssv << " " << temp->sinhVien.hoVaTen << " " << temp->sinhVien.NS.ngay
				<< "/" << temp->sinhVien.NS.thang << "/" << temp->sinhVien.NS.nam << " "
				<< temp->sinhVien.Toan << " " << temp->sinhVien.Van << " " << temp->sinhVien.Anh
				<< " " << temp->sinhVien.diemTrungBinh << " " << temp->sinhVien.loaihocluc << endl;
			temp = temp->next;
		}
		cout << endl;
	}
};
string normalize(string& name) {
	string res;
	bool flag = 1;
	for (int i = 0; i < name.size(); i++) {
		if (isspace(name[i])) {
			res += name[i];
			flag = 1;
		}
		else {
			if (flag) {
				res += toupper(name[i]);
				flag = 0;
			}
			else res += tolower(name[i]);
		}
	}
	return res;
}
void readData(string fileName, LinkedList& list, sv SV) {
	fstream ifile;
	ifile.open(fileName, ios::in);
	if (ifile.eof()) {
		cout << "File is not found!";
		return;
	}
	while (!ifile.eof()) {
		ifile >> SV.mssv;
		ifile.seekg(1, 1);
		getline(ifile, SV.hoVaTen, '-');
		SV.hoVaTen = normalize(SV.hoVaTen);
		ifile >> SV.NS.ngay;
		ifile.seekg(1, 1);
		ifile >> SV.NS.thang;
		ifile.seekg(1, 1);
		ifile >> SV.NS.nam;
		ifile.seekg(1, 1);

		ifile >> SV.Toan;
		ifile.seekg(1, 1);

		ifile >> SV.Van;
		ifile.seekg(1, 1);
		ifile >> SV.Anh;
		string dummy;
		getline(ifile, dummy);

		Node* newStudent = new Node(SV);
		list.addStudent(newStudent);


	}
}
void sortList(LinkedList& list) {

	if (list.head == NULL || list.head->next == NULL)
		return;

	Node* pivot = list.head;
	list.head = list.head->next;
	pivot->next = NULL;

	LinkedList l1, l2;
	l1.head = l2.head = NULL;
	Node* p = list.head;
	while (p != NULL) {
		Node* next = p->next;
		p->next = NULL;
		if (p->sinhVien.Toan < pivot->sinhVien.Toan)
			l1.addStudent(p);
		else l2.addStudent(p);
		p = next;
	}
	sortList(l1);
	sortList(l2);
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
Node* getNode(LinkedList& list, int idx) {
	Node* temp = list.head;
	int cnt = 0;
	while (temp != NULL && cnt < idx) {
		temp = temp->next;
		cnt++;
	}
	return temp;
}
Node* binarySearch(LinkedList& list, int target, int size) {
	int left = 0, right = size - 1, mid = 0;

	while (left <= right) {
		mid = left + (right - left) / 2;
		Node* midNode = getNode(list, mid);
		if (midNode == NULL)
			return NULL;
		if (midNode->sinhVien.mssv == target)
			return midNode;
		else if (midNode->sinhVien.mssv < target)
			left = mid + 1;
		else right = mid - 1;
	}
	return NULL;
}

void swapNode(LinkedList& list, int k) {
	if (list.head == NULL || list.head->next == NULL) return;
	Node* prevFirst = NULL;
	Node* First = NULL;
	Node* prevSecond = NULL;
	Node* Second = NULL;
	Node* temp = list.head;
	while (temp != NULL && First == NULL) {
		if (temp->next != NULL && temp->next->sinhVien.mssv == k) {
			prevFirst = temp;
			First = temp->next;
		}
		temp = temp->next;
	}
	temp = list.head;
	while (temp != NULL && Second == NULL) {
		if (temp->next != NULL && temp->next->sinhVien.mssv == k && temp->next != First) {
			prevSecond = temp;
			Second = temp->next;
		}
		temp = temp->next;
	}
	if (First == NULL || Second == NULL) 
		return;
	if (prevFirst != NULL) {
		prevFirst->next = Second;
	}
	else list.head = Second;
	if (prevSecond != NULL) {
		prevSecond->next = First;
	}
	else list.head = First;

	Node* tempNext = First->next;
	First->next = Second->next;
	Second->next = tempNext;

}
void convert(int n, string& s) {
	if (n == 0)
		return;
	convert(n / 2, s);
	if (n % 2 == 0)
		s += '0';
	else s += '1';
}
int convert2(int idx, string& s) {
	if (idx >= s.size())
		return 0;
	int bit = s[idx] - '0';
	int sum = bit * pow(2, s.size() - 1 - idx);
	return sum + convert2(idx + 1, s);
}

string convert3(int n, string& s) {
	string res;
	string arr = "0123456789ABCDEF";
	if (n == 0)
		return "";
	int bit = n % 16;
	return convert3(n / 16, s) + arr[bit];
}
string convert4(int n, string& s) {
	string res;
	if (n == 0)
		return "";
	int bit = n % 8;
	return convert3(n / 8, s) + to_string(bit);
}

int main() {

	/*string fileName = "data.txt";
	LinkedList list;
	sv SV;

	readData(fileName, list, SV);
	list.show();

	sortList(list);
	list.show();

	int k;
	cin >> k;
	swapNode(list, k);
	list.show();*/
	/*string s = "1001";
	cout << convert2(0, s);*/
	string s1;
	int k = 0;
	cin >> k;
	cout << convert4(k, s1);
	
	return 0;
}