#include<iostream>
using namespace std;

template<typename T> 
struct PhanSo {
	T tuso;
	T mauso;
	PhanSo() {
		tuso = 0;
		mauso = 1;
	}
	PhanSo(T a, T b) {
		this->tuso = a;
		this->mauso = b;
	}
	void Tong(PhanSo ps1, PhanSo ps2) {
		T tu = (ps1.tuso * ps2.mauso + ps2.tuso * ps1.mauso);
		T mau = (ps1.mauso * ps2.mauso);
		cout << "Tong hai phan so la: ";
		cout << tu << "/" << mau << endl;
	}
	void Hieu(PhanSo ps1, PhanSo ps2) {
		T tu = (ps1.tuso * ps2.mauso - ps2.tuso * ps1.mauso);
		T mau = (ps1.mauso * ps2.mauso);
		cout << "Hieu hai phan so la: ";
		cout << tu << "/" << mau << endl;
	}
	void Tich(PhanSo ps1, PhanSo ps2) {
		T tu = (ps1.tuso * ps2.tuso);
		T mau = (ps1.mauso * ps2.mauso);
		cout << "Tich hai phan so la: ";
		cout << tu << "/" << mau << endl;
	}
	void Thuong(PhanSo ps1, PhanSo ps2) {
		T tu = (ps1.tuso * ps2.mauso);
		T mau = (ps1.mauso * ps2.tuso);
		cout << "Thuong hai phan so la: ";
		cout << tu << "/" << mau << endl;
	}

};

int main() {
	cout << "Khi tu so va mau so la integer!" << endl;
	int tu1, mau1, tu2, mau2;
	cin >> tu1 >> mau1 >> tu2 >> mau2;
	cout << "Phan so da cho la " << tu1 << "/" << mau1 << " va " << tu2 << "/" << mau2 << endl;
	PhanSo <int> ps1(tu1, mau1);
	PhanSo <int> ps2(tu2, mau2);
	ps1.Tong(ps1, ps2);
	ps1.Hieu(ps1, ps2);
	ps1.Tich(ps1, ps2);
	ps1.Thuong(ps1, ps2);

	cout << endl;
	cout << "Khi tu so va mau so la float!" << endl;
	float tu3, mau3, tu4, mau4;
	cin >> tu3 >> mau3 >> tu4 >> mau4;
	cout << "Phan so da cho la " << tu3 << "/" << mau3 << " va " << tu4 << "/" << mau4 << endl;
	PhanSo <float> ps3(tu3, mau3);
	PhanSo <float> ps4(tu4, mau4);
	ps3.Tong(ps3, ps4);
	ps3.Hieu(ps3, ps4);
	ps3.Tich(ps3, ps4);
	ps3.Thuong(ps3, ps4);

	return 0;
}