#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T; 
    cin >> T;

    for(int i=1; i<=T; i++)
    {
        int S, D, K;
        cin >> S >> D >> K;

        int cheese = S + 2 * D;
        int patty = S + 2 * D;
        int bun = 2 * S + 2 * D;

        cout << "Case #" << i << ": ";
        if(cheese >= K && patty >= K && bun >= K + 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;


    }

    return 0;
}