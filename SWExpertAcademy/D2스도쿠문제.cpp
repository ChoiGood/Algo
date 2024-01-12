#include <iostream>
#include <vector>

using namespace std;


typedef vector<vector<int>> matrix_t;

void InputM(int N, matrix_t &M) {
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> M[i][j];
        }
    }
}

// 0~9 숫자 하나씩 없으면 false 리턴 
bool CheckV(vector<int> &V) {
    vector<int> Check(9, 0); 

    for(int i = 0; i < V.size(); i++) {
        Check[V[i] - 1]++;
    }

    bool flag = true;

    for(int i = 0; i < 9; i++) {
        if(Check[i] == 0) {
            flag = false;
            break;
        }
    }

    return flag;
}

// 작은 사각형 스도쿠 체크하기 => 0~9 숫자 하나씩 없으면 false 리턴
bool CheckV2(int s_r, int s_c, matrix_t & M) {
    vector<int> Check(9, 0);
    for(int i = s_r; i <= s_r + 2; i++) {
        for(int j = s_c; j <= s_c + 2; j++) {
            Check[M[i][j] - 1]++;
        }
    }

    bool flag = true;

    for(int i = 0; i < 9; i++) {
        if(Check[i] == 0) {
            flag = false;
            break;
        }
    }

    return flag; 
}

void RotateM(int n, matrix_t &A, matrix_t &B) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            B[i][j] = A[n - 1 - j][i];
        }
    }
}

int main()
{
    int N;
    cin >> N;

    matrix_t A(9, vector<int> (9, 0));
    matrix_t A90(9, vector<int> (9, 0));

    InputM(9, A);
    RotateM(9, A, A90);

    bool solve = true;

    for(int i = 0; i < 9; i++) {
        if(!CheckV(A[i])) {
            solve = false;
            break;
        }
        if(!CheckV(A90[i])) {
            solve = false;
            break;
        }
    }

    for(int i = 0; i < 9; i += 3) {
        if(!solve)
            break;
        for(int j = 0; j < 9; j += 3) {
            if(!CheckV2(i, j, A)) {
                solve = false;
                break;
            }
        }
    }

    if(solve)
        cout << 1 << endl;
    else
        cout << 0 << endl;




    return 0;
}