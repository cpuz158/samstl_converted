// 2_adapter2-1
#include <iostream>
#include <list>
#include <algorithm>
#include "show.h"

int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,3,9,10 };

	// 주어진 구간에서 3을 찾고 싶다.
	auto ret1 = std::find(s.begin(),  s.end(),  3); // 앞에서 부터 검색
	auto ret2 = std::find(s.rbegin(), s.rend(), 3); // 뒤에서 부터 검색

	std::list<int> s2;

	// s의 모든 내용을 s2로 복사하는데, 거꾸로 하고 싶다.??

	show(s2); // 10,9, 3,7, 6,5,4,3,2,1
}
