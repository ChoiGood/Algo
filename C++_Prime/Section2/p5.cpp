#include <iostream>

double StoF(double);

int main()
{
    using namespace std;

    int s;
    cout << "���� �µ��� �Է��ϰ� Enter Ű�� �����ʽÿ�: ";
    cin >> s;
    cout << "���� " << s <<"���� ȭ���� " << StoF(s) << "�� �Դϴ�." << endl;

    return 0;
}

double StoF(double s)
{
    return 1.8 * s + 32.0;
}