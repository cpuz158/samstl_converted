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

//	std::copy(s2.begin(), s2.end(), y); // 컨테이너버전.
	std::copy(s2.rbegin(), s2.rend(), y); // 역순으로 복사.. 
										  // 원리는 내일..

	// 컨테이너간, 배열이건.. 결국 반복자로 작업하므로.. 동일하게 사용
}
// 주의!!
// 반복자란 : "반복자 처럼 동작하는 모든 것은 반복자이다."
//          ++로 이동가능하고, *로 요소 접근이 가능하면 반복이다.
// 1. slist_iterator 처럼 클래스로 만든것도 반복자 이고..
// 2. int* p 처럼 raw pointer도 반복자 이다.