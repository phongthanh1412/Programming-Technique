#include<iostream>
using namespace std;

struct Node {

    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

struct HangDoi {

    Node* head;
    int size;
    HangDoi() {
        head = NULL;
        size = 0;
    }
    //Thêm một phần tử vào cuối hàng đợi
    void push(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            size++;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        size++;
        return;
    }
    //Trả về giá trị của phần tử ở cuối hàng đợi
    int back() {
        if (head == NULL)
            return 1;
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        return temp->data;
    }
    //Trả về giá trị của phần tử ở đầu hàng đợi
    int front() {
        if (head == NULL)
            return 1;
        return head->data;
    }
    //Xóa phần tử ở đầu hàng đợi
    void pop() {
        if (size == 1) {
            head = NULL;
            size = 0;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
    }
    //Trả về kết quả cho biết hàng đợi có rỗng hay không
    bool empty() {
        return head == NULL;
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
    void print() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};


int main() {
    HangDoi myQueue;
    cout << "queue ban dau: ";
    myQueue.push(6);
    myQueue.push(8);
    myQueue.push(9);
    myQueue.push(3);
    myQueue.print();

    cout << "queue sau khi pop phan tu dau: ";
    myQueue.pop();
    myQueue.print();

    cout << "phan tu cuoi cua queue: ";
    cout << myQueue.back();
    cout << endl;

    cout << "queue sau khi push them 10: ";
    myQueue.push(10);
    myQueue.print();

    cout << "phan tu dau cua queue: ";
    cout << myQueue.front();

    myQueue.release();
    return 0;
}