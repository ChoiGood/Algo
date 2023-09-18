#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> matrix_t;

int count = 0;

bool exam(int row, int col, int N, int M, matrix_t &room)
{
    int test_r; 
    int test_c;

    // 남
    test_r = row + 1;
    if(test_r >= N)
        test_r = N-1;
    
    if(room[test_r][col] == 0)
        return true;
        
        

    // 북
    test_r = row - 1;
    if(test_r  < 0)
        test_r = 0;
    
    if(room[test_r][col] == 0)
        return true;

    // 동
    test_c = col + 1;
    if(test_c  >= M)
        test_c = M-1;
    
    if(room[row][test_c] == 0)
        return true;

    // 서
    test_c = col - 1;
    if(test_c  < 0)
        test_c = 0;
    
    if(room[row][test_c] == 0)
        return true;


    
    return false;
    
}

bool exam_back(int row, int col, int dir, int N, int M, matrix_t &room)
{
    if(dir == 3)    // 서 바라보때
    {   
        int test_r = row;
        int test_c = col + 1;
        if(test_c >= M)
            test_c = M-1;
        
        if(room[test_r][test_c] != 1)
            return true;
        else
            return false;

    }
    else if (dir == 2)  // 남 바라볼때
    {
        int test_r = row - 1;
        int test_c = col;
        if(test_r < 0)
            test_r = 0;
        
        if(room[test_r][test_c] != 1)
            return true;
        else
            return false;
    }
    else if (dir == 1)  // 동 바라볼때
    {
        int test_r = row;
        int test_c = col - 1;
        if(test_c < 0)
            test_c = 0;
        
        if(room[test_r][test_c] != 1)
            return true;
        else
            return false;
    }
    else if (dir == 0)  // 북 바라볼때
    {
        int test_r = row + 1;
        int test_c = col;
        if(test_r >= N)
            test_r = N-1;
        
        if(room[test_r][test_c] != 1)
            return true;
        else
            return false;
    }
}

void solve(int row, int col, int dir, int N, int M, matrix_t &room)
{
    // 해당 칸 청소
    if(room[row][col] == 0)
    {
        room[row][col] = -1;
        ::count++;
    }

    if(exam(row,col,N,M,room))
    {
        int t_dir = dir;
        // 청소가능
        while(true)
        {
            t_dir--;
            
            if(t_dir == -1)
                t_dir = 3;
            
            if(t_dir == 0)  // 북
            {
                int test_r = row - 1;
                if(test_r < 0) test_r = 0;
                if(room[test_r][col]==0) break;
                    
            }
            else if(t_dir == 1) //
            {
                int test_c = col + 1;
                if(test_c >= M) test_c = M -1;
                if(room[row][test_c]==0 ) break;
            }
            else if(t_dir == 2)
            {
                int test_r = row + 1;
                if(test_r >= N) test_r = N-1;
                if(room[test_r][col]==0 ) break;
            }
            else if(t_dir == 3)
            {
                int test_c = col - 1;
                if(test_c < 0) test_c = 0;
                if(room[row][test_c]==0 ) break;
            }

            

        }

        if(t_dir == 0)
            solve(row - 1, col, t_dir, N,M, room);
        else if(t_dir == 1)
            solve(row , col + 1, t_dir, N,M, room);
        else if(t_dir == 2)
            solve(row + 1 , col, t_dir, N,M, room);
        else if(t_dir == 3)
            solve(row , col - 1, t_dir, N,M, room);
        

    }
    else        // 청소할 구역 X
    {
        // 바라보는 방향 유지한채로 한칸 후진
        if(exam_back(row,col, dir, N,M, room))
        {
            // 후진 벽이 아닐 때
            if(dir == 0)
                solve(row + 1, col, dir, N,M, room);
            else if(dir == 1)
                solve(row, col - 1, dir, N,M, room);
            else if (dir == 2)
                solve(row - 1 , col, dir, N,M, room);
            else if (dir == 3)
                solve(row , col + 1, dir, N,M, room);    
        }
        else    // 멈춤
        {
            return;
        }
    }
   

}

int main()
{
    int n,m;
    cin >> n >> m;

    int row, col, dir;
    cin >> row >> col >> dir;

    matrix_t room(n, vector<int> (m));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> room[i][j];
        }
    }


    solve(row, col, dir, n, m, room);

   
    cout << ::count;

    return 0;
}