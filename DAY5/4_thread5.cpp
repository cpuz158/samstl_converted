#include <iostream>
#include <thread>
#include <future> 
#include <chrono>
using namespace std::chrono;
using namespace std::literals;

// 스레드로 수행할 함수도
// 일반 함수와 동일하게 반환 값으로 반환 합니다.
int foo()
{
	std::this_thread::sleep_for(5s);

	return 100;
}
/*
void 내부스레드함수(promise<int>& p)
{
	int ret  = foo();
	p.set_value(ret);
}
*/

int main()
{
//	int ret = foo(); // 스레드 수행이 아닌. 주스레드가 함수 호출

	// foo 함수를 스레드로 실행하고, 결과를 future 객체로 반환해 달라.
	std::future<int> ft = std::async(std::launch::async, &foo);

	std::cout << "main 계속 실행" << std::endl;

	int result = ft.get();  // 스레드 함수(foo)가 아직 return 하지 않은 경우는
							// 대기

	std::cout << "결과 : " << result << std::endl;
}


