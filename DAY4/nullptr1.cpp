// nullptr1
#include <iostream>

void fn(int   n) { std::cout << "int"   << std::endl; } // 1
void fn(void* n) { std::cout << "void*" << std::endl; } // 2

void goo(char* p) {}

int main()
{
	fn(0);			// 1
	fn((void*)0);	// 2
/*
#ifdef __cplusplus   // C++ 컴파일러인지 조사
	#define NULL 0
#else
	#define NULL (void*)0
#endif
*/
	fn(NULL);	// ok..

	goo(NULL);	// void* => char* 로의 변환이 필요 합니다.
				// C언어는 되지만 C++ 언어는 안됩니다.
}
