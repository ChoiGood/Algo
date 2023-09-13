#include <iostream>

void Time(int n, int m);

int main()
{
    using namespace std;

    int n, m;

    cout << "시간 값을 입력하시오 : ";
    cin >> n;
    cout << "분 값을 입력하시오. : ";
    cin >> m;
    Time(n,m);

    return 0;
}

void Time(int n, int m)
{
    using namespace std;
    cout << "시각 : " << n << ":" << m << endl;
}