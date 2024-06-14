#include"checkValid.h"

//Các hàm kiểm tra năm nhuận, ngày hợp lệ, điểm hợp lệ
bool isLeapYear(int year) {
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		return 1;
	return 0;
}

bool isValidDate(int day, int month, int year) {
	if (day < 1 || day > 31)
		return 0;
	if (month < 1 || month > 12)
		return 0;
	if (year < 0)
		return 0;
	if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8
		|| month == 10 || month == 12) && day > 31)
		return 0;
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && (day > 30))
		return 0;
	else if (month == 2) {
		if ((isLeapYear(year)) && day > 29)
			return 0;
		else if ((!isLeapYear(year)) && day > 28)
			return 0;
	}
	return 1;
}

bool core(double n) {
	if (n < 0 || n > 10)
		return 0;
	return 1;
}