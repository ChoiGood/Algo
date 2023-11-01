// 평균 구하기
#include <iostream>
#include <vector>

int main()
{
    using namespace std;
    
    int n; cin >> n;
    vector<int> score(n);

    for(int i = 0; i < n; i++)
    {
        cin >> score[i];
    }

    double sum = 0;
    int max = 0;

    for(int i = 0; i < n; i++)
    {
        if(score[i] > max)
            max = score[i];
        
        sum += score[i];
    }

    cout << sum * 100 / max / n;
}