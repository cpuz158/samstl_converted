#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::vector<int> v = { 1,2,3,4 };

	// 아래 3줄을 생각해 보세요
	auto p1 = v.begin(); // ok.!!

	auto p2 = std::vector<int>{ 1,2,3 }.begin();

	auto p3 = std::begin(std::vector<int>{1, 2, 3});


}