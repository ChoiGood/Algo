#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main()
{
    set<int> s4 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    s4.erase(s4.find(1));    //output : 2, 3, 4, 5, 6, 7, 8, 9, 10

    for(auto it = s4.begin(); it != s4.end(); it++)
        cout << *it << " ";

    cout << endl;

    s4.erase(s4.begin(), s4.find(7));    //output : 7, 8, 9, 10

     for(auto it = s4.begin(); it != s4.end(); it++)
        cout << *it << " ";

    return 0;


    return 0;
}