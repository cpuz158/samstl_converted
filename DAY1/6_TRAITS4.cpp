// 6_TRAITS4.cpp
#include <vector>
#include <iostream>
// 함수 인자 관례
// 반복자   : call by value 를 주로 사용 (크기가 크지 않은 타입)
// 컨테이너 : const reference 또는 reference  사용

template<typename T> void f1(T p)
{
	// T 는 객체형 반복자 또는 raw pointer 입니다.
	// 둘다 사용법이 동일하므로 *p 등으로 요소 접근 가능합니다
	auto n = *p; // 객체형 반복자건, raw pointer 건 모두 가능..
	++p;         // ok..

	// 그런데, 반복자가 가리키는 타입이 필요하면
//	typename T::value_type n2; // 이 코드는 객체형 반복자에 대해서만 동작

	typename std::iterator_traits<T>::value_type n2; // ok
						// T가 객체형 반복자건, raw pointer 이건 모두 가능

	// 참고, 위 표기법이 너무 복잡해서, C++20에서 새로운 표기법이 등장합니다
//	std::iter_value_t<T> n3; // ok. 위와 동일. typename도 필요 없음.

}

template<typename T> void f2(T& c)
{
	// T는 STL Container 이거나, raw array 입니다.
	// std::begin()등으로 반복자를 꺼내면 안전 합니다.
//	auto p1 = c.begin(); // c가 배열이면 안됨.

	auto p1 = std::begin(c); // ok.. 모두 가능.


	// 컨테이너가 저장하는 타입을 알고싶다.
//	typename T::value_type n;	// T 가 STL Container 일때만 가능..
								// T가 배열이면 error

	// iterator_traits 처럼
	// 컨테이너와 배열에 상관없이 요소의 타입을 구하는 방법은 없나요 ?
	// => C++20이 되어서야 도입되었습다.
//	std::ranges::range_value_t<T>  n; // ok
}

int main()
{
	int x[4] = { 1,2,3,4 };
	std::vector<int> v = { 1,2,3,4 };
	
	f2(v); // 컨테이너 전달
	f2(x); // raw array 전달


	f1(v.begin()); // 객체형 반복자 전달
	f1(x);		   // raw pointer 전달
}