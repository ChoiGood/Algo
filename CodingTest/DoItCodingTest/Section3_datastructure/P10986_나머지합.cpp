#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;   // 배열 원소의 개수 n, 나누는 수 m
    cin >> n >> m;

    vector<long> A(n + 1, 0);
    vector<long> S(n + 1, 0);
    vector<int> C(m, 0);
    long answer = 0;

    for(int i = 1; i <= n; i++) {
        cin >> A[i];
        S[i] = S[i-1] + A[i];
    }

    for(int i = 1; i <= n; i++) {   // 합 배열의 모든 값에 % 연산 수행하기
        int remainder = S[i] % m;
        
        // 0 ~ i 까지 구간 합 자체가 0일 때 정답에 더하기
        if(remainder == 0)
            answer += 1;
        // 나머지가 같은 인덱스의 개수 세기
        C[remainder]++;
    }

    for(int i = 0; i < m; i++) {
        // 나머지가 같은 인덱스 중 2개를 뽑는 경우의 수 더하기
        if(C[i] > 1)
            answer += C[i] * (C[i] - 1) / 2;
    }
    cout << answer << "\n";

    return 0;
}