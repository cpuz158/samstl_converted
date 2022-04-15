// 4_traits
#include <iostream>
#include <type_traits> // C++11 에서 추가된 라이브러리

/*
template<typename T> void printv(const T& v)
{
	if ( std::is_pointer<T>::value  )
		std::cout << v << " : " << *v << std::endl;
	else 
		std::cout << v << std::endl;
}
*/

// C++17 의 새로운 if 문 : if constexpr 
// => 컴파일 시간 if 문, 템플릿 만들때 주로 사용
// => 조건이 false 인 경우, 실제 C++ 코드(함수, 클래스)를 만들때 포함되지 않는다.

template<typename T> void printv(const T& v)
{
	if constexpr (std::is_pointer<T>::value)
		std::cout << v << " : " << *v << std::endl;
	else
		std::cout << v << std::endl;
}


int main()
{
	int n = 10;
	double d = 10;

	printv(n);
//	printv(d);
	printv(&n);
}

