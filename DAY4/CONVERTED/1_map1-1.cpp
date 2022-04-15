// 1_map1-1
#include <string>
#include <map>
#include <iostream>

int main()
{
	std::map<std::string, std::string> m;

	m.emplace("mon", "월요일");
	m.emplace("sun", "일요일");

	// map 과 range-for
	for (const auto& e : m)
	{
		std::cout << e.first << std::endl;
	}

	// C++17 부터 가능한 문법
	std::pair<int, int> p(1, 2);

	auto [a, b] = p; // auto a = p.first
					 // auto b = p.second;

	for (auto [key, value] : m)
	{
		std::cout << key   << std::endl;
		std::cout << value << std::endl;
	}
}