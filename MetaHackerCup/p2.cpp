#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T; 
    cin >> T;

    for(int i=1; i<=T; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;

        int S, D;
        if (B / A >= 2) 
        {
            // A가 더 효율적 ==> A먼저 다 사기!!
            S = (C/A);
            if(S < 1)
                S = 0;
            D = 0;

        }
        else
        {
            // B가 더 효율적 
            D =  (C/B);
            if(D < 1) 
            {
                D = 0;
                S = C/A;
            }
            else
            {
                C = C - D * B;
                S = (C/A);
            }
            
        }

        int cheese = S + 2 * D;
        int patty = S + 2 * D;
        int bun = 2 * S + 2 * D;
        int sol = bun;
        while(true)
        {
            if(cheese >= sol && patty >= sol && bun >= sol + 1)
                break;

            if(sol == 0)
                break;

            sol--;
        }

        cout << "Case #" << i << ": " << sol << endl; 
    }

    return 0;
}

// Case 6 은 10000000000 int의 범위를 넘어가고 있어서
// double 로 받으면 되는건가?
// 그럼 어떻게 바꿔야하는 거지?
