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

void addTail(List& l, Node* newNode) {
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
void mergeLists(List x, List y, List& z) {
	if (x.head == NULL && y.head == NULL)
		return;
	while (x.head != NULL || y.head != NULL) {
		Node* p = new Node;
		if (x.head != NULL && y.head != NULL) {
			if (x.head->data <= y.head->data) {
				p = x.head;
				x.head = x.head->next;
				p->next = NULL;
				addTail(z, p);
			}
			else {
				p = y.head;
				y.head = y.head->next;
				p->next = NULL;
				addTail(z, p);
			}
		}
		else if (x.head != NULL && y.head == NULL) {
			p = x.head;
			x.head = x.head->next;
			p->next = NULL;
			addTail(z, p);
		}
		else {
			p = y.head;
			x.head = y.head->next;
			p->next = NULL;
			addTail(z, p);
		}
	}
}

void createList(List& l, int n) {
	init(l);
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		Node* p = createNode(val);
		addTail(l, p);
	}
}
void quickSort(List& l) {
	if (l.head == NULL || (l.head != NULL && l.head->next == NULL))
		return;
	Node* pivot = l.head;
	l.head = l.head->next;
	pivot->next = NULL;

	List l1, l2;
	init(l1);
	init(l2);
	Node* p = l.head;
	while (p != NULL) {
		Node* next = p->next;
		p->next = NULL;
		if (pivot->data > p->data) {
			addTail(l1, p);
		}
		else {
			addTail(l2, p);
		}
		p = next;
	}
	quickSort(l1);
	quickSort(l2);
	if (l1.head != NULL) {
		l.head = l1.head;
		Node* cur = l1.head;
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = pivot;
	}
	else l.head = pivot;
	if (l2.head != NULL) {
		pivot->next = l2.head;
	}
}
Node* getMinNode(Node* head) {
	if (head == NULL)
		return NULL;
	Node* minNode = head;
	Node* temp = head->next;
	while (temp != NULL) {
		if (minNode->data > temp->data)
			minNode = temp;
		temp = temp->next;
	}
	return minNode;
}
Node* getMaxNode(Node* head) {
	if (head == NULL)
		return NULL;
	Node* maxNode = head;
	Node* temp = head->next;
	while (temp != NULL ) {
		if (maxNode->data < temp->data)
			maxNode = temp;
		temp = temp->next;
	}
	return maxNode;
}
int countNodeBetweenMinMax(List l) {
	Node* temp = l.head;
	int cnt = 0;
	Node* mini = getMinNode(l.head);
	Node* maxi = getMaxNode(l.head);
	if (mini == NULL || maxi == NULL || mini == maxi)
		return 0;
	Node* start = l.head;
	Node* end = l.head;
	while (start != mini && start != maxi)
		start = start->next;
	while (end != mini && end != maxi)
		end = end->next;
	if (start == mini) {
		start = mini->next;
		end = maxi; 
	}
	else {
		start = maxi->next;
		end = mini;
	}
	while (start != end) {
		cnt++;
		start = start->next;
	}
	return cnt;
}
void show(List l) {
	Node* temp = l.head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
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
int main() {
	/*List l1, l2, l;
	int m = 0, n = 0;
	cin >> m >> n;
	init(l);
	createList(l1, m);
	createList(l2, n);
	mergeLists(l1, l2, l);
	cout << "danh sach sau khi tron la:\n";
	show(l);*/

	List l;
	init(l);
	int size = 0;
	cin >> size;
	createList(l, size);
	//quickSort(l);
	show(l);
	cout << endl;
	/*Node* mini = getMinNode(l.head);
	cout << mini->data << endl;
	Node* maxi = getMaxNode(l.head);
	cout << maxi->data << endl;*/
	cout << countNodeBetweenMinMax(l);
	release(l);
	return 0;
}