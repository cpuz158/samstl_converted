


// github.com/codenuri/samstl 에서
// "DAY4_사전소스.zip" 받으세요



// codexpert.org 에서 출석해 주세요








#include <iostream>
#include "show.h"

// set : 집합(교집합, 합집합등)관련 연산 제공
#include <set> // Red Black Tree로 구현
#include <functional>

int main()
{
//	std::set<int> s;
	std::set<int, std::greater<int> > s;

	s.insert(20);
	s.insert(30);
	s.insert(15);
	s.insert(5);
	s.insert(40);

	auto p = s.begin();
	while (p != s.end())
	{
		std::cout << *p << std::endl;
		++p;
	}
	
}







