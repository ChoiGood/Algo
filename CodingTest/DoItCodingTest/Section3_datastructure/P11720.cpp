// 자료구조/P11720_숫자의 합

#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    string numbers;
    cin >> n;
    cin >> numbers;

    int sum = 0;
    for(int i = 0; i < numbers.length(); i++)
    {
        // numbers[i]를 정수로 계산하여 sum에 누적하기
        sum += numbers[i] - '0';
    }
    cout << sum << endl;
}