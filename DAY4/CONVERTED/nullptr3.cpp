#include <iostream>

// nullptr 의 역사
// 1. boost 라이브러리에서 아래처럼 만들어서 제공했습니다.
// 2. C++11 에서 표준에 추가되면서는 nullptr 을 키워드로 만들었습니다.

struct xnullptr_t
{
	template<typename T>
	operator T* () const { return 0; }
};
xnullptr_t xnullptr;

int main()
{
//	int n = xnullptr; // error. 

	int*  p1 = xnullptr; // ok
	char* p2 = xnullptr; // ok
}
