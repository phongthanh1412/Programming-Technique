#include<iostream>
using namespace std;

struct Node {
	int* row;
	Node* next;
	Node(int* row) {
		this->row = row;
		this->next = NULL;
	}
};
struct LinkedList {
	Node* ll = NULL;
	int size = 0;
	int** createMatrix(int& n, int& m) {
		int** arr2 = new int* [n];
		for (int i = 0; i < n; i++)
			arr2[i] = new int[m];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> arr2[i][j];
		cout << "Ma tran ban dau: \n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cout << arr2[i][j] << " ";
			cout << endl;
		}
		return arr2;
	}
	void convertToList(int** arr2, int n, int m, Node*& ll) {
		
		if (ll == NULL) {
			ll = new Node(arr2[0]);
			size++;
		}
		Node* temp = ll;
		while (temp ->next != NULL) {
			temp = temp->next;
		}
		for (int i = 1; i < n; i++) {

			Node* newNode = new Node(arr2[i]);
			temp->next = newNode;
			temp = temp->next;
			size++;
		}
		cout << "Ma tran sau khi chuyen sang danh sach lien ket la: \n";
	}
	void sort(int* row, int n) {
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1)) {
					int temp = row[i];
					row[i] = row[j];
					row[j] = temp;
				}
			}
		}
	}
	void printList(int** arr2, int n, int m, Node*& ll) {
		Node* temp = ll;
		while (temp != NULL) {
			for (int i = 0; i < m; i++) {
				cout << temp->row[i] << " ";
			}
			temp = temp->next;
		}
	}
	void deleteMemory() {
		Node* temp = ll;
		while (temp != NULL) {
			Node* cur = temp->next;
			delete[]cur->row;
			delete cur;
			temp = temp->next;
		}
		ll = NULL;
		size = 0;
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	LinkedList list;
	int** matrix = list.createMatrix(n, m);
	list.convertToList(matrix, n, m, list.ll);
	list.printList(matrix, n, m, list.ll);
	list.deleteMemory();
	return 0;
}