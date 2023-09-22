#include <iostream>
#include <vector>

using namespace std;

#define INF 0xffff

typedef vector<vector<int>> matrix_t;
typedef vector<pair<int, int>> set_of_edges;
typedef pair<int, int> edge_t;

void prim(int n, matrix_t& W, set_of_edges& F)
{
    int vnear, min;
    vector<int> nearest(n + 1), distance(n + 1);

    F.clear(); // F = O;
    for(int i = 2; i <= n; i++) 
    {
        nearest[i] = 1;
        distance[i] = W[1][i];
    }

    for(int repeat = 1; repeat <= n - 1; repeat++)
    {
        min = INF;
        for(int i = 2; i <= n; i++)
        {
            if(0 <= distance[i] && distance[i] < min)
            {
                min = distance[i];
                vnear = i;
            }
        }

        // e = edge connecting vertices indexed by vnear and nearest[vear]
        // add e to F;
        F.push_back(make_pair(vnear, nearest[vnear]));
        distance[vnear] = -1;
        for(int i = 2; i <= n; i++) 
        {
            if(distance[i] > W[i][vnear])
            {
                distance[i] = W[i][vnear];
                nearest[i] = vnear;
            }
        }

    }
}

void InputW(int n, int m, matrix_t &W)
{
    int a, b, c;
    
    for(int i = 1; i <= n; i++) 
    {
        W[i][i] = 0;
    }

    for(int i = 1; i <= m; i++) 
    {
        cin >> a >> b >> c;
        W[a][b] = c;
        W[b][a] = c;
    }
}

void OutputW(int n, matrix_t &W)
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cout << W[i][j] << " ";
        }
    }
}




int main()
{
    int n,m,u,v;    // n은 정점의 개수, m은 간선의 개수
    cin >> n >> m;

    matrix_t W(n+1, vector<int> (n+1, INF));
    set_of_edges F;
    
    InputW(n,m,W);

    prim(n,W,F);
    
    cout << endl;


    int cnt = 0;
    for(edge_t e: F) {
        u = e.first; v= e.second;
        cout << u << " " << v << " " << W[u][v] << endl;
        cnt += W[u][v];
    }

    cout << "최소비용 신장트리의 모든 이음선의 합 : " << cnt << endl;
    


    return 0;
}