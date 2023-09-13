#include <iostream>

double StoF(double);

int main()
{
    using namespace std;

    int s;
    cout << "섭씨 온도를 입력하고 Enter 키를 누르십시오: ";
    cin >> s;
    cout << "섭씨 " << s <<"도는 화씨로 " << StoF(s) << "도 입니다." << endl;

    return 0;
}

double StoF(double s)
{
    return 1.8 * s + 32.0;
}