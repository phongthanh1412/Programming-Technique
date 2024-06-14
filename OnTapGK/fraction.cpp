#include"fraction.h"

using namespace std;

void phanSo::findSum(phanSo ps1, phanSo ps2) {
	int sum = ps1.tu * ps2.mau + ps2.tu * ps1.mau;
	cout << "Tong cua " << ps1.tu << "/" << ps1.mau << " va " << ps2.tu << "/" << ps2.mau << " la: ";
	cout << sum << "/" << (ps1.mau * ps2.mau) << endl;
}
void phanSo::findAbstract(phanSo ps1, phanSo ps2) {
	int abstract = ps1.tu * ps2.mau - ps2.tu * ps1.mau;
	cout << "Hieu cua " << ps1.tu << "/" << ps1.mau << " va " << ps2.tu << "/" << ps2.mau << " la: ";
	cout << abstract << "/" << (ps1.mau * ps2.mau) << endl;
}
void phanSo::findProduct(phanSo ps1, phanSo ps2) {

	cout << "Tich cua " << ps1.tu << "/" << ps1.mau << " va " << ps2.tu << "/" << ps2.mau << " la: ";
	cout << (ps1.tu * ps2.tu) << "/" << (ps1.mau * ps2.mau) << endl;
}
void phanSo::findQuotient(phanSo ps1, phanSo ps2) {

	cout << "Thuong cua " << ps1.tu << "/" << ps1.mau << " va " << ps2.tu << "/" << ps2.mau << " la: ";
	cout << (ps1.tu * ps2.mau) << "/" << (ps1.mau * ps2.tu) << endl;
}
int phanSo::findGcd(int a, int b) {
	if (a == 0 || b == 0)
		return a + b;
	while (a != b) {
		if (a > b)
			a -= b;
		else b -= a;
	}
	return a;
}
void phanSo::findShorten(phanSo ps) {
	int temp = findGcd(ps.tu, ps.mau);
	cout << "Phan so " << ps.tu << "/" << ps.mau << " rut gon la : ";
	cout << ps.tu / temp << "/" << ps.mau / temp << endl;
}
void phanSo::isSimplified(phanSo ps) {
	int temp = findGcd(ps.tu, ps.mau);
	if (temp == 1)
		cout << "Phan so " << ps.tu << "/" << ps.mau << " da toi gian!\n";
	else cout << "Phan so " << ps.tu << "/" << ps.mau << " chua toi gian!\n";
}
void phanSo::compare(phanSo ps1, phanSo ps2) {
	if (ps1.tu * ps2.mau - ps2.tu * ps1.mau > 0)
		cout << "Phan so " << ps1.tu << "/" << ps1.mau << " lon hon phan so " << ps2.tu << "/" << ps2.mau << endl;
	else cout << "Phan so " << ps1.tu << "/" << ps1.mau << " be hon phan so " << ps2.tu << "/" << ps2.mau << endl;
}