// exceed.cpp -- ���� �Ѱ谪�� �ʰ��Ѵ�
#include <iostream>
#define ZERO 0
#include <climits>

int main()
{
    using namespace std;
    short Dohee = SHRT_MAX;
    unsigned short Insuk = Dohee;

    cout << "������ ���¿� " << Dohee << "���� ����ְ�, ";
    cout << "�μ����� ���¿��� " << Insuk << "���� ����ִ�." << endl;
    cout << "������ ���¿� 1���� �Ա��Ѵ�. " << endl << "���� ";
    Dohee = Dohee + 1;
    Insuk = Insuk + 1;
    cout << "������ �ܰ�� " << Dohee << "���� �Ǿ���, ";
    cout << "�μ��� �ܰ�� " << Insuk << "���� �Ǿ���. " << endl;
    cout << "�̷����� ����! �� ���� �����ߴ�??" << endl;

    Dohee = ZERO;
    Insuk = ZERO;

    cout << "������ ���¿� " << Dohee << "���� ����ְ�, ";
    cout << "�μ����� ���¿��� " << Insuk << "���� ����ִ�." << endl;
    cout << "������ ���¿� 1���� �����Ѵ�. " << endl << "���� ";
    Dohee = Dohee - 1;
    Insuk = Insuk - 1;
    cout << "������ �ܰ�� " << Dohee << "���� �Ǿ���, ";
    cout << "�μ��� �ܰ�� " << Insuk << "���� �Ǿ���. " << endl;
    cout << "�̷����� �μ���! ���� ���ǿ� ��÷�� �Ȱž�?? :):)" << endl;
    
    return 0;
}