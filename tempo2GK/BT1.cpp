#include<iostream>
#include<fstream>
using namespace std;

struct Node {
	int score;
	Node* next;
	Node(int score) {
		this->score = score;
		this->next = NULL;
	}
};
struct List {
	Node* head = NULL;
	int size = 0;
	void changeArray(int*& newarr, int* arr, int n) {
		newarr = new int[n];
		for (int i = 0; i < n; i++) {
			int temp = arr[i];
			while (temp >= 10) {
				int sum = 0;
				while (temp > 0) {
					int surplus = temp % 10;
					sum += surplus;
					temp /= 10;
				}
				temp = sum;
			}
			newarr[i] = temp;
		}
		cout << "Mang sau bien doi:\n";
		for (int i = 0; i < n; i++)
			cout << newarr[i] << " ";
		cout << endl;
	}
	void changeToList(int* newarr, int n) {
		if (head == NULL) {
			head = new Node(newarr[0]);
			size++;
		}
		Node* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		for (int i = 1; i < n; i++) {
			Node* newNode = new Node(newarr[i]);
			temp->next = newNode;
			temp = temp->next;
			size++;
		}
		cout << "Danh sach sau khi chuyen la:\n";
		temp = head;
	}
	void findReverseList(Node*& head) {
		if (head == NULL || head->next == NULL)
			return;
		Node* prev = NULL;
		Node* temp = head;
		while (temp != NULL) {
			Node* nextNode = temp->next;
			temp->next = prev;
			prev = temp;
			temp = nextNode;
		}
		head = prev;
		cout << "Danh sach sau khi dao nguoc:\n";
	}
	void printList() {
		Node* temp = head;
		while (temp != NULL) {
			cout << temp->score << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	void readData(int*& arr, int& n) {
		fstream ifile;
		ifile.open("data1.txt", ios::in);
		if (ifile.eof()) {
			cout << "Error! File is not found!";
			return;
		}
		ifile >> n;
		arr = new int[n];
		for (int i = 0; i < n; i++)
			ifile >> arr[i];
		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";
		cout << endl;
	}

	
	void deleteMemory(int* arr) {
		delete[]arr;
	}
};

int main() {
	int n;
	List list;
	int* arr = NULL;
	int* newarr = NULL;
	list.readData(arr, n);
	list.changeArray(newarr, arr, n);
	list.changeToList(newarr, n);
	list.printList();
	list.findReverseList(list.head);
	list.printList();

	list.deleteMemory(newarr);
	list.deleteMemory(arr);
	return 0;
}