#include <iostream>

// Traits : 타입(T) 에 대한 다양한 특성을 조사하는 기술
// "템플릿 부분특수화 문법"으로 만드는 도구

// 만드는 방법
// 1. primary template 을 만들고 false 반환 ( value = false 라는 의미)
// 2. 조건을 만족하는(포인터) 경우의 부분 특수화를 만들고 true 반환

template<typename T> struct is_pointer
{
	enum { value = false };
};

template<typename T> struct is_pointer<T*>
{
	enum { value = true };
};


template<typename T> void foo(const T& b)
{
	if ( is_pointer<T>::value )

		std::cout << "포인터" << std::endl;
	else
		std::cout << "포인터 아님" << std::endl;	
}
int main()
{
	int n = 10;
	printv(n);
	printv(&n);
}

