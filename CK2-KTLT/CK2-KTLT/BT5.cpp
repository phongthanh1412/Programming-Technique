#include<iostream>
using namespace std;

template<typename T> void myswap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}
template<typename T> bool accending(T a, T b) {
	return a <= b;
}
template<typename T> bool deccending(T a, T b) {
	return a >= b;
}

template<typename T> void dummySort(T a[], T n, bool (*compare)(T, T)) {
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (!compare(a[i], a[j]))
				myswap(a[i], a[j]);
}
template<typename T>void show(T a[], T n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

int main() {
	int a[] = { 7,8,1,3,6,5 };
	dummySort(a, 6, accending);
	show(a, 6);
	dummySort(a, 6, deccending);
	show(a, 6);
}