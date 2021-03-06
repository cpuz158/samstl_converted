#include <iostream>
#include <thread>
#include <future> 
#include <chrono>
using namespace std::chrono;
using namespace std::literals;

// 스레드에서 결과를 가져 오고 싶다.
// promise & future

// 1단계. 스레드 함수를 만들때 "promise" 객체를 참조로 받습니다.
void foo( std::promise<int>& p )
{
	std::this_thread::sleep_for(5s);
	
	// 2단계. 연산 수행후에.. 결과를 약속객체에 넣어 줍니다
	p.set_value(100);
}

int main()
{
	// 스레드 생성 코드
	// 1단계. promise 객체를 만듭니다. 
	std::promise<int> p;

	// 2단계. promise 객체에서 future 객체를 꺼냅니다.
	std::future<int> ft = p.get_future();

	// 3. 스레드 생성시 promise 객체를 "참조로 전달" 합니다.
	std::thread t(&foo, std::ref(p) );

	std::cout << "main 계속 실행" << std::endl;

	// 4. 스레드 결과를 얻고 싶으면 future의 get 사용
	// => 이때 결과가 있을수도 있고, 
	// => 아직 없을수도 있습니다. 없으면 대기하기 됩니다.
	int result = ft.get();

	std::cout << "결과 : " << result << std::endl;
						
	t.join();
}


