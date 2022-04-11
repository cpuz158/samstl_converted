#include <iostream>
#include <list>   
#include <vector>

// 반복자 무효화
// => 특정 컨테이너의 어떤 멤버 함수가
//    반복자를 무효화 시키는 지, 알고서 사용해야 합니다.
// 
// => cppreference.com 에 접속해서
//    std::vector 찾아 보세요
int main()
{
	std::vector<int> v = { 1,2,3,4,5 };
	
	auto p = std::begin(v); // v.begin()

	std::cout << *p << std::endl; // 1


	v.resize(10); // 이순간 vector가 사용하던 버퍼가 재할당됩니다.
				  // 이전에 꺼내 놓았던 모든 반복자는 사용할수 없습니다
				  // interator invalidate(반복자 무효화 현상)

	std::cout << *p << std::endl; // 안전할까요 ?
}



