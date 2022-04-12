#include <iostream>
#include <vector>
#include <algorithm>
#include "show.h"
using namespace std;

// 단항 함수 : 인자가 1개인 함수
// 이항 함수 : 인자가 2개인 함수
void foo(int n)
{
    std::cout << n << ", ";
}

int main()
{
    std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    
    // STL 알고리즘에는 "인자로 함수(포인터)" 를 받는 경우가 많이 있습니다.

    // 1. for_each 알고리즘
    std::for_each(v.begin(), v.end(), foo);


	return 0;
}



















//
