#include <iostream>
#include "perfect_num.h"
using namespace std;
int main() {
	int n = 0;
	cout << "Nhap so n: ";
	cin >> n;
	if (checkNum(n))
		cout << n << " la so hoan hao!";
	else cout << n << " khong la so hoan hao!";
	return 0;
}