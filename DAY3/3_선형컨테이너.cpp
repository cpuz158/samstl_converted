// 
// sequence container, 선형컨테이너
// => 요소가 순서를 가지고 한 줄로 놓여있는 컨테이너
// => 5개가 있습니다.
// => "메모리 구조" 와 "반복자의 종류" 를 알아 두세요.
// 
// 
// C++98 에서 3개
#include <vector>  // 연속된 메모리, 임의접근 반복자
#include <deque>   // 연속된 메모리와 유사, 임의접근 반복자
#include <list>    // 떨어진 메모리, 양방향 반복자


// C++11 추가된 2개
#include <forward_list> // 전진형 반복자
#include <array>		// 임의접근 반복자

#include "show.h"

int main()
{
//	std::vector<int> c = { 1,2,3 };
	std::list<int>   c = { 1,2,3 };


	// 핵심 1. sequence 컨테이너는 사용법이 유사합니다.
	c.push_back(10);
	c.pop_back();


	// 핵심 2. 사용법에 차이가 있다면 "의도적으로" 그렇게 설계 한것
	// => vector 는 앞쪽으로 삽입/삭제 안됩니다.	
	// => 앞에 넣고 싶다면 "다른 컨테이너"를 사용하라는 의도.
	c.push_front(5); // vector 라면 에러.
	c.pop_front();   // vector 라면 에러.


	// 핵심 3. [] 연산은 list 는 사용할수 없습니다.
	c[0] = 10; // vector, deque 만 가능, list 안됨.


	// 핵심 4. 모든 요소 순회는, range-for 또는 반복자 사용
	for (auto e : c) // 모든 컨테이너 가능
	{
	}
	auto p1 = c.begin(); // std::begin(c)
	
	while (p1 != c.end())
	{
		++p1;
	}

	// 핵심 5.
	// 전방 삽입은 필요 없고, [] 가 필요, 삽입삭제는 적다 : vector
	// 전방 삽입은 필요 있고, [] 가 필요, 삽입삭제는 적다 : deque
	// []는 필요없고, 삽입삭제가 많다. :  list
}
