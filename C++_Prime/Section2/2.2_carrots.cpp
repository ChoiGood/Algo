// carrots.cpp -- ���Ĺ� ó�� ���α׷�
// �ϳ��� ������ ����ϰ� ����Ѵ�

#include <iostream>

int main()
{
    using namespace std;

    int carrots;        // ���� ������ �����Ѵ�

    carrots = 25;       // ������ ���� �����Ѵ�
    cout << "���� ����� ";
    cout << carrots;    // ������ ���� ����Ѵ�
    cout << "�� ������ �ִ�.";
    cout << endl;       
    carrots = carrots - 1;  // ������ ���� �����Ѵ�
    cout << "�ƻ�ƻ�, ���� ����� " << carrots << "���̴�.\n";

    int steinway;
    int baldwin;
    int yamaha;
    yamaha = baldwin = steinway = 88;       // �����ϰ� ���̴� �ڵ嵵 ����Ϸ��� C�� �������� C++ �� �������ֱ�

    cout << yamaha << " " << baldwin << " " << steinway;

    return 0;
}