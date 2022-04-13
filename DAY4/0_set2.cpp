#include <iostream>
#include "show.h"
#include <set> 
#include <functional>

int main()
{
	std::set<int> s;

	s.insert(20);
	s.insert(30);
	s.insert(15);
	s.insert(5);
	s.insert(40);



	// 핵심 1. 요소의 중복을 허용하지 않는다.
	// insert() 반환 타입은 pair 입니다.
//	std::pair< std::set<int>::iterator, bool> ret = s.insert(15); // 실패

	auto ret = s.insert(15);

	if (ret.second == false)
		std::cout << "fail" << std::endl;
	else
		std::cout << "ok" << std::endl;



	// 핵심 2. 요소 삽입은 insert(또는 emplace) 만 가능합니다.
	//        항상 자료구조의 특징을 잘 생각하세요..
//	s.push_front(37); // error


	// 핵심 3. 반복자로는 읽기만 가능합니다.
	auto p1 = s.begin();
//	*p1 = 100; // error. 


	// 핵심 4. 자료구조 특성에 맞는 함수를 사용하세요.
	
	// 아래 코드는 에러가 아니고, 잘동작하지만, 선형검색으로 값을 찾는 코드입니다.
	// 비효율적입니다. set(tree)를 사용하는 이유는 선형검색을 하려고 사용합니다.
	auto ret1 = std::find(s.begin(), s.end(), 15);
	std::cout << *ret1 << std::endl;

	auto ret2 = s.find(15); // 이진 검색
	std::cout << *ret2 << std::endl;

	// "알고리즘과 동일한 이름의 멤버 함수 있으면
	//  멤버 함수를 사용해라!"

}







