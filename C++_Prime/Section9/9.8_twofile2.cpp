// twfile2.cpp -- 외부 링크와 내부 링크를 가지는 변수
#include <iostream>
extern int tom;
static int dick = 10;
int harry = 200;

void remote_access()
{
    using namespace std;
    cout << "remote_access () 가 보고하는 세 변수의 주소:\n";
    cout << &tom << " = &tom, " << &dick << " = &dick, ";
    cout << &harry << " = &harry\n";
}