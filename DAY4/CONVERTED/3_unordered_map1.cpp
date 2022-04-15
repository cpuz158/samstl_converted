#include <iostream>
#include <string>
#include <unordered_map>

int main()
{
	// pair 를 저장하는 hash(unordered_set)
	std::unordered_map<std::string, std::string> m;

	// map 과 사용법이 거의 동일합니다
	m["sun"] = "일요일";

	auto ret = m.find("sun");

	std::cout << ret->first << std::endl;
	std::cout << ret->second << std::endl;

}


