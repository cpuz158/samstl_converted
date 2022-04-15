#include <iostream>
#include <thread>
#include <functional>

void f1(int  n) { n = 100; }
void f2(int& n) { n = 100; }

int main()
{
	int v = 10;
	
	std::thread t1(f1, v); // f1을 스레드로 실행해 달라, 
						   // 인자로 v 를 보내 달라.
	t1.join();

//	std::thread t2(f2, v); // error.

	// 결국 v 는 직접 f2로 전달되는 것이 아니라
	// v => thread 생성자 => f2로 전달되게 되는데
	// thread 생성자가 call by value 로 되어 있습니다.
	// call by value 로 된 곳에 "참조로 보내려면 std::ref()" 를 사용해야합니다
	std::thread t2(f2, std::ref(v)); // ok.
	t2.join();
}
