#include<iostream>
using namespace std;

char* toBitString(int N) {
	if (N == 0) {
		char* res = new char[2];
		res[0] = '0';
		res[1] = '\0';
		return res;
	}
	int cnt = 0;
	int temp = N;
	while (temp > 0) {
		cnt++;
		temp /= 2;
	}
	char* res = new char[cnt + 1];
	res[cnt] = '\0';
	for (int i = cnt - 1; i >= 0; i--) {
		if (N % 2 == 1)
			res[i] = '1';
		else res[i] = '0';
		N /= 2;
	}
	return res;
}

int main() {
	int N = 0;
	cin >> N;
	char* res = toBitString(N);
	cout << res;
	delete[]res;
}