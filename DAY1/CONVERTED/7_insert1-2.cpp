#include <iostream>
#include <list>
#include <vector>

int main()
{
	std::list<int>   s = { 1,2,3 };
	std::vector<int> v = { 1,2,3 };

	// 삽입반복자란 ?
	// => 컨테이너에 요소를 추가 할때 사용하는 반복자
	
	// 사용하는 방법 1. 삽입반복자 클래스 이름 직접 사용.
	std::back_insert_iterator< std::list<int> >   p1(s);
	std::back_insert_iterator< std::vector<int> > p2(v);

	// 사용법 2. 삽입반복자 객체를 만드는 "도움 함수" 사용
	//          => insert1-1에 있는 make_pair 개념으로 만든것
	auto p3 = std::back_inserter(s);
	auto p4 = std::back_inserter(v);

	*p3 = 100; // s.push_back(100);


	// 사용법 3. C++17 이후 부터는 아래 처럼만 사용해도 됩니다.
	std::back_insert_iterator p5(s);
	std::back_insert_iterator p6(v);

	*p6 = 30; // v.push_back(30) 의 의미.

}