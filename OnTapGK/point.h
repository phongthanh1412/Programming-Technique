#pragma once

#include<iostream>
using namespace std;

struct point {
	float x;
	float y;
	point() {
		x = 0;
		y = 0;
	}
	point(int a, int b) {
		x = a;
		y = b;
	}
	void findDistance(point A, point B);

	void isStraightLine(point A, point B, point C);

	void findMiddle(point A, point B);
};