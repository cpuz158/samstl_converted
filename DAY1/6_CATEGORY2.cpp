#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>

// 입력 vs 출력 

// 입력 반복자 : =*p, ++
// 출력		 : *p=, ++// 
// --------------------  위 2개는 멀티 패스 보장안되고, 아래 3개는 멀티 패스 보장// 
// 전진형     : =*p, ++			싱글리스트 반복자
// 양방향		 : =*p, ++, --		더블리스트 반복자
// 임의접근    :=*p, ++, --, +, -, [] 연속된 메모리와 유사, vector

int main()
{
	std::forward_list<int> s1 = { 1,2,3 };
	std::list<int> s2 = { 1,2,3 };
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	// find 는 1, 2번째 인자가 반복자 입니다.
	// => 최소 요구 조건을 5가지 category 에서 골라 보세요

	auto p = std::find(std::begin(v), std::end(v), 5);
						// 입력 반복자

	std::reverse(v.begin(), v.end()); // reverse 알고리즘의 인자가 가지는
					// 최소 요구 조건 ?
					// => 양방향 반복자

	std::sort( v.begin(), v.end() ); // 퀵 소트 입니다.
					// 최소 요구조건은 ? 임의접근 반복자 !!

	// 현재 
	// s1 : 싱글리스트
	// s2 : 더블리스트
	// v  : vector 입니다.

	// 아래 코드 생각해 보세요
	// std::reverse : 반드시 인자로 양방향 반복자가 전달되어야 합니다.
	std::reverse(s2.begin(), s2.end()); // ok. 요구 조건 만족
//	std::reverse(s1.begin(), s1.end()); // error. 싱글리스트 반복자는
								// 전진형 이므로 -- 될수 없다.

	// std::sort : 임의접근 반복자만 가능합니다
	std::sort(v.begin(),  v.end()); // ok
//	std::sort(s2.begin(), s2.end());// s2의 반복자는 양방향 반복자.
							// 요구조건(-연산)을 만족할수 없기때문에 error

	// 결론 : STL 의 모든 알고리즘은 "자신이 요구하는 반복자의 종류"가 정해져 있습니다.
	//		 반드시 조건을 만족하는 반복자를 보내야 합니다.
	//		std::sort()에 std::list 반복자 보내지 마세요..

	// 그럼, 더블리스트는 sort 할수 없을까 ? quick 말고 다른 알고리즘사용하면된다
	// 그래서 멤버 함수 sort 제공.
	s2.sort(); // quick 은 아니고, 다른 알고리즘 사용.

	// 질문!! 
//	v.sort();	// vector 에도 sort() 멤버 함수가 있을까 ?? 없다.
				// 임의접근 반복자이므로 알고리즘(멤버가 아닌 일반함수) std::sort()
				// 에 보내면 된다.

	// cppreference.com 에서 std::find 검색해 보세요.
}




