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
					// 여유 공간이 없으므로 메모리 재할당 필요
					// expensive operation

	std::cout << v.size() << std::endl;     // 9
	std::cout << v.capacity() << std::endl; // g++ : 16(즉, 2배씩 확장)
									// cl(visual studio) : 12(1.5배)

	v.reserve(100); // 메모리(capacity)만 100 으로

	std::cout << v.size() << std::endl;     // 9
	std::cout << v.capacity() << std::endl; // 100

	// list 에는 capacity 개념이 없습니다.
	// vector 에만 있습니다.


	// 아래 2개의 코드의 차이점을 알아두세요
	// 아래 코드는 무조건 2번으로 하셔야 합니다.
	// 1.
	std::vector<int> v1(100); // 100개를 만들어 놓고
	v1.resize(0);             // 일단, 크기는 0으로 놓고 출발
							  // size = 0, capacity = 100
	// 그런데.. 이코드는
	// std::vector<int> v1(100);    1. sizeof(int) * 100의 메모리 할당
								 // 2. int 타입이 아니라 사용자 정의타입이면
								 //	   100번의 생성자 호출


	// 2. 
	std::vector<int> v2;
	v2.reserve(100);		// size = 0, capacity = 100
							// 1. 100개의 메모리만 할당
							//    int 가 아닌 사용자 정의 타입이라도 생성자호출안됨




}









// 파이썬의 경우도 마찬가지입니다
// s = [1,2,3]  // 내부적으로는 4개 할당
// s.append(4)  // 여유 공간에 들어가므로 메모리 재할당 없음
// s.append(5)  // 4개 => 8개 메모리로 확장합니다.



