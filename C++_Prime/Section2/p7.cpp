#include <iostream>

void Time(int n, int m);

int main()
{
    using namespace std;

    int n, m;

    cout << "�ð� ���� �Է��Ͻÿ� : ";
    cin >> n;
    cout << "�� ���� �Է��Ͻÿ�. : ";
    cin >> m;
    Time(n,m);

    return 0;
}

void Time(int n, int m)
{
    using namespace std;
    cout << "�ð� : " << n << ":" << m << endl;
}