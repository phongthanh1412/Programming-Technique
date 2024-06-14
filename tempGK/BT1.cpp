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

	void readData(int*& arr, int& n) {
		fstream ifile;
		ifile.open("data1.txt", ios::in);
		
		if (!ifile.is_open()) {
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

		ifile.close();
		
	}

	void findcount(int* arr, int n) {
		int maxVal = -1e9;
		for (int i = 1; i < n; ++i) {
			if (arr[i] > maxVal) {
				maxVal = arr[i];
			}
		}

		int* count = new int[maxVal + 1];
		for (int i = 0; i <= maxVal; ++i) {
			count[i] = 0;
		}
	
		for (int i = 0; i < n; i++) 
			count[arr[i]]++;

		int maxi = count[arr[0]];
		int maxiNum = arr[0];
		
		for (int i = 0; i < n; i++) {
			if (count[arr[i]] > maxi) {
				maxi = count[arr[i]];
				maxiNum = arr[i];
			}
		}
		
		cout << "Phan tu xuat hien nhieu nhat la " << maxiNum << " voi " << maxi << " lan\n";
	}
	void changeArray(int* arr, int n, int*& newArr) {
		newArr = new int[n];
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
			newArr[i] = temp;
		}
		cout << "Mang sau khi bien doi la: \n";
		for (int i = 0; i < n; i++)
			cout << newArr[i] << " ";
		cout << endl;

		fstream ofile;
		ofile.open("result.txt", ios::out | ios::app);
		ofile << "Mang sau khi bien doi la: \n";
		for (int i = 0; i < n; i++)
			ofile << newArr[i] << " ";
		ofile << endl;

		ofile.close();
	}
	void changeToList(int* newArr, int n) {
		if (head == NULL) {
			head = new Node(newArr[0]);
			size++;
		}
		Node* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		for (int i = 1; i < n; i++) {

			Node* newNode = new Node(newArr[i]);
			temp->next = newNode;
			temp = temp->next;
			size++;
		}
		cout << "Mang sau khi chuyen sang danh sach lien ket la: \n";
		temp = head;
		
	}
	void reverseList(Node*& head) {
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
		cout << "Danh sach sau khi dao nguoc\n";
	}
	void printList() {
		Node* temp = head;
		while (temp != NULL) {
			cout << temp->score << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	void deleteMemory(int* arr) {
		delete[]arr;
	}
};

int main() {
	List list;
	int n;
	int* arr = NULL;
	int* newArr = NULL;
	int* count = NULL;
	list.readData(arr, n);
	list.findcount(arr, n);
	list.changeArray(arr, n, newArr);
	list.changeToList(newArr, n);
	list.printList();
	list.reverseList(list.head);
	list.printList();

	list.deleteMemory(count);
	list.deleteMemory(newArr);
	list.deleteMemory(arr);
	return 0;
}