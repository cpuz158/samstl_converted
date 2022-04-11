// 6_TRAITS4.cpp
#include <vector>
#include <iostream>
// 함수 인자 관례
// 반복자 : call by value 를 주로 사용 (크기가 크지 않은 타입)
// 컨테이너 : const reference 또는 reference  사용

template<typename T> void f1(T c)
{
}

template<typename T> void f2(T& c)
{
}

int main()
{
	int x[4] = { 1,2,3,4 };
	std::vector<int> v = { 1,2,3,4 };
	
	f1(v.begin()); // 객체형 반복자 전달
	f1(x);		   // raw pointer 전달
}