#include <iostream>
#include <vector>
#include <ranges> // C++20 에서 제공

// g++ 소스이름.cpp -std=c++20
// cl  소스이름.cpp /std:c++latest

// VC IDE 사용시는  C++ 버전 설정

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	// take_view 를 사용하는법
	// 1. take_view 클래스 이름 직접 사용
	std::ranges::take_view tv1(v, 3);

	// 2. take_view를 생성하는 take() 함수 사용
	auto tv2 = std::views::take(v, 3);



//	for (auto e : tv1)
	for (auto e : std::views::take(v, 3) )
	{
		std::cout << e << std::endl;
	}

}