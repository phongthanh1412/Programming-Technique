#include<iostream>
using namespace std;

template<typename T> void tranpose(T* arr, int size, int a, int b) {
	for (int i = 0; i < size; i++) {
		if (i == a) {
			for (int j = i; j < size; j++) {
				if (j == b) {
					T temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
	}
}
template<typename T> void print(T* arr, int size) {
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main() {
	int a = 0, b = 0;
	cout << "Nhap vi tri can chuyen doi: ";
	cin >> a >> b;
	int arr1[] = { 3,7,2,4,9,5 };
	cout << "Mang integer ban dau: " << endl;
	print(arr1, 6);
	tranpose(arr1, 6, a, b);
	cout << "Mang integer luc sau: " << endl;
	print(arr1, 6);

	cout << endl;
	cout << "Mang float ban dau: " << endl;
	float arr2[] = { 3.6,7.5,2.2,4.6,9.7,5.8 };
	print(arr2, 6);
	tranpose(arr2, 6, a, b);
	cout << "Mang float luc sau: " << endl;
	print(arr2, 6);
	return 0;
}