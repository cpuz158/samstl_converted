#include <iostream>

// find 정리
// 검색 구간   : [first, last) 사이의 임의 타입의 배열, last 검색 대상 아님.
// 구간의 표현 : 반드시 포인터일 필요는 없다. 단, *,  !=, ++ 가 가능한 타입
// 구간의 이동 : 전위형 ++ 연산자 사용
// 실패의 반환 : last 반환 - "past the end" 라고 부릅니다.

// C++ 표준에 이미 아래 같은 "find" 가 있습니다.

template<typename T1, typename T2>
T1 find(T1 first, T1 last, T2 value)
{
	while (first != last && *first != value)
		++first;

	return first; 
}



int main()
{
	double x[10] = { 1,2,3,4,5,6,7,8,9,10 };

	double* p = find(x, x + 10, 5.0f); // ??

	if (p == x + 10)
		std::cout << "not found" << std::endl;
	else
		std::cout << "found : " << *p << std::endl;
}