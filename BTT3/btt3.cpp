#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;
void nhap(int** a, int& m, int& n) {
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
}
void xuat(int** a, int m, int n) {
	fstream output;
	output.open("result.txt", ios::out);
	if (output.eof()) {
		cout << "Error!";
		return;
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
			output << a[i][j] << " ";
		}
		cout << endl;
		output << endl;
	}
	output.close();
}
void giaiphong(int** a, int& m) {
	for (int i = 0; i < m; i++)
		delete[]a[i];
	delete[]a;
}
bool ktnguyento(int x) {
	if (x < 2)
		return 0;
	for (int i = 2; i <= sqrt(x); i++) {
		if (x % i == 0)
			return 0;
	}
	return 1;
}
void tinhTong(int** a, int m, int n) {
	int sum = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			sum += a[i][j];
	cout << "Tong la " << sum << endl;
	cout << sum << endl;
	if (ktnguyento(sum))
		cout << sum << " la so nguyen to" << endl;
	else cout << sum << " khong la so nguyen to" << endl;
}
void sapxephang(int* a, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

void sapXepMatran(int** a, int m, int n) {
	for (int i = 0; i < m; i++) {
		sapxephang(a[i], n);
	}
}
int main() {
	int m, n;
	cin >> m >> n;

	int** a = new int* [m];
	for (int i = 0; i < m; i++)
		a[i] = new int[n];

	nhap(a, m, n);
	xuat(a, m, n);
	tinhTong(a, m, n);
	sapXepMatran(a, m, n);
	xuat(a, m, n);
	giaiphong(a, m);
	return 0;
}