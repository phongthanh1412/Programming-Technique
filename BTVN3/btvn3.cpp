#include<iostream>

using namespace std;

int** printMatrix(int& length, int& width) {

	//Khởi tạo ma trận
	int** matrix = new int* [length];
	for (int i = 0; i < length; i++)
		matrix[i] = new int[width];
	for (int i = 0; i < length; i++)
		for (int j = 0; j < width; j++)
			cin >> matrix[i][j];
	//In ra ma trận
	cout << "Ma tran ban dau la: " << endl;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
	return matrix;
}

void checkAccendingColRow(int** matrix, int length, int width) {

	//Kiểm tra dòng tăng dần và in ra cột đó (nếu có)
	for (int i = 0; i < length; i++) {
		bool flag = 1;
		for (int j = 0; j < width - 1; j++) {
			if (matrix[i][j] > matrix[i][j + 1])
				flag = 0;
		}
		if (flag) {
			cout << "Dong tang dan la dong: " << i << endl;
			for (int j = 0; j < width; j++)
				cout << matrix[i][j] << " ";
			cout << endl;
		}
	}
	//Kiểm tra cột tăng dần và in ra dòng đó (nếu có)
	for (int j = 0; j < width; j++) {
		bool flag = 1;
		for (int i = 0; i < length - 1; i++) {
			if (matrix[i][j] > matrix[i + 1][j])
				flag = 0;
		}
		if (flag) {
			cout << "Cot tang dan la cot: " << j << endl;
			for (int i = 0; i < length; i++)
				cout << matrix[i][j] << endl;
			cout << endl;
		}
	}
}

int** matrixTranpose(int** matrix, int length, int width) {

	//Cấp phát động ma trận chuyển vị
	int** tranposed_matrix = new int* [width];
	for (int i = 0; i < width; i++)
		tranposed_matrix[i] = new int[length];
	//Tạo ma trận chuyển vị
	for (int i = 0; i < width; i++)
		for (int j = 0; j < length; j++)
			tranposed_matrix[i][j] = matrix[j][i];
	//In ra ma trận chuyển vị
	cout << "Ma tran chuyen vi la: " << endl;
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < length; j++)
			cout << tranposed_matrix[i][j] << " ";
		cout << endl;
	}
	return tranposed_matrix;
}

int** sumOfMatrix(int** matrix, int length, int width) {

	//Cấp phát động ma trận tổng
	int** sum_matrix = new int* [length];
	for (int i = 0; i < length; i++)
		sum_matrix[i] = new int[width];
	//Tạo ma trận tổng
	for (int i = 0; i < length; i++)
		for (int j = 0; j < width; j++)
			sum_matrix[i][j] = matrix[i][j] + matrix[i][j];
	//In ma trận tổng
	cout << "Ma tran tong la: " << endl;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++)
			cout << sum_matrix[i][j] << " ";
		cout << endl;
	}
	return sum_matrix;
}

bool isSymmetricMatrix(int** matrix, int length, int width) {

	//Nếu không là ma trận vuông thì trả về sai
	if (length != width)
		return 0;
	//Nếu là ma trận vuông thì tiếp tục
	int** tranposed_matrix = matrixTranpose(matrix, length, width);
	for (int i = 0; i < length; i++)
		for (int j = 0; j < width; j++)
			if (matrix[i][j] != tranposed_matrix[i][j])
				return 0;
	return 1;
}

int** deleteCol(int** matrix, int length, int width, int value) { //value là vị trí cần xoá

	int** deleleted_matrix = new int* [length];
	for (int i = 0; i < length; i++)
		deleleted_matrix[i] = new int[width - 1];
	for (int i = 0; i < length; i++) {
		int idx = 0;
		for (int j = 0; j < width; j++) {
			if (j != value) {
				deleleted_matrix[i][idx] = matrix[i][j];
				idx++;
			}
		}
	}
	cout << "Ma tran sau khi xoa la: " << endl;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width - 1; j++)
			cout << deleleted_matrix[i][j] << " ";
		cout << endl;
	}
	return deleleted_matrix;
}
int main() {

	int length, width, value;
	cin >> length >> width >> value;
	int** matrix = printMatrix(length, width);
	checkAccendingColRow(matrix, length, width);
	int** tranposed_matrix = matrixTranpose(matrix, length, width);
	int** sum_matrix = sumOfMatrix(matrix, length, width);
	if (isSymmetricMatrix(matrix, length, width))
		cout << "Ma tran ban dau doi xung" << endl;
	else cout << "Ma tran ban dau khong doi xung" << endl;
	int** deleleted_matrix = deleteCol(matrix, length, width, value);

	for (int i = 0; i < length; i++)
		delete[]deleleted_matrix[i];
	delete[]deleleted_matrix;

	for (int i = 0; i < length; i++)
		delete[]sum_matrix[i];
	delete[]sum_matrix;

	for (int i = 0; i < width; i++)
		delete[]tranposed_matrix[i];
	delete[]tranposed_matrix;

	for (int i = 0; i < length; i++)
		delete[]matrix[i];
	delete[]matrix;

	return 0;
}