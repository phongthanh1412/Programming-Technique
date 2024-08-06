#include<iostream>
using namespace std;

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void show(int* arr, int n) {
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}
void bubbleSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; i++) {
			if (arr[i] > arr[j])
				swap(arr[i], arr[j]);	
		}
	}
}
void selectionSort(int arr[], int n) {
	int idx = 0;
	for (int i = 0; i < n - 1; i++) {
		idx = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[idx] > arr[j])
				idx = j;
		}
		swap(arr[i], arr[idx]);
	}
}
void mergeArr(int a[], int b[], int c[], int n, int m) {
	int idx1 = 0, idx2 = 0, idx3 = 0;
	while (idx1 < n && idx2 < m) {
		if (a[idx1] < b[idx2]) {
			c[idx3++] = a[idx1++];
		}
		else c[idx3++] = b[idx2++];
	}
	if (idx1 < n) {
		for (int i = idx1; i < n; i++) {
			c[idx3++] = a[i];
		}
	}
	else {
		for (int i = idx2; i < m; i++) {
			c[idx3++] = b[i];
		}
	}
}
int* mergeSort(int a[], int l, int r) {
	if (l == r) {
		int* temp = new int[1];  
		temp[0] = a[l];
		return temp;
	}
	int mid = (l + r) / 2;
	int* arr1 = mergeSort(a, l, mid);
	int* arr2 = mergeSort(a, mid + 1, r);
	int n1 = mid - l + 1;
	int n2 = r - mid;
	int* arr3 = new int[n1 + n2];
	mergeArr(arr1, arr2, arr3, n1, n2);
	delete[] arr1;
	delete[] arr2;
	return arr3;
}

int main() {
	/*int arr1[] = { 1,3,5,8,8 };
	int arr2[] = { 3,4,6,9 };*/
	int n = 0;
	cin >> n;
	int* arr3 = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr3[i];
	arr3 = mergeSort(arr3, 0, n - 1);
	show(arr3, n);
	delete[] arr3;
	/*insertionSort(arr1, 6);
	show(arr1, 6);*/
	return 0;
}
