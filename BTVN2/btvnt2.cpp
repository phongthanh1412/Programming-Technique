#include<iostream>
#include<math.h>
using namespace std;

void createArray(int* &a, int& n) {
	for (int i = 0; i < n; i++)
		cin >> *(a + i);
	for (int i = 0; i < n; i++)
		cout << *(a + i) << " ";
	cout << endl;
}
void isAcending(int*& a, int& n) {
	bool flag = 1;
	for (int i = 0; i < n - 1; i++) {
		if (*(a + i) > *(a + i + 1)) {
			flag = 0;
			break;
		}	
	}
	if (flag)
		cout << "Mang tang dan!";
	else cout << "Mang khong tang dan!";
}
int findSum(int*& a, int& n) {
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += *(a + i);
	return sum;
}
int findMax(int*& a, int& n) {
	int maxi = *a;
	for (int i = 1; i < n; i++)
		if (*(a + i) > maxi)
			maxi = *(a + i);
	return maxi;
}
bool isPrime(int& x) {
	if (x < 2)
		return 0;
	for (int i = 2; i <= sqrt(x); i++)
		if (x % i == 0)
			return 0;
	return 1;
}
void findPrimeNum(int*& a, int& n) {
	int cnt = 0;
	for (int i = 0; i < n; i++) 
		if (isPrime(*(a + i))) 
			cnt++;
	if (cnt > 0) {
		cout << "Co " << cnt << " so nguyen to la ";
		for (int i = 0; i < n; i++)
			if (isPrime(*(a + i)))
				cout << *(a + i) << " ";
		cout << endl;
	}
	else cout << "Khong ton tai so nguyen to!" << endl;
}
void reverseArray(int*& a, int& n) {
	cout << "Mang sau khi dao nguoc la ";
	for (int i = n - 1; i >= 0; i--) {
		cout << *(a + i) << " ";
	}
	cout << endl;
}
int main() {
	int n;
	cin >> n;
	int* a = new int[n];

	createArray(a, n);
	isAcending(a, n);
	cout << endl;
	cout << "Tong cac phan tu cua mang la " << findSum(a, n) << endl;
	cout << "Phan tu lon nhat cua mang la " << findMax(a, n) << endl;
	findPrimeNum(a, n);
	reverseArray(a, n);

	delete[] a;
	
	return 0;
}