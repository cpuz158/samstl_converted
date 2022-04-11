#include <iostream>

// Step 4. 보다 Generic 하게.. - 약간 어려운 이야기

// 템플릿을 아래 처럼 만들면 2개의 문제점이 있습니다.

// template<typename T>
// T* find(T* first, T* last, T c)

// 1. 구간의 타입과 검색 대상 타입이 연관됩니다.
//    double 배열에서 double 만 검색 가능하고,
//    int, float 값은 검색이 안됩니다(T를 결정할수 없어서, 컴파일 에러)

// 2. "T*" 라고 하면 항상 "raw pointer 만 사용가능합니다."
//    스마트 포인터등을 사용할수 없습니다.

template<typename T1, typename T2>
T1 find(T1 first, T1 last, T2 value)
{
	while (first != last && *first != value)
		++first;

	return first == last ? nullptr : first;
}


int main()
{
	double x[10] = { 1,2,3,4,5,6,7,8,9,10 };

	double* p = find(x, x + 10, 5.0f); // ??


	if (p == nullptr)
		std::cout << "not found" << std::endl;
	else
		std::cout << "found : " << *p << std::endl;
}