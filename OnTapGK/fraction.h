#pragma once

#include<iostream>
using namespace std;

struct phanSo {
	int tu;
	int mau;
	phanSo() {
		tu = 0;
		mau = 1;
	}
	phanSo(int a, int b) {
		tu = a;
		mau = b;
	}
	void findSum(phanSo ps1, phanSo ps2);

	void findAbstract(phanSo ps1, phanSo ps2);

	void findProduct(phanSo ps1, phanSo ps2);

	void findQuotient(phanSo ps1, phanSo ps2);

	int findGcd(int a, int b);

	void findShorten(phanSo ps);

	void isSimplified(phanSo ps);

	void compare(phanSo ps1, phanSo ps2);
};

