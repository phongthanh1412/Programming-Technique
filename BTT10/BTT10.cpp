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

struct NganXep {

    Node* head = NULL;
    int size = 0;

    //Trả về kết quả cho biết ngăn xếp có rỗng hay không
    bool empty() {
        return head == NULL;
    }

    //Thêm một phần tử vào cuối ngăn xếp
    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    //Trả về giá trị của phần tử ở cuối ngăn xếp
    int top() {
        return head->data;
    }

    //Xóa phần tử ở cuối ngăn xếp
    void pop() {
        int data = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    //Giải phóng bộ nhớ
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
};

template <class T>

T findMax(T* arr, int idx, int size, T maxi) {
    if (size == 1)
        return maxi;
    if (idx >= size)
        return maxi;
    if (arr[idx + 1] > maxi)
        maxi = arr[idx + 1];
    return findMax(arr, idx + 1, size, maxi);

}
int main() {
    int arr1[] = { 2,7,4,3,1 };
    float arr2[] = { 2.5,7.8,4.1,3.7,9.2 };
    int maxi1 = arr1[1];
    cout << findMax(arr1, 0, 5, maxi1);
    cout << endl;
    float maxi2 = arr2[0];
    cout << findMax(arr2, 0, 5, maxi2);
    return 0;
}