#include"functionBT2.h"

using namespace std;

Node::Node(int* row) {

		this->row = row;
		this->next = NULL;
};

int** DanhSachLienKet::createMarix(int& n, int& m) {
	int** arr2 = new int* [n];
	for (int i = 0; i < n; i++)
		arr2[i] = new int[m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr2[i][j];
	cout << "Ma tran ban dau la: \n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << arr2[i][j] << " ";
		cout << endl;
	}
	return arr2;
}

void DanhSachLienKet::convertToList(int** arr2, int n, int m, Node*& ll) {
	Node* temp = ll;
	if (ll == NULL) {
		ll = new Node(arr2[0]);
		temp = ll;
		size++;
	}
	for (int i = 1; i < n; i++) {
		Node* newNode = new Node(arr2[i]);
		temp->next = newNode;
		temp = newNode;
		size++;
	}
	cout << "Ma tran sau khi chuyen sang danh sach lien ket la: \n";
}

void DanhSachLienKet::sortMatrix(int* row, int m) {
	for (int i = 0; i < m - 1; i++) {
		for (int j = i + 1; j < m; j++) {
			if (i % 2 == 0 && j % 2 == 0 && row[i] > row[j] || i % 2 == 1 && j % 2 == 1 && row[i] < row[j]) {
				int temp = row[i];
				row[i] = row[j];
				row[j] = temp;
			}
		}
	}
}

void DanhSachLienKet::sortList(Node*& ll, int m) {
	Node* temp = ll;
	while (temp != NULL) {
		sortMatrix(temp->row, m);
		temp = temp->next;
	}
	cout << "Danh sach sau khi sap xep la:\n";
}

void DanhSachLienKet::findSumList(Node*& ll, int m) {
	Node* temp = ll;
	cout << "Tong cac phan tu trong tung nut cua danh sach lien ket la:\n";
	while (temp != NULL) {
		int sum = 0;
		for (int i = 0; i < m; i++) {
			sum += temp->row[i];
		}
		cout << sum << " ";
		temp = temp->next;
	}
	cout << endl;
}
void DanhSachLienKet::writeToFile(Node*& ll, int m) {
	fstream ofile;
	ofile.open("data.txt", ios::out);
	if (ofile.eof()) {
		cout << "File is not found!";
		return;
	}
	Node* temp = ll;
	while (temp != NULL) {
		int sum = 0;
		for (int i = 0; i < m; i++) {
			sum += temp->row[i];
		}
		ofile << sum << " ";
		temp = temp->next;
	}
	ofile.close();
}
void DanhSachLienKet::readFileData(Node*& ll, int m, int* arr) {
	fstream ifile;
	ifile.open("data.txt", ios::in);
	if (ifile.eof()) {
		cout << "File is not found!";
		return;
	}
	int idx = 0, val = 0;
	while (ifile >> val) {
		arr[idx++] = val;
	}
	ifile.close();
}

bool DanhSachLienKet::isFibonacci(int n) {
	if (n == 0 || n == 1)
		return 1;
	int a = 0, b = 1;
	while (b < n) {
		int temp = b;
		b += a;
		a = temp;
	}
	return b == n;
}

int DanhSachLienKet::countFibonacci(int* arr, int m) {
	int cnt = 0;
	for (int i = 0; i < m; i++)
		if (isFibonacci(arr[i]))
			cnt++;
	return cnt;
}

void DanhSachLienKet::printList(int** arr2, int m, Node*& ll) {
	Node* temp = ll;
	while (temp != NULL) {
		for (int i = 0; i < m; i++) {
			cout << temp->row[i] << " ";
		}
		temp = temp->next;
	}
	cout << endl;
}

void DanhSachLienKet::deleteMemoryList() {
	Node* temp = ll;
	while (temp != NULL) {
		Node* cur = temp->next;
		temp = temp->next;
		delete[]cur->row;
		delete cur;
	}
	ll = NULL;
	size = 0;
}