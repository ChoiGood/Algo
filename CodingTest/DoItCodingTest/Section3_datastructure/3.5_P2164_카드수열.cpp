#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    queue<int> myQueue;
    for(int i = 1; i <= N; i++) {
        myQueue.push(i);
    }

    while(myQueue.size() != 1) {    // 카드가 한 장 남을 때까지
        // 맨 위 카드 한장 버리기
        myQueue.pop();
        // 맨 위 카드 가장 아래로 보내기 
        int temp = myQueue.front();
        myQueue.pop();
        myQueue.push(temp);

    }
    cout << myQueue.front() << "\n";

    return 0;
}