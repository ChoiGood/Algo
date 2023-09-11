#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main(void) {

    set<string> s;
    set<string> result;

    int m,n;
    cin >> m >> n;

    for(int i=0; i<m; i++)
    {
        string a;
        cin >> a;
        s.insert(a);
    }

    for(int i=0; i<n; i++)
    {
        string a;
        cin >> a;
        if(s.find(a)!=s.end())
            result.insert(a);
    }

    cout << result.size() << endl;
   
     for_each(result.begin(), result.end(), [](string n) {
        cout << n << endl;        //output : -1, 1, 3, 200
        });
   
    return 0;
}