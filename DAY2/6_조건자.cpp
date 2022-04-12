// 6_조건자
#include <iostream>
#include <vector>
#include <algorithm>

// 조건자(predicator) : bool 을 반환 하는 함수(함수객체)
bool foo(int n) { return n % 3 == 0; }

int main()
{
	std::vector<int> v = { 1,2,6,4,5,3,7,8,9,10 };

	// 주어진 구간에서 "3" 검색
	auto ret1 = std::find(v.begin(), v.end(), 3);

	// 주어진 구간에서 1번째 나오는 "3의 배수" 를 찾고 싶다.
	// std::find    : 값 검색   - 3번째 인자로 값
	// std::find_if : 조건 검색 - 3번째 인자로 함수
	auto ret2 = std::find_if(v.begin(), v.end(), foo);

	auto ret3 = std::find_if(v.begin(), v.end(), 
							[](int n) { return n % 3 == 0; });

}


