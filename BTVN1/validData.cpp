#include<string.h>
#include<sstream>
#include<fstream>
#include"validData.h"
#include"findMax.h"

//Ghi các thông số ngày sinh, điểm số hợp lệ ra màn hình
void validData(string& filename, string& outfilename) {

	ifstream ifile(filename);
	ofstream ofile(outfilename);
	if (!ifile.is_open()) {
		cerr << "Error";
		return;
	}
	string line;

	while (getline(ifile, line)) {
		string name;
		char c;
		int day, month, year;
		double literature, maths, english;

		istringstream iss(line);
		iss >> name >> day >> c >> month >> c >> year
			>> literature >> maths >> english;

		if (isValidDate(day, month, year) && core(literature) && core(maths) && core(english))
		{
			ofile << name << " " << day << "_" << month << "_" << year
				<< " " << literature << " " << maths << " " << english << endl;
		}
	}

	ifile.close();
	ofile.close();
	findMax(filename, outfilename);
}