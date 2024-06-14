#include<iostream>
using namespace std;

int findSum(int n) {
	if (n < 10)
		return n;
	else {
		int surplus = n % 10;
		return surplus + findSum(n / 10);
	}
}

int main() {
	int n = 0;
	cin >> n;
	cout << "Tong cac chu so cua " << n << " La: ";
	cout << findSum(n);
	return 0;
}