#include <iostream>

using namespace std;

double Dis(double);

int main()
{
    double num;
    cout << "광년 수를 입력하고 Enter 키를 누르십시오: ";
    cin >> num;
    cout << num << " 광년은 " << Dis(num) << " 천문 단위입니다.\n";

    return 0;
}

double Dis(double d)
{
    return d * 63240;
}