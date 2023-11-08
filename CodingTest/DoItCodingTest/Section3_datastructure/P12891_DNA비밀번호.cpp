// 자료구조/P12891_DNA비밀번호.cpp
#include <iostream>
using namespace std;

int checkArr[4];
int myArr[4];
int checkSecret = 0;
void Add(char c);
void Remove(char c);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int S,P;
    cin >> S >> P;

    int Result = 0;
    string A;
    cin >> A;

    for(int i = 0; i < 4; i++) {
        cin >> checkArr[i];
        if (checkArr[i] == 0) {
            checkSecret++;
        }
    }

    for(int i = 0; i < P; i++) {    // 초기 P부분 문자열 처리
        Add(A[i]);
    }
    if (checkSecret == 4) {
        Result++;
    }

    // 슬라이딩 윈도우 처리 부분
    for(int i = P; i < S; i++) {
        int j = i - P;
        Add(A[i]);
        Remove(A[j]);
        // 4자리 수에 대한 크기가 모두 충족되었을 때는 유효한 비밀번호
        if(checkSecret == 4) {
            Result++;
        }
    }

    cout << Result << "\n";

    return 0;
}

void Add(char c)    // 새로 들어온 문자를 처리하는 함수
{
    switch (c)
    {
    case 'A':
        myArr[0]++;
        if(myArr[0] == checkArr[0])
            checkSecret++;
        break;
    case 'C':
        myArr[1]++;
        if(myArr[1] == checkArr[1])
            checkSecret++;
        break;
    case 'G':
        myArr[2]++;
        if(myArr[2] == checkArr[2])
            checkSecret++;
        break;
    case 'T':
        myArr[3]++;
        if(myArr[3] == checkArr[3])
            checkSecret++;
        break;

    default:
        break;
    }
}

void Remove(char c) // 제거할 문자를 처리하는 함수
{
    switch (c)
    {
    case 'A':
        if(myArr[0] == checkArr[0])
            checkSecret--;
        myArr[0]--;
        break;
    case 'C':
        if(myArr[1] == checkArr[1])
            checkSecret--;
        myArr[1]--;
        break;
    case 'G':
        if(myArr[2] == checkArr[2])
            checkSecret--;
        myArr[2]--;
        break;
    case 'T':
        if(myArr[3] == checkArr[3])
            checkSecret--;
        myArr[3]--;
        break;

    default:
        break;
    }
}

/*
현재 문자는 ACGT 인데 이 부분의 문자 비번이 길어진다면?
저렇게 switch로 짜면 코드를 다시 바꾸기 어렵겠지?
재사용 하기 쉬운 코드를 짤려면 어떻게 만드는 게 좋을까??
*/