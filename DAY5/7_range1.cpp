// 7_range1
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	
	// 아래 코드를 원리를 알아 봅시다.
	for (auto e : v)
	{
		std::cout << e << std::endl;
	}
	//------------------------------------
	// 위 코드를 보고 컴파일러가 만드는 코드
	// 핵심 : for(auto e : "컨테이너")  에서 "컨테이너의 begin,end()" 사용을 꼭 기억하세요
	auto first = v.begin();
	auto last = v.end();

	for (auto p = first; first != last; ++p)
	{
		auto e = *p;
		//----------------------
		// 여기서 부터 사용자 코드
		std::cout << e << std::endl;
	}




}
// 참고 사이트
// 1. gotbolt.org    ==> C++(뿐아니라 거의 모든 언어)를 어셈블리어로 확인가능
// 2. cppinsights.io ==> 다양한 C++ 문법의 원리를 보여주는 사이트