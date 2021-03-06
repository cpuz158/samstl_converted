#include <iostream>
#include <vector>
#include <algorithm>
#include "show.h"

int main()
{
	std::vector<int> v1 = { 1,2,3,4,5,6,7,8,9,10 };
	std::vector<int> v2 = { 0,0,0,0,0,0,0,0,0,0 };

	// 1. inplace, 값 버전
//	auto p1 = std::remove(v1.begin(), v1.end(), 3);

	// 2. inplace, 조건자 버전
//	auto p2 = std::remove_if(v1.begin(), v1.end(), 
//						[](int n) { return n % 2 == 0; });


	// 3. copy, 값 버전
	// copy(v1=>v2) 후에 remove(v2) 를 하는 것 보다는 
	// remove_copy 를 하면 2배의 성능향상이 있기 때문에 별도로 제공
	// sort_copy 는 없다. 이유는 copy 와 sort 는 비슷한 시간이 아니라 sort()가 훨씬 비싸다.
	// 그래서, "copy 후 sort" 해도 된다.

	// 주의 반환값 p3는 v2의 반복자 입니다.
	auto p3 = std::remove_copy(v1.begin(), v1.end(), 
							   v2.begin(), 
							   3);

	// 4. copy, 조건자 버전
	auto p4 = std::remove_copy_if(v1.begin(), v1.end(),
								 v2.begin(),
								[](int n) { return n % 2 == 0; });


	show(v1);
	show(v2);
}
