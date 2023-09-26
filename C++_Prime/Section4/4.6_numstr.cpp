// numstr.cpp -- 수치 입력 뒤에 오는 문자열 입력
#include <iostream>
int main()
{
    using namespace std;
    cout << "지금 사시는 아파트에 언제 입주하셨습니까?\n";
    int year;
    cin >> year;
    cin.get();      // 이거 없으면 어떤 문제?
    cout << "사시는 도시를 말씀해 주시겠습니까?\n";
    char address[80];
    cin.getline(address, 80);
    cout << "아파트 입주 연도 : " << year << endl;
    cout << "도시: " << address << endl;
    cout << "등록이 완료되었습니다!\n";

    return 0;
}

/*
cin이 입주 연도를 읽어들이고, Enter 키가 만들어내는 개행 문자를 입력 큐에 남겨 두기 때문에 발생하는 문제이다.
cin.getline()은 입력 큐에 남겨진 개행 문자를 빈 행으로 읽어들이고, address 배열에 널 문자열을 대입한다.
이 문제를 해결하는 방법은 주소를 읽기 전에 개행 문자를 읽어 허공에다 버리는 것이다.
매개변수를 사용하지 않는 get()이나, 하나의 char형 매개변수를 사용하는 get() 을 호출하는 것을 포함하여, 
여러가지 방법으로 이 문제를 해결할 수 있다.!!
*/