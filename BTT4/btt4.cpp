#include<iostream>
using namespace std;

struct Node
{
	int score;
	Node* next;
};

struct ListNode
{
	int size;
	Node* head;
};
//Tạo một node bất ky
Node* createNewNode(int score) {
	Node* newNode = new Node();
	newNode->score = score;
	newNode->next = NULL;
	return newNode;
}
//Thêm node đã tạo vào cuối
void addNode(ListNode& l, int score) {
	Node* newNode = createNewNode(score);
	if (!l.head)
		l.head = newNode;
	else {
		Node* cur = l.head;
		while (cur->next)
			cur = cur->next;
		cur->next = newNode;
		l.size++;
	}
}
//In ra danh sách liên kết
void printListNode(ListNode& l) {
	Node* cur = l.head;
	while (cur) {
		cout << cur->score << " ";
		cur = cur->next;
	}
	cout << endl;
}
//Xoá phần tử có giá trị cho trước
void deleteNode(ListNode& l, int val_remove) {
	Node* cur = l.head;
	Node* prev = NULL;
	//Không tồn tại node cần xoá
	if (!cur) {
		cout << "Node does not exist!\n";
		return;
	}
	//Node cần xoá ở vị trí đầu tiên
	if (cur && cur->score == val_remove) {
		l.head = cur->next;
		delete cur;
		l.size--;
		return;
	}
	//Node cần xoá ở vị trí bất kỳ
	while (cur && cur->score != val_remove) {
		prev = cur;
		cur = cur->next;
	}
	if (!cur) {
		cout << "Node does not exist!\n";
		return;
	}
	prev->next = cur->next;
	delete cur;
	l.size--;
}
//Giải phóng bộ nhớ cho danh sách liên kết
void deleteMemory(ListNode& l) {
	Node* cur = l.head;
	while (cur) {
		Node* tmp = cur;
		cur = cur->next;
		delete tmp;
	}
	l.head = NULL;
	l.size = 0;
}
int main() {

	ListNode l;
	l.head = NULL;
	l.size = 0;
	int val_remove;
	int n;
	cout << "Nhap so node: ";
	cin >> n;
	cout << "Nhap gia tri can xoa: ";
	cin >> val_remove;
	for (int i = 1; i < 10; i++)
		addNode(l, i);
	//In danh sách trước khi xoá
	printListNode(l);
	deleteNode(l, val_remove);
	//In danh sách sau khi xoá
	printListNode(l);
	deleteMemory(l);
	return 0;

}