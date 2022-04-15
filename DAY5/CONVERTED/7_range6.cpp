#include <iostream>
#include <vector>
#include <ranges> 

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };


	auto tv = v | std::views::take(5) | std::views::filter([](int n) { return n % 2 == 0; });



	for (auto& e : v)
	{
		e *= 10; // vector의 모든 요소 10배
	}
	v.clear();
	//--------------------------------

	for (auto e : tv)
	{
		std::cout << e << std::endl;
	}

}