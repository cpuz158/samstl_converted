// 1_map1-1
#include <string>
#include <map>
#include <iostream>

int main()
{
	std::map<std::string, std::string> m;

	m.emplace("mon", "월요일");
	m.emplace("sun", "일요일");

	for (auto e : m)
	{
		
	}
}