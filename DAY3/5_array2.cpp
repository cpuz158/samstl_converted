#include <vector>
#include <algorithm>
#include "show.h"

// 아래 코드를 잘 생각해 보세요
template<typename T, std::size_t N>
class array
{
	T buff[N];

	int size() const { return N; }
};

int main()
{
	// array
	// 1. 모든 요소가 스택에 있습니다.(배열과 동일)
	array<int, 10> arr = { 1,2,3,4,5,6,7,8,9,10 };

	// raw array 는 멤버함수가 없지만 array 는 멤버함수가 있습니다.
	std::cout << arr.size() << std::endl; 
}
