#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "show.h"

// "알고리즘은 컨테이너를 알지 못한다."

int main()
{
	std::vector<int> v = { 1,2,3,1,2,3,1,2,3,1 };

	// remove 알고리즘은 요소를 (메모리)제거하는 것이 아니라..
	// 3을 만나면 뒤의 요소를 앞으로 당겨 놓는 역활입니다.
	// 반환값으로 나오는 반복자는 유효한 구간의 마지막 다음 요소를 가리킵니다.
	auto p = std::remove(v.begin(), v.end(), 3);

	show(v);  

	// 유효하지 않은 구간을 제거하려면 vector의 멤버 함수를 사용해야 합니다.
	// 컨테이너를 진짜 메모리 제거 하는 것은 
	// 알고리즘이 아닌 "각 컨테이너의 멤버 함수" 만 가능합니다.
	v.erase(p, v.end());
	show(v);

	// 실제로, 연속된 메모리에서 특정값을 제거하는 방법은 위 방법 밖에 없습니다.
	// => 나쁜 것 아닙니다.
	
	// 일반적으로 아래 처럼 한줄로 많이 합니다.
	// 아래 코드는 "erase-remove" 라는 이름을 가지고 있습니다.
	v.erase( std::remove(v.begin(), v.end(), 3), v.end());
	return 0;
}



















//
