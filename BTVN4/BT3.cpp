#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

struct Node {
	int score;
	Node* next;
	Node(int score) {
		this->score = score;
		this->next = NULL;
	}
};

struct DanhSachLienKet {
	int size = 0;
	Node* head = NULL;
	void addNewNode(int pos, int score) {
		Node* newNode = new Node(score);
		if (head == NULL) {
			head = newNode;
			size++;
			return;
		}
		if (pos == 1) {
			newNode->next = head;
			head = newNode;
			size++;
			return;
		}
		if (pos == size + 1) {
			Node* temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = newNode;
			newNode->next = NULL;
			size++;
			return;
		}
		int cnt = 1;
		Node* temp = head;
		while (cnt < pos - 1) {
			temp = temp->next;
			cnt++;
		}
		newNode->next = temp->next;
		temp->next = newNode;
		size++;
	}
	void deleteNode(int pos) {
		Node* temp = head;
		if (size == 1) {
			head = NULL;
			return;
		}
		if (pos == 1) {
			head = head->next;
			delete temp;
			size--;
			return;
		}
		if (pos == size) {
			while (temp->next->next != NULL) {
				temp = temp->next;
			}
			temp->next = NULL;
			delete temp->next;
			size--;
			return;
		}
		int cnt = 1;
		while (cnt < pos - 1 && temp->next != NULL) {
			temp = temp->next;
			cnt++;
		}
		if (temp->next != NULL) {
			Node* toDelete = temp->next;
			temp->next = toDelete->next;
			delete toDelete;
			size--;
		}
	}
	void findMaxNode(Node* head) {
		int maxi = head->score;
		Node* temp = head->next;
		while (temp != NULL) {
			if (temp->score > maxi)
				maxi = temp->score;
			temp = temp->next;
		}
		cout << "Gia tri score lon nhat la: " << maxi << endl;
	}
	void findAverage(Node* head) {
		int cnt = 0;
		int sum = 0;
		Node* temp = head;
		while (temp != NULL) {
			sum += temp->score;
			cnt++;
			temp = temp->next;
		}
		cout << "Trung binh cac gia tri score la: " << (float)sum / cnt << endl;
	}
	void sortAccendingNode(Node*& head) {
		if (head == NULL || head->next == NULL)
			return;
		Node* cur = head;
		Node* sorted = NULL;
		while (cur != NULL) {
			Node* nextNode = cur->next;
			if (sorted == NULL || cur->score <= sorted->score) {
				cur->next = sorted;
				sorted = cur;
			}
			else {
				Node* prevSorted = NULL;
				Node* temp = sorted;
				while (temp != NULL && temp->score < cur->score) {
					prevSorted = temp;
					temp = temp->next;
				}
				cur->next = temp;
				if (prevSorted != NULL)
					prevSorted->next = cur;
				else sorted = cur;
			}
			cur = nextNode;
		}
		head = sorted;
		cout << "Danh sach sau khi sap xep la: ";
	}
	void random(int n) {
		srand(time(NULL));
		int i = 1;
		while (i <= n) {
			int val = rand() % 100;
			addNewNode(i, val);
			i++;
		}
	}
	void printNode() {
		Node* temp = head;
		while (temp != NULL) {
			cout << temp->score << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	void deleteMemory() {
		Node* temp = head;
		while (temp != NULL) {
			Node* cur = temp;
			temp = temp->next;
			delete cur;
		}
		size = 0;
		head = NULL;
	}
};
int main() {
	DanhSachLienKet danhsach;
	int n = 0, to_delete = 0, to_insert = 0, val_insert = 0;
	cout << "Nhap so node can tao: ";
	cin >> n;
	cout << "Nhap vi tri can xoa: ";
	cin >> to_delete;
	cout << "Nhap vi tri can chen: ";
	cin >> to_insert;
	cout << "Nhap gia tri can chen: ";
	cin >> val_insert;

	danhsach.random(n);

	cout << "Danh sach ban dau: ";

	danhsach.printNode();

	danhsach.addNewNode(to_insert, val_insert);

	cout << "Danh sach sau khi chen phan tu " << val_insert << ": ";

	danhsach.printNode();

	danhsach.deleteNode(to_delete);

	cout << "Danh sach sau khi xoa phan tu thu " << to_delete << ": ";

	danhsach.printNode();

	danhsach.findMaxNode(danhsach.head);

	danhsach.findAverage(danhsach.head);

	danhsach.sortAccendingNode(danhsach.head);

	danhsach.printNode();

	danhsach.deleteMemory();

	return 0;
}