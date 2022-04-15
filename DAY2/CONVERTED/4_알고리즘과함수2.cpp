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
    std::list<int> s1 = { 1,2,3,4,5};
//  std::list<int> s2 = { 6,7,8,9,10 };
    std::list<int> s2 = { 6,7,8,9,10,11, 12, 13};
    std::list<int> s3;

    // transform 알고리즘
    // s1, s2 의 길이가 달라도 되는데.. 
    // s1.size() < s2.size() 라면 사용가능합니다.
    std::transform( s1.begin(), s1.end(), // 이 구간의 각 요소를
                    s2.begin(),           // 이 구간의 각 요소와 함께 
                                          // 마지막 인자로 전달된 함수로 보내라.
                    std::back_inserter(s3), // 함수의 반환값을 여기에 넣어 달라.
                    foo);

    show(s3);

	return 0;
}



















//
