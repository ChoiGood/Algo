#include <iostream>

using namespace std;

void Blind();
void See();

int main()
{
    Blind();
    Blind();
    See();
    See();

    return 0;
}

void Blind()
{
    cout << "Three blind mice\n";
}

void See()
{
    cout << "See how they run\n";
}