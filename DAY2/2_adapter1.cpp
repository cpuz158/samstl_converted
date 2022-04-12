#include <iostream>
#include <list>
#include <algorithm>

int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,3,9,10};

	auto p1 = s.begin();
	auto p2 = s.end();

	++p1;
	++p1;

	std::cout << *p1 << std::endl; // 3

	// std::reverse_iterator< 반복자타입 > p3( 반복자 );

	std::reverse_iterator<std::list<int>::iterator> ri(p1); // p1 보다
													// 한개 앞으로 초기화

	std::cout << *ri << std::endl; // 2
	--ri; // 거꾸로 동작하는 반복자 이므로 일반 반복자의 ++ 의미
	std::cout << *ri << std::endl; // 3
}
