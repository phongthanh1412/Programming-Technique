#include<iostream>
using namespace std;

int product(int a, int b) {
	if (b == 0)
		return 0;
	if (b == 1)
		return a;
	if (b > 0)
		return a + product(a, b - 1);
	else if (b < 0)
		return -product(a, -b);
}

int main() {
	int a = 0, b = 0;
	cin >> a >> b;
	cout << "Tich hai so " << a << " va " << b << " la: ";
	cout << product(a, b);
	return 0;
}