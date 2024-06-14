#include<iostream>
#include<ctime>
#include<cstdlib>
#include<string>

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

    Node* head;
    int size;
    NganXep() {
        head = NULL;
        size = 0;
    }
    //Thêm một phần tử vào cuối ngăn xếp
    void push(int data) {
        Node* newNode = new Node(data);
        if (head == NULL && size <= 0) {
            head = newNode;
            size++;
            return;
        }
        newNode->next = head;
        head = newNode;
        size++;
        return;
    }
    //Xóa phần tử ở cuối ngăn xếp
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
        return;
    }
    //Trả về giá trị của phần tử ở cuối ngăn xếp
    int top() {
        if (head == NULL)
            return -1;
        return head->data;
    }
    //Trả về kết quả cho biết ngăn xếp có rỗng hay không
    bool empty() {
        return head == NULL;
    }
};
void showNode(Node* head) {
    if (head == NULL)
        return;
    cout << head->data << " ";
    return showNode(head->next);

}
void showList(NganXep& nx) {
    return showNode(nx.head);
}
// Bai 4
void deleteNode(NganXep& nx, int size) {
    if (nx.head == NULL)
        return;
    nx.pop();
    deleteNode(nx, nx.size - 1);
}
void release(NganXep& nx) {
    Node* temp = nx.head;
    while (temp != NULL) {
        Node* cur = temp;
        temp = temp->next;
        delete cur;
    }
    nx.head = NULL;
    nx.size = 0;
}

void randomList(NganXep& nx, int n) {
    if (n <= 0)
        return;
    int data = rand() % n + 1;
    nx.push(data);
    randomList(nx, n - 1);
}
// Bai 5

// Bai 6
int countString(string& s1, string& s2) {
    int cnt = 0;
    int i = 0;
    while (i < s1.length()) {
        int pos = s1.find(s2, i);
        if (pos == string::npos)
            break;
        else {
            cnt++;
            i = pos + s2.length();
        }
    }
    return cnt;
}

int main() {
    //Bai 1 2 3 
    cout << "Bai 1,2,3\n";
    NganXep nx;
    int n = 0;
    cout << "Nhap so luong nut can random: ";
    cin >> n;
    srand(time(0));
    cout << "Ngan xep da random la:\n";
    randomList(nx, n);
    showList(nx);
    cout << endl;
    ////Bai 5
    //string s;
    //cin >> s;
    //cout << readNumber(s);
    //Bai 4
    cout << "Bai 4\n";
    deleteNode(nx, n);
    cout << "Ngan xep da xoa la:\n";
    showList(nx);
    release(nx);
    //Bai 5
    
    //Bai 6
    cout << "Bai 6\n";
    string s1 = "acdedefacdejgde";
    string s2 = "de";
    cout << "Tong so lan xuat hien cua chuoi s2 trong s1 la: ";
    cout << countString(s1, s2);
    return 0;
}