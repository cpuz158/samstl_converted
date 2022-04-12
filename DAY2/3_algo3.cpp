#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "show.h"

// 알고리즘과 동일한 이름의 멤버 함수가 있다면 멤버 함수를 사용하라.

// 핵심 정리.. "컨테이너에 대해서 어떤 작업을 수행하고 싶다면"

// 1. 멤버 함수에 해당하는 작업을 수행하는 함수가 있는지 찾아라!!
//    ==> 멤버 함수에 있으면.. 사용..
// 
// 2. 멤버 함수에 없으면, "알고리즘(멤버가 아닌 일반함수)" 에서 찾아라!
//    ==> 있으면 사용..

// 3. "알고리즘에도 없거나, 해당 알고리즘에 컨테이너 반복자를 보낼수 없다면"
//    ==> 해당 컨테이너에서 해당작업을 할수 있는지 생각해 보자.


int main()
{
//	std::vector<int> v = { 1,2,3,1,2,3,1,2,3,1 };
	std::list<int>   v = { 1,2,3,1,2,3,1,2,3,1 };

//	auto p = std::remove(v.begin(), v.end(), 3);
//	show(v);
//	v.erase(p, v.end());
//	show(v);

	// list 도 위 4줄이 실행되는 데는 문제 없지만 성능이 좋지 않습니다.
	// 아래처럼 멤버 함수 remove 를 사용하세요..
	v.remove(3);
	show(v);


	return 0;
}
