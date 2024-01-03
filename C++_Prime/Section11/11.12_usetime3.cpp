// usetime3.cpp -- Time 클래스의 네 번째 드래프트 버전을 사용한다
// usetime3.cpp와 mytime3.cpp를 함께 컴파일한다
#include <iostream>
#include "11.10_mytime3.h"

int main()
{
    using std::cout;
    using std::endl;
    Time aida(3, 35);
    Time tosca(2, 48);
    Time temp;

    cout << "Aida와 Tosca:\n";
    cout << aida << "; " << tosca << endl;
    temp = aida + tosca;            // operator+()
    cout << "Aida + Tosca: " << temp << endl;
    cout << "10 * Tosca: " << 10 * tosca << endl;

    return 0;
}