#include <iostream>
#include <list>

// STL 에서 반복자는 크게 2가지 형태로 볼수 있습니다.
// 
// 1. class 로 만드는 객체형 반복자(slist_iterator)
//    => 객체(클래스) 이므로 "T::value_type" 이 존재 합니다.

// 2. raw pointer (int*, double* 등)
//    => "int*::value_type" 등이 존재 하지 않습니다

// 위 2가지 차이점 때문에 sum 같은 함수를 generic 하게 만들기 어렵습니다

// 이문제의 해결책이 아래 코드 입니다.
template<typename T> struct iterator_traits
{
	using value_type = typename T::value_type;
};

template<typename T> struct iterator_traits<T*>
{
	using value_type = T;
};

template<typename T>
typename std::iterator_traits<T>::value_type sum(T first, T last)
{
//	typename T::value_type s = 0;

//	typename iterator_traits<T>::value_type s = 0;
	typename std::iterator_traits<T>::value_type s = 0;




	while (first != last)
	{
		s = s + *first;
		++first;
	}
	return s;
}

int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };


	int n1 = sum(std::begin(s), std::end(s));
	int n2 = sum(x, x + 10); // ???

	std::cout << n1 << std::endl; 
	std::cout << n2 << std::endl; 
}
