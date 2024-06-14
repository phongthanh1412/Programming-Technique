#include<iostream>
using namespace std;

int** createMatrix(int& n, int& m) {
	int** arr2 = new int* [n];
	for (int i = 0; i < n; i++)
		arr2[i] = new int[m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr2[i][j];
	cout << "Ma tran ban dau la:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << arr2[i][j] << " ";
		cout << endl;
	}
	return arr2;
}
void deleteMemory(int** arr2, int n, int m) {
	for (int i = 0; i < n; i++)
		delete[] arr2[i];
	delete[]arr2;
}
void isEqualAndFindSum(int** arr2, int n, int m) {
	int sum1 = 0, sum2 = 0;
	if (n == m) {
		for (int i = 0; i < n; i++) {
			sum1 += arr2[i][i];
			sum2 += arr2[i][n - i - 1];
		}
		cout << "Tong cac phan tu tren duong cheo chinh la: " << sum1 << endl;
		cout << "Tong cac phan tu tren duong cheo phu la: " << sum2 << endl;
	}
	else cout << "Khong the tinh tong!\n";
}
int** findSumMatrix(int** arr2, int n, int m) {
	int** sumMatrix = new int* [n];
	for (int i = 0; i < n; i++)
		sumMatrix[i] = new int[m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			sumMatrix[i][j] = arr2[i][j] + arr2[i][j];
	}
	cout << "Ma tran tong la:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << sumMatrix[i][j] << " ";
		cout << endl;
	}
	return sumMatrix;
}
bool isPrime(int n) {
	if (n < 2)
		return 0;
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			return 0;
	return 1;
}
bool isPerfect(int n) {
	int sum = 0;
	for (int i = 1; i <= n; i++)
		if (n % i == 0)
			sum += i;
	return sum == n;
}
void isPrimeAndPerfect(int** arr2, int n, int m) {
	int sum = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			sum += arr2[i][j];
	if (isPrime(sum))
		cout << "Tong cac phan tu cua ma tran la so nguyen to!\n";
	else cout << "Tong cac phan tu cua ma tran khong la so nguyen to!\n";
	if (isPerfect(sum))
		cout << "Tong cac phan tu cua ma tran la so hoan hao!\n";
	else cout << "Tong cac phan tu cua ma tran khong la so hoan hao!\n";
}
int** finddeletedMatrix(int** arr2, int n, int m) {
	int** deletedMatrix = new int* [n - 1];
	for (int i = 0; i < n - 1; i++)
		deletedMatrix[i] = new int[m - 1];
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < m - 1; j++)
			deletedMatrix[i][j] = arr2[i][j];
	cout << "Ma tran sau khi xoa dong va cot cuoi la:\n";
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 1; j++)
			cout << deletedMatrix[i][j] << " ";
		cout << endl;
	}
	return deletedMatrix;
}
void isAccendingRowCol(int** arr2, int n, int m) {
	int flag1 = 0, flag2 = 0;
	for (int i = 0; i < n; i++) {
		flag1 = 1;
		for (int j = 0; j < m - 1; j++) {
			if (arr2[i][j] > arr2[i][j + 1])
				flag1 = 0;
		}
		if (flag1) {
			cout << "Ma tran co dong thu " << i << " tang dan: ";
			for (int j = 0; j < m; j++) {
				cout << arr2[i][j] << " ";
			}
			cout << endl;
		}	
	}
	if (flag1 == 0)
		cout << "Ma tran khong co dong tang dan\n";
	for (int j = 0; j < m; j++) {
		int flag2 = 1;
		for (int i = 0; i < n - 1; i++) {
			if (arr2[i][j] > arr2[i + 1][j])
				flag2 = 0;
		}
		if (flag2) {
			cout << "Ma tran co cot thu " << j << " tang dan: ";
			for (int i = 0; i < n; i++) {
				cout << arr2[i][j] << " ";
			}
			cout << endl;
		}	
	}
	if (flag2 == 0)
		cout << "Ma tran khong co cot tang dan\n";
}
int** findtransposedMatrix(int** arr2, int n, int m) {
	int** transposedMatrix = new int* [m];
	for (int i = 0; i < m; i++)
		transposedMatrix[i] = new int[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			transposedMatrix[j][i] = arr2[i][j];
	cout << "Ma tran chuyen vi la:\n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			cout << transposedMatrix[i][j] << " ";
		cout << endl;
	}
	return transposedMatrix;
}
void isSymmetricMatrix(int** arr2, int n, int m) {
	bool flag = 1;
	int** transposedMatrix = findtransposedMatrix(arr2, n, m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (transposedMatrix[i][j] != arr2[i][j]) {
				flag = 0;
				break;
			}
		}
	}
	if (flag)
		cout << "Ma tran da cho doi xung!\n";
	else cout << "Ma tran da cho khong doi xung!\n";
}
int** findDeletedMatrix(int** arr2, int n, int m, int pos) {
	int** deletedMatrix = new int* [n];
	for (int i = 0; i < n; i++)
		deletedMatrix[i] = new int[m - 1];
	for (int i = 0; i < n; i++) {
		int idx = 0;
		for (int j = 0; j < m; j++) {
			if (j != pos) {
				deletedMatrix[i][idx] = arr2[i][j];
				idx++;
			}
		}
	}
	cout << "Ma tran sau khi xoa cot thu " << pos << " la:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m - 1; j++)
			cout << deletedMatrix[i][j] << " ";
		cout << endl;
	}
	return deletedMatrix;
}
int main() {
	int n, m, pos;
	cin >> n >> m >> pos;
	int** matrix = createMatrix(n, m);
	/*isEqualAndFindSum(matrix, n, m);
	int** sumMatrix = findSumMatrix(matrix, n, m);
	isPrimeAndPerfect(matrix, n, m);
	int** deletedMatrix = finddeletedMatrix(matrix, n, m);
	isAccendingRowCol(matrix, n, m);*/
	//int** transposedMatrix = findtransposedMatrix(matrix, n, m);
	//isSymmetricMatrix(matrix, n, m);
	int** deletedMatrix = findDeletedMatrix(matrix, n, m, pos);

	deleteMemory(deletedMatrix, n, m - 1);
	//deleteMemory(transposedMatrix, n, m);
	/*deleteMemory(deletedMatrix, n - 1, m - 1);
	deleteMemory(sumMatrix, n, m);*/
	deleteMemory(matrix, n, m);
	return 0;
}