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
	
	// 반복자에 대해서
	// 반복자는 "요소의 포인터 역활"을 하는데.
	// map 의 요소는 "std::pair" 입니다.
	// 따라서, map 의 반복자는 "pair 의 포인터"
	// 처럼 생각하면 됩니다.
	auto p2 = m.begin();

	std::cout << p2->first << std::endl;
	std::cout << p2->second << std::endl;







	// 반복자에 대해서
	auto p = m.find("wed"); // find(키값)

	// p를 사용해서 "wed : 수요일" 이라고 출력해보세요

	// [] 연산자
	std::cout << m["sun"] << std::endl; 
}




