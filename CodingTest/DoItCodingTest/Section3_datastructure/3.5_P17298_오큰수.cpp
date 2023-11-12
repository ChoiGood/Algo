#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> A(N, 0);    // 수열 배열
    vector<int> ans(N, 0);  // 정답 배열

    for(int i = 0; i < N; i++) {
        cin >> A[i]; 
    }

    stack<int> myStack;
    myStack.push(0);

    for(int i = 1; i < N; i++) {
        int su = A[i]; // 오큰수 검사할려는 수열의 수
        // 스택이 비지 않고 현재 수열이 스택 top 위치의 값보다 크면
        while(!myStack.empty() && su > A[myStack.top()]) {
            ans[myStack.top()] = su;    // 정답 배열에 오큰수를 현재 수열로 저장하기
            myStack.pop();
        }
        myStack.push(i);    // 신규 데이터 push()
    }
    while(!myStack.empty()) {
        // 반복문을 다 돌고 나왔는데 스택이 비지 않다면 빌 때까지
        ans[myStack.top()] = -1;
        myStack.pop();
    }
    for(int i = 0; i < N; i++) {    // 정답 출력
        cout << ans[i] << " ";
    }

    return 0;

}