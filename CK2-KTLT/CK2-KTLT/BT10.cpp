#include<iostream>
using namespace std;

int** createMatrix(int m, int a, int b, int c) {
	int** matrix = new int* [m];
	int signRow = -1;
	for (int i = 0; i < m; i++) {
		int size = 0;
		if (i % 3 == 0)
			size = a;
		else if (i % 3 == 1)
			size = b;
		else size = c;
		int signCol = signRow;
		int num = size;
		matrix[i] = new int[size];
		for (int j = 0; j < size; j++) {
			matrix[i][j] = num * signCol;
			signCol *= -1;
			num--;
		}
		signRow *= -1;
	}
	return matrix;
}

void showMatrix(int** matrix, int m, int a, int b, int c) {
	for (int i = 0; i < m; i++) {
		int size = 0;
		if (i % 3 == 0)
			size = a;
		else if (i % 3 == 1)
			size = b;
		else size = c;
		for (int j = 0; j < size; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}
void releaseMatrix(int** matrix, int m) {
	for (int i = 0; i < m; i++) {
		delete[]matrix[i];	
	}
	delete matrix;
}

int main() {
	int m = 0, a = 0, b = 0, c = 0;
	cin >> m >> a >> b >> c;
	int** matrix = createMatrix(m, a, b, c);
	showMatrix(matrix, m, a, b, c);
	releaseMatrix(matrix, m);
	return 0;
}