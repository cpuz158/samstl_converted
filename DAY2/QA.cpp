// QA
#include <iostream>
#include <functional>
#include <type_traits>
#include <concepts>

// 1. Sort() 는 마지막 인자로 int 2개를 비교할수 있는 함수(객체)를 기대하고 있습니다.
// 2. 그런데, 사용자가 전혀 관련없는 "int k" 를 보내고 있습니다.
// 3. Sort(int*, int*, int) 함수를 생성하고
//    생성된 함수를 다시 컴파일 할때, cmp(0,1) 에서 int cmp를 호출할수 없다고에러
/*
template<typename T>
void Sort(int*, int*, T cmp)
{
	cmp(0, 1);
}
*/
// C++이 아닌 대부분의 언어에는 Generic 제약(constraint) 라는 개념이 있습니다.
// C++ 은 Generic 제약 문법이 C++20에서 도입되었습니다.

// 1. C++11 ~ C++17 까지는 enable_if 라는 기술(문법이 아닌 테크닉)로 해결
// 2. C++20 에서는 concept 이라는 문법 도입.
/*
template<typename T> requires std::is_integral_v<T>
void Sort(int*, int*, T cmp)
{
//	cmp(0, 1);
}
*/

template<typename T> requires std::predicate<T, int, int> 
void Sort(int*, int*, T cmp)
{
	//	cmp(0, 1);
}

int cmp(int a, int b) { return 0; }

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	int k = 0;
//	double k = 0;

//	Sort(x, x+10, cmp); // ????
	Sort(x, x + 10, k); // ????

}