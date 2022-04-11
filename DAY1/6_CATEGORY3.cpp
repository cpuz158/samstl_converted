#include <iostream>
#include <vector>
#include <list>
#include <iterator>

int main()
{
//	std::vector<int> s = { 1,2,3,4,5,6,7,8,9,10 };
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };


	auto p = std::begin(s);

	
	// 반복자 p를 5칸 전진하고 싶다.
//	p = p + 5; // ok.. 그런데, 임의접근 반복자만 가능
//	++p; ++p; ++p; ++p; ++p; // ok.. 모든 반복자 가능.
							 // 그런데, p가 임의 접근 반복자이면 
							 // 성능이 나쁘다
							 // 
	// 반복자를 N 만큼 전진하는 함수.
	std::advance(p, 5); // 1. p가 임의접근이면 + 사용
						// 2.     임의접근이 아니면 ++ 사용

	
	std::cout << *p << std::endl;
}