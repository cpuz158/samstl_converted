#include <iostream>
#include <algorithm>
#include <functional>
using namespace std::placeholders;

int main()
{
    // C++ 표준에 modulus 라는 함수 객체가 이미 존재 합니다.
    // <functional> 헤더..
    std::modulus<int> m;

    int n = m(10, 3); // 10 % 3을 수행

    std::cout << n << std::endl; // 1


    int x[5] = { 9, 9, 2, 4, 3};

    // 3의 배수가 아닌 것을 찾고 싶다.!

//  auto p = std::find_if( x, x+5, m ); // error

    // 왜 에러 인가요 ?
    // 1. m 은 인자를 2개를 받는 "이항함수(객체)" 입니다.
    // 2. find_if 의 3번째 인자는 "단항함수(객체)"를 요구 합니다.
    // 결국, find_if 가 내부적으로 "m(9)" 로 호출하게 됩니다.
    //      => m은 인자가 2개인데, 한개만 보내 므로 error

    // 해결책 : 이항 함수(객체)인 m을 단항함수로 변경하면 됩니다.
    auto p = std::find_if(x, x + 5, std::bind(m, _1, 3 )  );

    // 알고리즘 사용시 "위처럼 bind"로 함수를 전달하는 경우도 예전에는 많이사용
    // 그런데, 요즘은 "람다표현식" 권장
}

















//












//
