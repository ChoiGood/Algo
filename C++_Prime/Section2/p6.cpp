#include <iostream>

using namespace std;

double Dis(double);

int main()
{
    double num;
    cout << "���� ���� �Է��ϰ� Enter Ű�� �����ʽÿ�: ";
    cin >> num;
    cout << num << " ������ " << Dis(num) << " õ�� �����Դϴ�.\n";

    return 0;
}

double Dis(double d)
{
    return d * 63240;
}