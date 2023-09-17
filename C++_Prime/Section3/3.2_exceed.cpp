// exceed.cpp -- 정수 한계값을 초과한다
#include <iostream>
#define ZERO 0
#include <climits>

int main()
{
    using namespace std;
    short Dohee = SHRT_MAX;
    unsigned short Insuk = Dohee;

    cout << "도희의 계좌에 " << Dohee << "원이 들어있고, ";
    cout << "인숙이의 계좌에도 " << Insuk << "원이 들어있다." << endl;
    cout << "각각의 계좌에 1원씩 입급한다. " << endl << "이제 ";
    Dohee = Dohee + 1;
    Insuk = Insuk + 1;
    cout << "도희의 잔고는 " << Dohee << "원이 되었고, ";
    cout << "인숙의 잔고는 " << Insuk << "원이 되었다. " << endl;
    cout << "이럴수가 도희! 나 몰래 도박했니??" << endl;

    Dohee = ZERO;
    Insuk = ZERO;

    cout << "도희의 계좌에 " << Dohee << "원이 들어있고, ";
    cout << "인숙이의 계좌에도 " << Insuk << "원이 들어있다." << endl;
    cout << "각각의 계좌에 1원씩 인출한다. " << endl << "이제 ";
    Dohee = Dohee - 1;
    Insuk = Insuk - 1;
    cout << "도희의 잔고는 " << Dohee << "원이 되었고, ";
    cout << "인숙의 잔고는 " << Insuk << "원이 되었다. " << endl;
    cout << "이럴수가 인숙아! 언제 복권에 당첨이 된거야?? :):)" << endl;
    
    return 0;
}