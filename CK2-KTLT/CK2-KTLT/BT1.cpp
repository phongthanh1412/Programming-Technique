#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

struct List {
	Node* head;
};

void init(List& l) {
	l.head = NULL;
}

Node* createNode(int val) {
	Node* newNode = new Node;
	newNode->data = val;
	newNode->next = NULL;
	return newNode;
}

void addTail(List& l, int val) {
	Node* newNode = createNode(val);
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
	}
}

void createList(List& l, int n) {
	init(l);
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		addTail(l, val);
	}
}

void show(List& l) {
	Node* temp = l.head;
	while (temp!= NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
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
Node* middle(List& l) {
	Node* fast = l.head;
	Node* slow = l.head;
	while (fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

Node* reverse(Node* head) {
	Node* temp = head;
	Node* prev = NULL;
	while (temp != NULL) {
		Node* cur = temp->next;
		temp->next = prev;
		prev = temp;
		temp = cur;
	}
	return prev;
}

bool isSymmetric(List& l) {
	if (l.head == NULL)
		return 0;
	Node* mid = middle(l);
	Node* temp = reverse(mid);
	mid = reverse(mid);
	while (temp != NULL) {
		if (temp->data != l.head->data || l.head == NULL)
			return 0;
		temp = temp->next;
		l.head = l.head->next;
	}
	return 1;
}

bool isPrime(int n) {
	if (n < 2)
		return 0;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)
			return 0;
	}
	return 1;
}
int countPrime(Node* h) {
	if (h == NULL)
		return 0;
	if (isPrime(h->data)) {
		return 1 + countPrime(h->next);
	}
	else return countPrime(h->next);
}
bool check(Node* head, int k) {
	if (head == NULL || head->next == NULL)
		return 1;
	if (head->data - head->next->data == k)
		return check(head->next, k);
	return 0;
}

bool isDeccendingEqual(Node* head) {
	if (head == NULL || head->next == NULL)
		return 1;
	int k = head->data - head->next->data;
	return check(head, k);
}

int count(List list) {
	Node* temp = list.head;
	int cnt = 0;
	while (temp != NULL && temp->next != NULL) {
		if (temp->data == temp->next->data)
			cnt++;
		temp = temp->next;
	}
	return cnt;
}
int main() {
	List l;
	int n;
	cin >> n;
	createList(l, n);
	show(l);
	//cout << isSymmetric(l);
	//cout << countPrime(l.head);
	//cout << isDeccendingEqual(l.head);
	cout << count(l);
	release(l);
	return 0;
}