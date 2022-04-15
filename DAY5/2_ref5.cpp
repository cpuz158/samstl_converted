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

	std::thread t2(f2, v); // error.
	std::thread t2(f2, std::ref(v)); // ok.
	t2.join();
}
