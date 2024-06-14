#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

struct SinhVien
{
	int mssv;
	char* ten;
};

void nhap(SinhVien*& sv, int& n) {
	sv = new SinhVien;
	cout << "Nhap mssv: ";
	cin >> sv->mssv;
	cin.ignore();
	sv->ten = new char[100];
	cout << "Nhap ten: ";
	cin.getline(sv->ten, 100);
}

void xuat(const SinhVien* sv) {
	cout << "Ten: " << sv->ten << endl;
	cout << "MSSV: " << sv->mssv << endl;
}

void copy1(SinhVien*& sv_des, const SinhVien*& sv_src) {
	sv_des = new SinhVien;
	sv_des->mssv = sv_src->mssv;
	int length = strlen(sv_src->ten);
	sv_des->ten = new char[length + 1];
	for (int i = 0; i < length; i++) {
		sv_des->ten[i] = sv_src->ten[i];
	}
}

void copy2(SinhVien *sv_des, SinhVien* sv_src) {

	sv_des->mssv = sv_src->mssv;
	int length = strlen(sv_src->ten); 
	sv_des->ten = new char[length + 1];
	strcpy(sv_des->ten, sv_src->ten);
}
void GiaiPhong(SinhVien *sv_des) {
	if (sv_des != NULL)
		if (sv_des->ten != NULL) 
			delete[] sv_des->ten;
}
int main() {

	SinhVien* sv1;
	int n;
	nhap(sv1, n);
	xuat(sv1);
	SinhVien* sv2;
	SinhVien* sv3 = new SinhVien;
	copy1(sv2, sv3);
	xuat(sv2);
	copy2(sv3, sv1);
	xuat(sv3);
	delete sv1;
	delete sv2;
	delete sv3;
	GiaiPhong(sv3);
	return 0;
}