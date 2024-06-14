#include<iostream>
using namespace std;

int countNumber(int* arr, int idx, int size, int val, int cnt) {
	if (idx >= size)
		return cnt;
	if (arr[idx] == val)
		cnt++;
	return countNumber(arr, idx + 1, size, val, cnt);
}

void init(int*& arr, int size) {
	arr = new int[size];
	for (int i = 0; i < size; i++)
		cin >> arr[i];
}

void printArray(int* arr, int idx, int size) {
	if (idx >= size)
		return;
	cout << arr[idx] << " ";
	printArray(arr, idx + 1, size);
}

void release(int* arr) {
	delete[]arr;
}

int main() {
	int* arr = NULL;
	int size = 0, cnt = 0, val = 0;

	cout << "Nhap kich thuoc: ";
	cin >> size;
	init(arr, size);
	cout << "Mang ban dau la: ";
	printArray(arr, 0, size);
	cout << endl;

	cout << "Nhap phan tu can dem: ";
	cin >> val;
	cout << "So luong phan tu " << val << " trong mang la : ";
	cout << countNumber(arr, 0, 6, 2, cnt);

	release(arr);
	return 0;
}