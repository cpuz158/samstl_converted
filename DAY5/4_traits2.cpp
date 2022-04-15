#include <iostream>

// Traits : 타입(T) 에 대한 다양한 특성을 조사하는 기술
// "템플릿 부분특수화 문법"으로 만드는 도구

template<typename T> struct is_pointer
{
	enum { value = false };
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

