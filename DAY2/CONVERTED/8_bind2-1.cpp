#include <iostream>
#include <functional>
using namespace std::placeholders;

class Machine
{
public:
    void mf1(int a) {}
    void mf2(int a, int b) {}
};
void f1(int a) { printf("f1 : %d\n", a); }
void f2(int a, int b) { printf("f2 : %d, %d\n", a, b); }
void f3(int a, int b, int c) { printf("f3 : %d, %d, %d\n", a, b, c); }
void f4(int a, int b, int c, int d) { printf("f4 : %d, %d, %d, %d\n", a, b, c, d); }

int main()
{
    // STL 에는 함수 포인터 보다 편리한 std::function<> 이 있습니다
    // 사용법 : std::function<함수타입> 
    
    // void(*)(int) : 함수 포인터 타입
    // void(int)    : 함수 타입
    std::function< void(int) > f;

    // 이제 f 는 함수 포인터 처럼 사용하면 됩니다.
    f = &f1;
    f(10); // ok.  f1(10)


    // 장점 1. 인자의 갯수가 다른 함수도 , std::bind()를 사용하면 
    //        f에 담을수 있습니다.
//  f = &f2; // error
    f = std::bind(&f2, 7 , _1 );
    f(10); // f2(7, 10)

    // 장점 2. 멤버 함수도 담을수 있습니다.
    //        => 멤버 함수는 호출하려면 반드시 객체가 있어야 합니다.
//  f = &Machine::mf1; // error

    Machine m;
    f = std::bind(&Machine::mf1, &m, _1 ); // bind(멤버함수, &객체, 인자들)
    f(10); // m.mf1(10);

    // 객체 고정시, 주소로 보내도 되고, 값으로 보내도 됩니다.
    // 값으로 보내면 "참조"로 보관하고 있게 됩니다.
    f = std::bind(&Machine::mf2, m, _1 , 9 ); 
    f(3); // m.mf2(3, 9);

    f = std::bind(&Machine::mf2, Machine(), _1, 9);

    // 장점 3. 람다 표현식도 됩니다.
    f = [](int a) { std::cout << "lambda " << a << std::endl; };
    f(3); // lambda : 3
}

// 결론 : function 에는 std::bind 이 도움을 받으면
//      일반함수, 멤버 함수, 함수객체, 람다 표현식 등 거의 모든 호출가능한 것을
//      담을수 있습니다.

