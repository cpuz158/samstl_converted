#include <iostream>
#include <functional>
using namespace std::placeholders;

class Machine
{
public:
    void mf1(int a)        {}
    void mf2(int a, int b) {}
};
void f1(int a)               { printf("f1 : %d\n", a); }
void f2(int a, int b)        { printf("f2 : %d, %d\n", a, b);}
void f3(int a, int b, int c) { printf("f3 : %d, %d, %d\n", a, b, c); }
void f4(int a, int b, int c, int d) { printf("f4 : %d, %d, %d, %d\n", a, b, c, d);}

int main()
{
    void(*f)(int) = &f1; // ok
    f(10); // ok.. f1(10) 와 동일

    // C 언어의 함수 포인터는 불편합니다.(한계가 있습니다)
    // 1. signature가 다른 함수 주소를 담을수 없습니다
    f = &f2; // error

    // 2. 멤버 함수의 주소도 담을수 없습니다.
    f = &Machine::mf1; // error
}













//
