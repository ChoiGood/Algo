// C++ 에서의 형 변환
#include <iostream>
#include <string>

using namespace std;

int main()
{
    // string -> 숫자형(int, long, double, float
    string sNum = "1234";
    string sNum_d = "1234.56";
    int inum = stoi(sNum);
    long lnum = stol(sNum);
    double dnum = stod(sNum_d);
    float fnum = stof(sNum_d);

    // 숫자형(int, long, double, float) -> string형
    inum = 1234;
    lnum = 1234;
    dnum = 1234.56;
    fnum = 1234.56f;
    string intToString = to_string(inum);
    string longToString = to_string(lnum);
    string doubleToString = to_string(dnum);
    string floatToString = to_string(fnum);
}