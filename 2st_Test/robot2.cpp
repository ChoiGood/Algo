#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> matrix_t;

int count = 0;

int dc[4] = { 0, 1, 0,-1};
int dr[4] = {-1, 0, 1, 0};

int N,M;
matrix_t room;

int aroundExam(int row, int col, int dir)  // 여기서 방향도 주자
{
    for(int i = 0; i < 4; i++)
    {
        int t_r = row + dr[i];
        int t_c = col + dc[i];

        if(t_r >= N) t_r = N - 1;
        if(t_c >= M) t_c = M - 1;
        if(t_r < 0) t_r = 0;
        if(t_c < 0) t_c = 0;

        if(room[t_r][t_c] == 0)
            return true;
    }

    return false;
}


void solve(int row, int col, int dir)
{
    // 해당 칸 청소
    if(room[row][col] == 0)
    {
        room[row][col] = -1;
        ::count++;
    }

    if(aroundExam(row, col, dir)) // 주변 칸 청소 가능 여부 검사
    {
        // 주변 청소 가능
        int t_dir = dir;
        int t_r;
        int t_c;

        while(true)
        {
            t_dir --;
            if(t_dir == -1) t_dir = 3;

            t_r = row + dr[t_dir];
            t_c = col + dc[t_dir];

            if(t_r >= N) t_r = N - 1;
            if(t_c >= M) t_c = M - 1;
            if(t_r < 0) t_r = 0;
            if(t_c < 0) t_c = 0;

            if(room[t_r][t_c] == 0)
                break;
        }

        solve(t_r, t_c, t_dir);

    }
    else
    {
        // 주변 청소 불가능
        // 바라보는 방향에서 후진 할 수 있으면 후진하고 , 후진 불가능?? STOP
        int t_r = row - dr[dir];
        int t_c = col - dc[dir];

        if(t_r >= N) t_r = N - 1;
        if(t_c >= M) t_c = M - 1;
        if(t_r < 0) t_r = 0;
        if(t_c < 0) t_c = 0;

        if(room[t_r][t_c] != 1)
        {
            // 후진 가능
            solve(t_r, t_c, dir);
        }
        else
        {
            // 벽이라 후진 불가능 => Stop
            return ;
        }
    }
}


int main()
{
    
    cin >> N >> M;

    int row, col, dir;
    cin >> row >> col >> dir;

    room.resize(N, vector<int> (M));

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> room[i][j];
        }
    }

    solve(row, col, dir);
    
    cout << ::count;

    return 0;
}

/*
북 동 남 서를 표현하기 위해 int 형 배열 두개를 만들고 (이런 생각을 자연스럽게 할 수 있어야한다!! 코딩 실력!!)
    int dc[4] = { 0, 1, 0,-1};
    int dr[4] = {-1, 0, 1, 0};

dir 을 이용하여 이동을 구현하면

if문을 여러개 쓸 필요가 없어서 코드가 훨씬 간결해진다.

*/