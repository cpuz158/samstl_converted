#include <vector>
#include <iostream>
#include <algorithm>
#include "show.h"

// capacity 개념
int main()
{
	std::vector<int> v(10, 0);

	v.resize(7); // 어떻게 구현했을까요 ?

	std::cout << v.size()     << std::endl;	// 7
	std::cout << v.capacity() << std::endl;	// 10

	v.push_back(20); // 끝에 한개 추가.
					 // 현재 상태는 메모리의 여유 공간이 있으므로
					 // 메모리 재할당 필요 없습니다.
					 // not expensive operation

	std::cout << v.size()     << std::endl; // 8
	std::cout << v.capacity() << std::endl; // 10

	v.shrink_to_fit(); // size == capacity 가 되도록 해달라.

	std::cout << v.size() << std::endl;     // 8
	std::cout << v.capacity() << std::endl; // 8

	v.push_back(3);  // 끝에 한개(3) 추가

	std::cout << v.size() << std::endl;     // 9
	std::cout << v.capacity() << std::endl; // ???

}




