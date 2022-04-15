#include <iostream>
#include <string>
#include <vector>
#include <ranges>
#include <iterator>

int main()
{
	std::vector<int> v = { 1,2,3,4 };

	// 아래 3줄을 생각해 보세요
	auto p1 = v.begin(); // ok.!!
	auto p2 = std::vector<int>{ 1,2,3 }.begin();
	auto p3 = std::begin( std::vector<int>{1, 2, 3} );

//	*p2 = 10;

	// 위처럼 기존의 begin 은 몇가지 문제가 있었습니다.
	// 그래서 새로운 begin 을 만들었습니다.
	auto p4 = std::ranges::begin(std::vector<int>{1, 2, 3});
//	auto p4 = std::ranges::begin(v);

}