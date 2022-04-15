#include <iostream>
#include <algorithm>
#include <functional>
using namespace std::placeholders; // _1, _2, _3 ...이
                                // 이 namespace 안에 있습니다.


// 4항 함수
void foo( int a, int b, int c, int d)
{
    printf("%d, %d, %d, %d\n", a, b, c, d);
}

int main()
{
    foo(1,2,3,4);   // 4항 함수..

    // std::bind : M항 함수(객체)를 N 항 함수로 변경하는 도구, 단(M > N)

    // bind 사용법 : std::bind( M항 함수, M개 인자 )
    std::bind(foo, 1, 2, 3, 4)();  // 4항 함수 => 0 항 함수로 변경한것
    //|<-----결과가 다시 함수-->|()

    std::bind(foo, 5, 6, _1, 3)(2); // 4항 => 1항 함수로 변경
                                // foo(5,6,2, 3)

    std::bind(foo, 9 , _2, 6, _1) (7, 4); // 9, 4, 6, 7  나오도록 ? 채우세요
}

