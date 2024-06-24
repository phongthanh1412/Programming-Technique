#include<iostream>
using namespace std;
int countNumChar(char* str) {
	int cnt = 0;
	while (*str != '\0') {
		if (*str >= '0' && *str <= '9')
			cnt++;
		str++;
	}
	return cnt;
}
int countNumCharRecursion(char* str) {
	if (*str == '\0')
		return 0;
	if (*str >= '0' && *str <= '9')
		return 1 + countNumCharRecursion(str + 1);
	else return countNumCharRecursion(str + 1);
}
int findLength(char* s) {
	int cnt = 0;
	while (*s != '\0') {
		cnt++;
		s++;
	}
	return cnt;
}

char* addString(char* s1, char* s2) {
	int len_s1 = findLength(s1);
	int len_s2 = findLength(s2);
	int len = 0;
	if (len_s1 > len_s2)
		len = len_s1;
	else len = len_s2;
	char* res = new char[len + 2];
	res[len + 1] = '\0';
	int i = len_s1 - 1, j = len_s2 - 1, k = len, carry = 0;
	while (i >= 0 || j >= 0 || carry > 0) {
		int d1 = (i >= 0) ? s1[i] - '0' : 0;
		int d2 = (j >= 0) ? s2[j] - '0' : 0;

		int d = d1 + d2 + carry;
		res[k] = (d % 10) + '0';
		carry = d / 10;

		i--;
		j--;
		k--;
	}
	if (carry > 0) {
		res[0] = carry + '0';
		return res;
	}
	else {
		char* ans = new char[len + 1];
		for (int m = 0; m <= len; m++) {
			ans[m] = res[m + 1];
		}
		delete[] res; 
		return ans;
	}
}

int main() {
	/*char str[] = "123 abd5cd efgh78";
	cout << countNumCharRecursion(str);*/

	char s1[] = "12345";
	char s2[] = "56";
	char* res = addString(s1, s2);
	cout << res << endl;
	delete[] res;

	return 0;
	
}