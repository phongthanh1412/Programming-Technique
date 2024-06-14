#include<iostream>
#include<math.h>
using namespace std;

struct toaDo {
	float kinhdo;
	float vido;
	toaDo() {
		kinhdo = 0;
		vido = 0;
	}
	toaDo(float x, float y) {
		kinhdo = x;
		vido = y;
	}
	void khoangCach(toaDo A, toaDo B) {
		float dis = sqrt(pow(A.kinhdo - B.kinhdo, 2) + pow(A.vido - B.vido, 2));
		cout << "Khoang cach giua hai diem A va B la: " << (float)dis << endl;
	}
	bool kiemTraThangHang(toaDo A, toaDo B, toaDo C) {
		return (B.vido - A.vido) * (C.kinhdo - A.kinhdo) - (C.vido - A.vido) * (B.kinhdo - A.kinhdo) == 0;
	}
	void trungDiem(toaDo A, toaDo B) {
		float x = (A.kinhdo + B.kinhdo) / 2;
		float y = (A.vido + B.vido) / 2;
		cout << "Trung diem cua hai diem A va B la: " << "(" << (float)x << ";" << (float)y << ")" << endl;
	}
};
int main() {
	float kd1, vd1, kd2, vd2, kd3, vd3;
	cin >> kd1 >> vd1 >> kd2 >> vd2 >> kd3 >> vd3;
	cout << "Toa do A va B la " << "(" << kd1 << ";" << vd1 << ")" << " va "
		<< "(" << kd2 << ";" << vd2 << ")" << endl;
	toaDo diemA(kd1, vd1);
	toaDo diemB(kd2, vd2);
	toaDo diemC(kd3, vd3);
	toaDo diem;
	diem.khoangCach(diemA, diemB);

	if (diem.kiemTraThangHang(diemA, diemB, diemC))
		cout << "Ba diem " << "(" << kd1 << ";" << vd1 << ")" << " , "
		<< "(" << kd2 << ";" << vd2 << ")" << " , " << "(" << kd3 << ";" << vd3 << ")" << " thang hang\n";
	else cout << "Ba diem " << "(" << kd1 << ";" << vd1 << ")" << " , "
		<< "(" << kd2 << ";" << vd2 << ")" << " , " << "(" << kd3 << ";" << vd3 << ")"
		<< " khong thang hang\n";
	diem.trungDiem(diemA, diemB);

	return 0;
}