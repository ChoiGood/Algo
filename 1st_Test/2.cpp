#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int m,n;
    cin >> m >> n;
    vector<int> arr(1000001);

    for(int i=2; i<=n; i++)
    {
        arr[i] = i;
    }

    for(int i=2; i<= sqrt(n); i++)
    {
        if(arr[i] == 0) continue;
        for(int j = 2 * i; j <= n; j +=i)
        {
            arr[j] = 0;
        }
    }

    for(int i = m; i <= n; i++)
    {
        if(arr[i] != 0 && arr[i] != 1) 
            printf("%d\n", arr[i]);
    }

    return 0;

}