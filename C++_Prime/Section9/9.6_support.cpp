// support.cpp -- 외부 변수를 사용한다
// external.cpp 와 컴파일한다
#include <iostream>
extern double warming;      // 다른 파일로부터 warming; 을 사용

// 함수 원형
void update(double dt);
void local();

using std::cout;

void update(double dt)  // 전역 변수를 갱신한다
{
    extern double warming;  // 선택적 재선언
    warming += dt;      // 전역 warming 을 사용한다
}