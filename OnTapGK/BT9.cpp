#include<iostream>
using namespace std;

int** createMatrix(int& n) {
	int** arr1 = new int* [n];
	for (int i = 0; i < n; i++)
		arr1[i] = new int[n];
	cout << "Nhap ma tran:\n";
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr1[i][j];
	cout << "Ma tran:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr1[i][j] << " ";
		}
		cout << endl;
	}
	return arr1;
}
int** findproductedMatrix(int** arr1, int** arr2, int n) {
	int** arr = new int* [n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = 0;
			for (int k = 0; k < n; k++) {
				arr[i][j] += arr1[i][k] * arr2[k][j];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	return arr;
}
int** rotate90Type1(int** arr1, int n) {
	int** arr3 = new int* [n];
	for (int i = 0; i < n; i++)
		arr3[i] = new int[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			arr3[i][j] = arr1[j][i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n / 2; j++) {
			int temp = arr3[i][j];
			arr3[i][j] = arr3[i][n - 1 - j];
			arr3[i][n - 1 - j] = temp;
		}
	}
	cout << "Ma tran sau khi xoay 90 cung chieu kim dong ho:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr3[i][j] << " ";
		}
		cout << endl;
	}
	return arr3;
}
int** rotate90Type2(int** arr1, int n) {
	int** arr4 = new int* [n];
	for (int i = 0; i < n; i++)
		arr4[i] = new int[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			arr4[i][j] = arr1[j][i];
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < n; j++) {
			int temp = arr4[i][j];
			arr4[i][j] = arr4[n - i - 1][j];
			arr4[n - i - 1][j] = temp;
		}
	}
	cout << "Ma tran sau khi xoay 90 nguoc chieu kim dong ho:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr4[i][j] << " ";
		}
		cout << endl;
	}
	return arr4;
}

void deleteMemory(int** arr, int n) {
	for (int i = 0; i < n; i++)
		delete[]arr[i];
	delete[]arr;
}
int main() {
	int n;
	cin >> n;
	int** arr1 = createMatrix(n);
	//int** arr2 = createMatrix(n);
	//int** productedMatrix = findproductedMatrix(arr1, arr2, n);
	//int** arr3 = rotate90Type1(arr1, n);
	int** arr4 = rotate90Type2(arr1, n);

	//deleteMemory(productedMatrix, n);
	deleteMemory(arr4, n);
	//deleteMemory(arr3, n);
	//deleteMemory(arr2, n);
	deleteMemory(arr1, n);
	return 0;
}