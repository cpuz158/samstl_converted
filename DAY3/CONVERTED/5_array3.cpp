#include <vector>
#include <algorithm>
#include "show.h"
#include <array> // 이 안에 array2.cpp 에서 만든 코드가 있습니다.
				 // C++11부터 도입

int main()
{
	std::array<int, 10> arr = { 1,2,3,4,5,6,7,8,9,10 };
				// int arr[10]

	// 아래 코드 생각해보세요
	arr.push_back(1); // error
	arr.resize(7);	  // error

	// std::array 는 내부적으로 raw array 입니다.
	// 그래서, 크기 조절, 삽입/삭제 는 모두 불가능합니다.
	// 단지, "raw 배열 + 몇가지 도움 함수" 로 되어 있습니다.

}
