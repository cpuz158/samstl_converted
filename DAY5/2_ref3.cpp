#include <iostream>

void foo(int& a) { a = 200; }

// bind_call : 함수, 인자를 받아서
//				함수(인자)형태로 호출해 주는 도구
template<typename F, typename T> void bind_call(F f, T arg)
{
	f(arg);
}
int main()
{
	int n = 10;
	foo(n);	// 직접 전달, n은 200으로 변경됩니다.
//	bind_call(foo, n);
//	bind_call(foo, &n); // 값이 아닌 n의 메모리 주소를 보냅니다.

	// reference_wrapper의 의미 : 객체의 주소를 보관하는데, 참조로도 변환가능한 도구
//	std::reference_wrapper<int> r(n); // 1. r은 n의 주소를 보관		
								  // 2. 참조로 변환 가능
//	bind_call(foo, r);

	bind_call(foo, std::ref(n)); // std::ref(n) 이 결국
								 // std::reference_wrapper 를 만들어 주는 도움함수입니다.
								// 이줄과 위 2줄은 동일 합니다.


	std::cout << n << std::endl; 
}
