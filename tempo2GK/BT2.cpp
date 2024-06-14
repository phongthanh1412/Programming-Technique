#include<iostream>
#include<fstream>
using namespace std;

void readData(int**& arr1, int**& arr2, int& n, int& m) {
	fstream ifile;
	ifile.open("data2.txt", ios::in);
	if (ifile.eof()) {
		cout << "Error! File is not found!";
		return;
	}
	ifile >> n >> m;
	arr1 = new int* [n];
	for (int i = 0; i < n; i++)
		arr1[i] = new int[m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			ifile >> arr1[i][j];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr1[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	ifile >> m >> n;
	arr2 = new int* [m];
	for (int i = 0; i < m; i++)
		arr2[i] = new int[n];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			ifile >> arr2[i][j];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr2[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	ifile.close();
}
int** findTranposedMatrix(int** arr, int n, int m) {
	int** TranposedMatrix = new int* [m];
	for (int i = 0; i < m; i++)
		TranposedMatrix[i] = new int[n];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			TranposedMatrix[i][j] = arr[j][i];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << TranposedMatrix[i][j] << " ";
		}
		cout << endl;
	}
	return TranposedMatrix;
}
int** findProductMatrix(int** arr1, int** arr2, int n, int m) {
	int** productMatrix = new int* [n];
	for (int i = 0; i < n; i++)
		productMatrix[i] = new int[m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			productMatrix[i][j] = 0;
			for (int k = 0; k < n; k++) {
				productMatrix[i][j] += arr1[i][k] * arr2[k][j];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << productMatrix[i][j] << " ";
		}
		cout << endl;
	}
	return productMatrix;
}
void deleteMemory(int** arr, int n) {
	for (int i = 0; i < n; i++)
		delete[]arr[i];
	delete[]arr;
}
int main() {
	int n, m;
	int** arr1 = NULL;
	int** arr2 = NULL;
	readData(arr1, arr2, n, m);
	int** TranposedMatrix1 = findTranposedMatrix(arr1, n, m);
	int** TranposedMatrix2 = findTranposedMatrix(arr2, m, n);
	int** productMatrix = findProductMatrix(arr1, arr2, n, m);

	deleteMemory(productMatrix, n);
	deleteMemory(TranposedMatrix2, m);
	deleteMemory(TranposedMatrix1, n);
	deleteMemory(arr2, m);
	deleteMemory(arr1, n);
}