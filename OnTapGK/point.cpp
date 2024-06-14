#include"point.h"

using namespace std;

void point::findDistance(point A, point B) {
	float dis = sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
	cout << "Khoang cach giua " << "(" << A.x << ";" << A.y << ")" << " va diem "
		<< "(" << B.x << ";" << B.y << ")" << " la: " << (float)dis << endl;

}
void point::isStraightLine(point A, point B, point C) {
	if ((B.y - A.y) * (C.x - A.x) - (C.y - A.y) * (B.x - A.x) == 0)
		cout << "Ba diem " << "(" << A.x << ";" << A.y << ")" << "," << "(" << B.x << ";" << B.y << ")"
		<< "," << "(" << C.x << ";" << C.y << ")" << " thang hang\n";
	else cout << "Ba diem " << "(" << A.x << ";" << A.y << ")" << "," << "(" << B.x << ";" << B.y << ")"
		<< "," << "(" << C.x << ";" << C.y << ")" << " khong thang hang\n";
}
void point::findMiddle(point A, point B) {
	float a = (A.x + B.x) / 2;
	float b = (A.y + B.y) / 2;
	cout << "Trung diem cua " << "(" << A.x << ";" << A.y << ")" << " va diem "
		<< "(" << B.x << ";" << B.y << ")" << " la: " << "(" << a << ";" << b << ")" << endl;
}