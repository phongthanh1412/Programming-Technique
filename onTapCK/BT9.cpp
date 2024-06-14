#include<iostream>
using namespace std;
int main() {
	int a[10] = { 7,6,9,1,2,4,2,6,3,1 };
	int* p = a;
	p = p + 1;
	*p = *p + 1;
	p += 1;
	*p += 1;
	*(p += 1);
	++p;
	++*p;
	*++p;
	p++;
	*p++;
	cout << *p;

}