#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "show.h"

int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	// s 의 모든 내용을 뒤집어 보세요
//	s.reverse(); // 1. 멤버 함수 사용
				// list 안에 있는 prev, next 의 값을 교환
				// 즉, 포인터 2개를 swap 하는 원리.

	std::reverse(s.begin(), s.end()); // 2. 알고리즘 사용
								// 원리, swap(첫번째요소값, 마지막요소값)
								// list 가 저장하는 요소가 크기가 큰 구조체
								// 라면 약간의 성능 이슈!!

	show(s); // 10, 9, 8, 7, 6, 5, 4, 3, 2, 1

	return 0;
}
