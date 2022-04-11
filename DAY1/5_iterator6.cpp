#include <iostream>
#include <list>
#include <algorithm>

int main()
{
	int x[5] = { 1, 2, 3, 4, 5 };
	int y[5] = { 0, 0, 0, 0, 0 };
	
	std::list<int> s2 = { 0,0,0,0,0 };

	// x 의 모든 요소를 y로 복사하고 싶다.
	// 1. for 문 사용
//	for (int i = 0; i < 5; i++)
//		y[i] = x[i];

	// 2. range-for
//	int i = 0;
//	for (auto e : x)
//		y[i++] = e; // 인데.. i가 필요 합니다


	// 3. copy 알고리즘을 사용해도 됩니다. - 과정에서 많이 사용할 예정
	std::copy(x, x + 5,  // [first, last) 전달.. 완전한 구간
			  y);

	for (auto e : y)
		std::cout << e << ", ";

	std::copy(s2.begin(), s2.end(), y); // 컨테이너버전.
}