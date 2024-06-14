#include<iostream>
using namespace std;

struct phanSo {
	int tuso;
	int mauso;
	phanSo() {
		tuso = 0;
		mauso = 1;
	}
	phanSo(int a, int b) {
		tuso = a;
		mauso = b;
	}
	int ucln(int a, int b) {
		if (a == 0 || b == 0)
			return a + b;
		while (a != b) {
			if (a > b)
				a -= b;
			else
				b -= a;
		}
		return a;
	}
	void rutGonPhanSo(phanSo p) {
		int temp = ucln(p.tuso, p.mauso);
		cout << "Phan so sau khi rut gon la : ";
		cout << p.tuso / temp << "/" << p.mauso / temp << endl;
	}
	bool kiemTraToiGian(phanSo p) {
		int temp = ucln(p.tuso, p.mauso);
		if (temp == 1)
			return 1;
		return 0;
	}
	void tongPhanSo(phanSo p1, phanSo p2) {
		int sum = p1.tuso * p2.mauso + p1.mauso * p2.tuso;
		cout << "Tong hai phan so la: ";
		cout << sum << "/" << (p1.mauso * p2.mauso) << endl;
	}
	void hieuPhanSo(phanSo p1, phanSo p2) {
		int abstract = p1.tuso * p2.mauso - p1.mauso * p2.tuso;
		cout << "Hieu hai phan so la: ";
		cout << abstract << "/" << (p1.mauso * p2.mauso) << endl;
	}
	void tichPhanSo(phanSo p1, phanSo p2) {
		cout << "Tich hai phan so la: ";
		cout << p1.tuso * p2.tuso << "/" << p1.mauso * p2.mauso << endl;
	}
	void thuongPhanSo(phanSo p1, phanSo p2) {
		cout << "Thuong hai phan so la: ";
		cout << p1.tuso * p2.mauso << "/" << p1.mauso * p2.tuso << endl;
	}
	void soSanhPhanSo(phanSo p1, phanSo p2) {
		int temp1 = p1.tuso * p2.mauso;
		int temp2 = p2.tuso * p1.mauso;
		if (temp1 > temp2)
			cout << "Phan so " << p1.tuso << "/" << p1.mauso << " lon hon\n";
		else if (temp1 < temp2)
			cout << "Phan so " << p2.tuso << "/" << p2.mauso << " lon hon\n";
		else cout << "Phan so " << p1.tuso << "/" << p1.mauso << " bang " <<
			"phan so " << p2.tuso << "/" << p2.mauso << endl;
	}
};
int main() {
	int tu1, mau1, tu2, mau2;
	cin >> tu1 >> mau1 >> tu2 >> mau2;
	cout << "Phan so da cho la " << tu1 << "/" << mau1 << " va " << tu2 << "/" << mau2 << endl;
	phanSo p1(tu1, mau1);
	phanSo p2(tu2, mau2);
	phanSo ps;
	ps.tongPhanSo(p1, p2);
	ps.hieuPhanSo(p1, p2);
	ps.tichPhanSo(p1, p2);
	ps.thuongPhanSo(p1, p2);
	if (ps.kiemTraToiGian(p1))
		cout << "Phan so " << tu1 << "/" << mau1 << " da toi gian\n";
	else cout << "Phan so " << tu1 << "/" << mau1 << " chua toi gian\n";
	if (ps.kiemTraToiGian(p2))
		cout << "Phan so " << tu2 << "/" << mau2 << " da toi gian\n";
	else cout << "Phan so " << tu2 << "/" << mau2 << " chua toi gian\n";
	ps.rutGonPhanSo(p1);
	ps.rutGonPhanSo(p2);
	ps.soSanhPhanSo(p1, p2);
	return 0;
}