// 7_insert1-1
#include <iostream>

template<typename T>
T square(T a)
{
	return a * a;
}

// 함수 템플릿은 타입 인자를 생략할수 있지만, 
// 클래스(구조체) 템플릿은 타입인자를 생략할수 없다.( ~ C++14 까지)
// 그래서 클래스 템플릿을 바로 사용하면 항상 어려워 보입니다
// 
// 이 경우는 클래스 템플릿 의 객체를 만드는  함수 템플릿을 제공하면 편리합니다

// Object Generator 라는 이름을 가진 기술 입니다.
template<typename T, typename U>
std::pair<T, U> make_pair(const T& a, const U& b)
{
	return std::pair<T, U>(a, b);
}

int main()
{
	// 다음중 쉬워 보이는 것은 ?
	square<int>(3); // 1
	square(3);		// 2.  쉬워 보인다!!

	std::pair<int, double> p1(3, 3.4); // int, double을 생략할수 있을까 ?

//	auto p2 = make_pair<int, double>(3, 3.4); // 이 표현이 정확한 표현이지만
//	auto p2 = make_pair(3, 3.4); // 이렇게 해도 됩니다.

	auto p2 = std::make_pair(3, 3.4);


	std::pair p3(3, 3.4); // C++17 부터는 클래스(구조체)템플릿도
							// 타입 인자 생략 가능합니다
}


