#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> matrix_t;

// 아래, 위, 왼쪽, 오른쪽
int prow[4] = {1, -1, 0, 0};    
int pcol[4] = {0, 0, -1, 1};
// 오른대각아래, 왼쪽대각위, 오른대각위, 왼쪽대각아래
int xrow[4] = {1, -1, -1, 1};
int xcol[4] = {1, -1, 1, -1};


void InputM(int n, matrix_t &M) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> M[i][j];
        }
    }
}

// 해당 위치에서 파리 죽이는 개수 리턴 (+랑 X중 큰 값)
int KillFly(int n, int m, int row, int col, matrix_t &M) {
    int count1 = 0; // +
    int count2 = 0; // X

    // +

    count1 += M[row][col];
    count2 += M[row][col];

    for(int i = 0; i < 4; i++) {
        for(int j = 1; j < m; j++) {
            int t_row = row + prow[i] * j;
            int t_col = col + pcol[i] * j;

            if(t_row >= 0 && t_row < n) {
                if(t_col >= 0 && t_col < n) {
                    count1 += M[t_row][t_col];
                }
            }
        }
    }

    // X
    for(int i = 0; i < 4; i++) {
        for(int j = 1; j < m; j++) {
            int t_row = row + xrow[i] * j;
            int t_col = col + xcol[i] * j;

            if(t_row >= 0 && t_row < n) {
                if(t_col >= 0 && t_col < n) {
                    count2 += M[t_row][t_col];
                }
            }
        }
    }

    cout << "count1, count2 : "  << count1 << " " << count2 << endl;

    if(count1 > count2) {
        return count1;
    } else {
        return count2;
    }
}

// 스프레이 뿌렸을 때 메트릭스에서 가장 많은 파리를 죽이는 값 리턴
int KillMaxFly(int n, int m, matrix_t &M) {
    int max = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int count = KillFly(n,m,i,j,M);
            if(count > max) {
                max = count;
            }
        }
    }

    return max;
}

void OutputM(int n, matrix_t M) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int N,M;
    cin >> N >> M;

    matrix_t A(N, vector<int> (N, 0));
    InputM(N, A);

    int max = KillMaxFly(N,M,A);

    cout << max << endl;

    

    return 0;
}