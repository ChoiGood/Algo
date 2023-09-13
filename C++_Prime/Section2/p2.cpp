// 거리에 대해 마일 단위로 입력을 요구하고, 그것을 킬로미터 단위로 환산하는 프로그램을 작성하시오.
// (1마일은 1.60934킬로미터이다.)
#include <iostream>

using namespace std;

int main()
{
    double mile;
    cout << "마일을 입력하세요 : ";
    cin >> mile;
    cout << mile << " 마일은 " << mile * 1.60934 << " 킬로미터입니다.";

    return 0;
}
