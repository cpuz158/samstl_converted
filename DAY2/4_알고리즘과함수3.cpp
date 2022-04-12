#include <iostream>
#include <list>
#include <algorithm>
#include "show.h"

int foo(int a, int b)
{
    return a + b;
}
int main()
{
    std::list<int> s1 = { 1,2,3,4,5 };
    std::list<int> s2 = { 6,7,8,9,10 };
    std::list<int> s3;

    // STL에 함수 전달시
    // 1. 진짜 함수를 만들어서 전달해도 되고
//    std::transform(s1.begin(), s1.end(),
//        s2.begin(),                                         
//        std::back_inserter(s3), 
//        foo);

    // 2. 요즘은 함수 보다는 "람다표현식"을 사용하는 것이 좋습니다.
    std::transform(s1.begin(), s1.end(),
        s2.begin(),
        std::back_inserter(s3),
        [](int a, int b) { return a + b; } );

    show(s3);


    return 0;
}


