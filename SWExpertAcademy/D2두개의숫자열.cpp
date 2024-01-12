#include <iostream>
#include <vector>

using namespace std;

void OutPutV(vector<int> &A) {
    for(int i = 0; i < A.size(); i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    vector<int> B(M);



    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }

    OutPutV(A);
    OutPutV(B);

    vector<int> Small;
    vector<int> Big;

    if(A.size() > B.size()) {
        Small = B;
        Big = A;
    }
    else {
        Small = A;
        Big = B;
    }
    

    int moving = abs(N-M);

    int max = -99999;
    int temp;

    for(int i = 0; i <= moving; i++) {
        temp = 0;
        for(int j = 0; j < Small.size(); j++) {
            temp += Small[j] * Big[i + j];
        }
        if(temp > max) {
            max = temp;
        }
        cout << temp << endl;
    }

    cout << max << endl;

    return 0;
}