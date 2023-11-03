// 자료구조/P11659_구간합구하기
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; int M;
    cin >> N >> M;

    vector<int> A(N+1, 0);
    vector<long> S(N+1, 0);

    for(int i = 1; i <= N; i++) {
        cin >> A[i];
        S[i] = S[i - 1] + A[i];
    }

    for (int i =0; i < M; i++) {
        int start, end;
        cin >> start >> end;
        cout << S[end] - S[start - 1] << "\n";
    }

    return 0;
}