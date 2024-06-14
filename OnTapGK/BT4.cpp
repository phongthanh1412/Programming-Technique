#include"point.h"

int main() {
	float x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	point A(x1, y1);
	point B(x2, y2);
	point C(x3, y3);
	point P;
	P.findDistance(A, B);
	P.isStraightLine(A, B, C);
	P.findMiddle(A, B);
	return 0;
}