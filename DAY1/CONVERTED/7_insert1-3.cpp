// 7_insert1-3
#include <iostream>
#include <list>
#include <vector>

int main()
{
	std::list<int>   s = { 1,2,3 };

	auto p1 = std::back_inserter(s);
	
	*p1 = 10; // s.push_back(10);
	*p1 = 20; // s.push_back(20) 으로 자동으로 추가 됩니다.

	// 원래 모든 반복자는 ++을 해야 다음으로 이동입니다
	// 그런데, 삽입 반복자는 ++ 안해도 됩니다.
	// ++을 해도 됩니다.
	*p1 = 30; // s.push_back(10);
	++p1;     // ok.. 사실, ++에서는 아무일도 하지 않고 있습니다.
			  // 하지만, copy 등에 보내려면 ++이 아무 일도 하지 않아도
			  // 제공되긴 해야 합니다.
	*p1 = 40;

//	std::copy(x, x + 5, p1);
}