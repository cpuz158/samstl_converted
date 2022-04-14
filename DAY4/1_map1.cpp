// 6_map1
#include "show.h"
#include <map>  

// map : pair 를 저장하는 set,   key 값으로 value 를 저장

int main()
{
	std::map<std::string, std::string> m;

	// 요소 넣기
	// 1. pair 만들어서 넣기
	std::pair<std::string, std::string> p1("mon", "월요일");

	m.insert(p1);


	// 2. make_pair
	m.insert( std::make_pair("tue", "화요일") );


	// 3. emplace
	m.emplace("wed", "수요일");


	// 4. [] 연산자 사용
	m["sun"] = "일요일";

	//------------------------
	
	// 2. 반복자에 대해서
	// 반복자는 "요소의 포인터 역활"을 하는데.
	// map 의 요소는 "std::pair" 입니다.
	// 따라서, map 의 반복자는 "pair 의 포인터"
	// 처럼 생각하면 됩니다.
	auto p2 = m.begin();

	std::cout << p2->first << std::endl;
	std::cout << p2->second << std::endl;


	// 3. [] 연산자에 대해서
	std::string s1 = m["sun"]; // 맵안에 sun 키가 있으므로 s2는 "일요일"
	std::string s2 = m["sat"]; // 현재 맵안에 "sat" 키는 없습니다.
							   // 이 순간 {"sat", ""} 의 쌍으로 항목이 추가됩니다.

	// 그래서, 키값이 있는지 검색할때는 아래 처럼하지 마세요
	if (m["aaa"] != "")  // 가능은 하지만, 이순간 키값이 만들어지게 됩니다.
	{					  // 의도는 단순한 조사 였는데, 이 코드는 키값의 생성이됩니다.

	}
	// 조사는 아래 코드로 하세요
	auto ret = m.find("sun");

	if ( ret == m.end() ) {} // "sun" 이 없는 경우.


	// C++20 에서 아래 멤버 함수가 추가되었습니다.
	if (m.contains("sun"))
	{
	}

}




