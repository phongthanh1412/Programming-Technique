#include<iostream>
using namespace std;

void hanoiTower(int size, char a, char b, char c) {
    if (size == 1) {
        cout << "Move disc " << size << " from " << a << " to " << c << endl;
        return;
    }
    hanoiTower(size - 1, a, c, b);
    cout << "Move disc " << size << " from " << a << " to " << c << endl;
    hanoiTower(size - 1, b, a, c);
}
int main() {
    hanoiTower(3, 'A', 'B', 'C');
    return 0;
}
    