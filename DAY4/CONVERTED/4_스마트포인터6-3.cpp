#include <cstdlib >

// C++ 스마트포인터의 목표는
// C 언어 포인터 3가지 문제점을 해결하는 것 입니다.
int main()
{
	// 1. 자원 누수, free 하는 않는 것.
	//    => 스마트 포인터는 자동삭제 기능이 있으므로 해결!
	int* p1 = (int*)malloc(20);

	// 2. double delete
	//	  => 스마트포인터는 참조 계수로 관리되므로 해결
	int* p2 = p1;
	free(p1);
	free(p2);
	
	// 3. dangling pointer - 포인터가 가리키는 곳이 이미 삭제된 경우
	int* p3 = (int*)malloc(4);

	free(p3); // 메모리는 파괴 되지만, p3가 0으로 reset 되는 것은 아님.

	if (p3 != 0)
		*p3 = 10;

}