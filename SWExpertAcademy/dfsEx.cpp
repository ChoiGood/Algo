// DFS 소스코드 예제(C++)

#include <bits/stdc++.h>

using namespace std;

bool visited[9];
vector<int> graph[9]; // 각 노드는 자신과 연결된 노드 정보를 리스트 형태로 갖고 있어야한다!!

void dfs(int x) {
    visited[x] = true;  // 방문 처리
    cout << x << ' ';
    for (int i = 0; i < graph[x].size(); i++) { // 인접 리스트 상에서 현재 확인하고자
        // 하는 그 노드 번호와 연결된 다른 노드의 개수가 몇 개인지 확인
        int y = graph[x][i];  // 인접 노드를 하나씩 확인
        if (!visited[y]) dfs(y);    // 해당 노드를 방문하지 않았다면 재귀적으로 방문
    }
}

int main(void) {
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(8);
    
    graph[2].push_back(1);
    graph[2].push_back(7);
    
    graph[3].push_back(1);
    graph[3].push_back(4);
    graph[3].push_back(5);
    
    graph[4].push_back(3);
    graph[4].push_back(5);

    graph[5].push_back(3);
    graph[5].push_back(4);
    
    graph[6].push_back(7);
    
    graph[7].push_back(2);
    graph[7].push_back(6);
    graph[7].push_back(8);

    graph[8].push_back(1);
    graph[8].push_back(7);

    for(int i = 0; i < 9; i++) {
        visited[i] = false;
    }

    dfs(1);

    return 0;
}