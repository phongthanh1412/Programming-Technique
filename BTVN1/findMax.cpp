#include<string.h>
#include"checkValid.h"
#include"findMax.h"
#include<sstream>
#include<fstream>

//Tìm học sinh có điểm trung bình cao nhất và in ra màn hình
void findMax(string& filename, string& outfilename) {
	ifstream ifile(filename);
	ofstream ofile(outfilename, ios_base::app);
	if (!ifile.is_open()) {
		cerr << "Error";
		return;
	}
	string name;
	char c;
	int day, month, year;
	double literature, maths, english;
	double maxi = -1e9;
	string student_name;
	while (ifile >> name >> day >> c >> month >> c >> year
		>> literature >> maths >> english) {
		if (isValidDate(day, month, year) && core(literature) && core(maths) && core(english)) {
			double average = (literature + maths + english) / 3;
			if (average > maxi) {
				maxi = average;
				student_name = name;
			}
		}
	}
	ifile.close();

	ofile << "Nguoi co diem trung binh cao nhat la " << " " << student_name << " " << "voi diem " << maxi;
	ofile.close();
}
