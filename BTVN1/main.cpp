#include<iostream>
#include<fstream>
#include<sstream>
#include<string.h>
#include"checkValid.h"
#include"averageGrade.h"
#include"validData.h"
#include"findMax.h"

using namespace std;

int main() {
	string ifile = "./input.txt";
	string ofile = "output.txt";
	validData(ifile, ofile);
	return 0;
}