#include <iostream>
#include <functional>
void f1() { std::cout << "f1" << std::endl; }

struct FOO
{
	void operator()() { std::cout << "FOO operator()" << std::endl; }
};

//void call_ntimes(int n, void(*f)())				// 1. 함수객체를 보낼수 없다.
void call_ntimes(int n, std::function<void()> f )
{
	for (int i = 0; i < n; i++)
		f();
}

int main()
{
	FOO f2;
	call_ntimes(3, f1); // 
	call_ntimes(3, f2); // 
	call_ntimes(3, []() { std::cout << "lambda" << std::endl; }); // 
}