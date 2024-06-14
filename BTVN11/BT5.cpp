#include <iostream>
#include <string>
using namespace std;

// Định nghĩa các chuỗi để biểu diễn các số đơn vị, chục, và nhóm nghìn, triệu, tỷ
const string a[] = { "khong", "mot", "hai", "ba", "bon", "nam", "sau", "bay", "tam", "chin" };
const string b[] = { "muoi", "muoi mot", "muoi hai", "muoi ba", "muoi bon", "muoi lam", "muoi sau", "muoi bay", "muoi tam", "muoi chin" };
const string c[] = { "", "", "hai muoi", "ba muoi", "bon muoi", "nam muoi", "sau muoi", "bay muoi", "tam muoi", "chin muoi" };
const string d[] = { "", "nghin", "trieu", "ty" };

string readNumber(const string& s) {
    int len = s.length();
    if (len == 0) 
        return "";

    string res = "";
    int cnt = 0; // Để đếm nhóm nghìn, triệu, tỷ

    while (len > 0) {
        int pos = 0;
        if (len - 3 >= 0)
            pos = len - 3;
        else pos = 0;

        int n = stoi(s.substr(pos, len - pos));
        len = pos;

        string temp = "";
        int hundred = n / 100;
        int ten = (n / 10) % 10;
        int unit = n % 10;

        if (hundred != 0) {
            temp += a[hundred] + " tram ";
            if (ten == 0 && unit != 0) {
                temp += "le ";
            }
        }
        if (ten == 1) {
            temp += b[unit];
        }
        else {
            if (ten > 1) {
                temp += c[ten];
                if (unit != 0) {
                    temp += " " + a[unit];
                }
            }
            else if (unit != 0) {
                temp += a[unit];
            }
        }
        if (!temp.empty()) {
            if (cnt > 0) {
                temp += " " + d[cnt] + " ";
            }
            res = temp + res;
        }
        else if (cnt > 0) {
            res = "khong " + d[cnt] + " " + res;
        }
        cnt++;
    }
    return res;
}

int main() {
    string s;
    cin >> s;
    cout << readNumber(s) << endl;
    return 0;
}
