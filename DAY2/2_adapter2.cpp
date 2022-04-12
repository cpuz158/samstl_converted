#include <iostream>
#include <list>
#include <algorithm>

int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,3,9,10 };

	// reverse iterator 를 만드는 방법
	// 1. 반복자를 꺼낸후, reverse_iterator 를 만드는 방법
	auto p1 = s.begin();
	std::reverse_iterator<std::list<int>::iterator> ri1(p1); 

	// 2. make_reverse_iterator 함수 사용
	auto rend = std::make_reverse_iterator( s.begin() );
	auto rbegin = std::make_reverse_iterator( s.end() );

	// 3. 컨테이너에서 직접 꺼낸다. - 사실상 이방법이 널리 사용
	auto rp1 = s.rbegin(); // std::make_reverse_iterator( s.end() );
	auto rp2 = s.rend();
}
