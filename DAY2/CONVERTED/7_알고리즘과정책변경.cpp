// 3_알고리즘과정책변경
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>    // 수치 관련 연산
#include <functional>
#include "show.h"

int main()
{
	std::vector<int> v1 = { 1,2,3,4,5,6,7,8,9,10 };

	// 1. sort 의 비교 정책.
//	std::sort(v1.begin(), v1.end(), [](int a, int b) {return a < b; });

	// 
//	int n = std::accumulate(v1.begin(), v1.end(), 0); // +로 합구하기

	int n = std::accumulate(v1.begin(), v1.end(), 1,
									[](int a, int b) { return a * b; });	

	// C++11 이후에는 람다 표현식으로 많이 하지만
	// C++11 이전에는 <functional> 안에 있는 std::plus<>, std::multiples<> 
	// 같은 함수 객체 사용
	int n = std::accumulate(v1.begin(), v1.end(), 1, 
											std::multiplies<int>() );

	std::cout << n << std::endl; // 55
}
