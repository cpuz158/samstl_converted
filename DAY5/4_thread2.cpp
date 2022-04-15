#include <iostream>
#include <thread> 

void f1() {}

void foo(int n, double d)
{
	std::cout << "foo" << std::endl;
}

class Test
{
public:
	void goo(int n, double d)
	{
		std::cout << "goo" << std::endl;
	}
};

int main()
{
	// 핵심 1. 스레드를 생성하는 방법
//	std::thread t1( &f1 ); // 이순간 스레드가 생성되어서 f1 함수 실행됩니다.
						   // 별도의 start() 같은 함수는 필요 없습니다.

	// 핵심 2. 모든 종류의 함수를 스레드로 수행할수 있습니다.
	//        인자의 형태에 제한 없습니다.
	//        함수, 멤버 함수, 함수객체, 람다표현식 모두 가능
//	std::thread t2(&foo, 3, 3.4 ); 
//	std::thread t3( []() { std::cout << "lambda" << std::endl; } );

	Test test;
	std::thread t4(&Test::goo, &test, 3, 3.4);

	t4.join();
}


