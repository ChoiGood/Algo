#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    string str;
    getline(cin,str);
    //cout << str << endl;
    istringstream ss1(str);

    string buffer;
    int count=0;

    while(getline(ss1,buffer,' '))
    {
        int res = buffer.compare(" ");
        if(res == 1)
        {
            cout << buffer << " "<< res << endl;
            count++;
        }
        
    }

    cout << count;

    return 0;
}