#include <iostream>
#include "show.h"

// 서로 다른 타입의 값을 2개 보관할수 있는 범용적인 용도의 구조체
template<typename T, typename U> struct pair
{
	T first;
	U second;

	// 생성자들... 
};
//--------------------------------------------


template<typename T> void foo(T a) {}

int main()
{
	// pair : 서로다른 타입 2개를 보관하는 구조체
	std::pair<int, double> p1(1, 3.4);

	// 1. 요소 접근
	std::cout << p1.first  << std::endl;
	std::cout << p2.second << std::endl;

	// 2. make_pair
	auto p2 = std::make_pair(1, 3.4);

	foo( std::make_pair(1, 3.4) ); // 함수 인자로 pair 를 보낼때
								 // make_pair 를 사용하면 편리합니다.

	// 3. C++17 부터는 pair 자체도 타입생략 가능
	std::pair p3(1, 3.4);

}


