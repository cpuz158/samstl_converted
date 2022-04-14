// github.com/codenuri/samstl 에서 "DAY5_사전소스.zip" 받으세요
// codexpert.org 에서 출석해 주세요

#include <iostream>
#include <functional>
using namespace std::placeholders;

// 핵심 : foo 함수의 2번째 인자는 "참조(reference)" 입니다.
void foo(int a, int& b) { b = 100; }

int main()
{
	std::function<void(int)> f;

	int n = 0;

//	f = std::bind(&foo, _1, n); // 이 한줄을 생각 해 봅시다.
								// foo 의 2번째 인자로
								// "n" 자체를 참조로 보관 하지않고
								// 값 0을 보관. 
	f = std::bind(&foo, _1, std::ref(n) ); // n을 참조로 보관해달라.

	f(0); // foo(0, n)

	std::cout << n << std::endl; // 결과 예측해 보세요
}


