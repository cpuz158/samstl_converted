#include <iostream>
#include <list>
#include <iterator>

int main()
{
	std::list<int> s = { 1, 2, 3, 4, 5};

	// 컨테이너에 요소를 넣는 방법
	// 1. push_xxx()계열 함수 사용
	s.push_back(10);

	// 2. 삽입반복자 사용
	// 아래 코드에서 "p" 는 반복자입니다
	std::back_insert_iterator< std::list<int> > p(s);

	// p에 값을 넣으면 s 의 끝에 추가 됩니다.
	*p = 20; // s.push_back(20);

	for (auto e : s)
		std::cout << e << ", ";
}
