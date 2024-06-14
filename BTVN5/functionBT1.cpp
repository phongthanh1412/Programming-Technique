#include"functionBT1.h"

using namespace std;

int** createArray(int& n, int& m) {
	int** arr = new int* [n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	cout << "Mang 2 chieu ban dau: \n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
	return arr;
}

void isEqualAndFindSum(int** arr, int n, int m) {
	int sum1 = 0, sum2 = 0;
	if (n == m) {
		for (int i = 0; i < n; i++)
			sum1 += arr[i][i];
		for (int i = 0; i < n; i++)
			sum2 += arr[i][n - i - 1];
		cout << "Tong phan tu tren duong cheo chinh la: " << sum1 << endl;
		cout << "Tong phan tu tren duong cheo phu la: " << sum2 << endl;
	}
	else cout << "Mang 2 chieu da cho khong la ma tran vuong!\n";
}
int** findMatrixSum(int** arr, int n, int m) {
	int** matrixSum = new int* [n];
	for (int i = 0; i < n; i++)
		matrixSum[i] = new int[m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			matrixSum[i][j] = arr[i][j] + arr[i][j];
	cout << "Ma tran tong la: \n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << matrixSum[i][j] << " ";
		cout << endl;
	}
	return matrixSum;
}
bool isPrime(int n) {
	if (n < 2)
		return 0;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)
			return 0;
	}
	return 1;
}
bool isPerfectNum(int n) {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0)
			sum += i;
	}
	return sum == n;
}
void particlesOfMatrix(int** arr, int n, int m) {
	int sum = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			sum += arr[i][j];
	if (isPrime(sum))
		cout << "Tong cac phan tu cua ma tran la mot so nguyen to!\n";
	else cout << "Tong cac phan tu cua ma tran khong la mot so nguyen to!\n";
	if (isPerfectNum(sum))
		cout << "Tong cac phan tu cua ma tran la mot so hoan hao!\n";
	else cout << "Tong cac phan tu cua ma tran khong la mot so hoan hao!\n";

}
int** deleteMatrix(int** arr, int n, int m) {
	int** deleted_matrix = new int* [n - 1];
	for (int i = 0; i < n - 1; i++)
		deleted_matrix[i] = new int[m - 1];
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < m - 1; j++)
			deleted_matrix[i][j] = arr[i][j];
	cout << "Ma tran sau khi xoa cot cuoi va dong cuoi la: \n";
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 1; j++)
			cout << deleted_matrix[i][j] << " ";
		cout << endl;
	}
	return deleted_matrix;
}
void deleletMemory(int** arr, int n, int m) {

	for (int i = 0; i < n; i++)
		delete[]arr[i];
	delete[]arr;

}