// 사용자에게 본인의 이름을 입력하도록 요구하는 프로그램을 작성하시오. 또한 그 프로그램은 화면에 사용자의 나이를 월수로 나타내도록 합니다.

#include <iostream>

using namespace std;

int main()
{
    string name;
    cout << "이름을 입력하시오 : ";
    cin >> name;

    int age;
    cout << "나이를 입력하시오 : ";
    cin >> age;

    cout << name << " 님의 나이를 월수로 나태날 경우" << age * 12 << "입니다.\n";

    return 0;
}