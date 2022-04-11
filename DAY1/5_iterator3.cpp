#include <iostream>
#include <list>   
#include <vector>

int main()
{
//	std::list<int> s = { 1,2,3,4,5 };
//	std::vector<int> s = { 1,2,3,4,5 };

	int s[5] = {1,2,3,4,5};


	// 반복자를 꺼내는 법
	// 1. C++11 이전 스타일
	//    => 컨테이너 교체시, 좌변 타입이 수정되어야 합니다.
//	std::list<int>::iterator p = s.begin();

	// 2. C++11 이후라면 auto 사용하세요
//	auto p = s.begin(); // 이 코드는 s 가 raw array 라면 error 입니다.


	// 3. C++11 이후, 유연성이 가장 좋은 코드는 아래 코드입니다.
	auto p = std::begin(s); // ok. s 가 STL 컨테이너 뿐 아니라, 
							//     raw array 라도 ok
	
	// 4. 참고, C++20 이후에는 아래 처럼 꺼내게 됩니다.
//	auto p1 = std::ranges::begin(s); // <ranges> 헤더 필요
									 // 3번보다 조금더 안전합니다.
									 // C++20 과정 참고.


}



