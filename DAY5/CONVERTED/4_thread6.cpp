#include <iostream>
#include <thread>

// atomic

int x = 0;

void foo()
{
	for (int i = 0; i < 1000000; i++)
	{
//		m.lock();
//		x = x + 1;
//		m.unlock();

		// x = x +1 의 어셈은 아래와 같습니다. 32bit
		/*
		__asm
		{			
			mov eax, x
			add eax, 1
			mov x, eax
		}
		*/

		// 1증가하기 위한 어셈을 다르게 해 봅시다.
		// inc : 실행중 context swiching 이 발생하지 않은 것은 보장합니다.
		//       그런데, CPU 자체가 여러개 인 경우는 1증가 보장 안됨
		// 
		// lock prefix : 다중 CPU 에서, 특정 메모리를 동시에 접근할수 없게하는
		//				intel opcode
		__asm
		{
			lock inc x 
		}
		// lock free : OS 의 동기화 도구를 사용하지 않고
		//				CPU 명령만 가지고, 동기화를 구현하는 기술

	}
}

int main()
{
	std::thread t1(&foo);
	std::thread t2(&foo);
	std::thread t3(&foo);
	t1.join();
	t2.join();
	t3.join();
	std::cout << x << std::endl;
}