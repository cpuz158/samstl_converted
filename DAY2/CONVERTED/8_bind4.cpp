#include <iostream>

void f1() { std::cout << "f1" << std::endl; }

struct FOO
{
	void operator()() { std::cout << "FOO operator()" << std::endl; }
};

// callback 방법
void call_ntimes(int n, void(*f)())
{
	for (int i = 0; i < n; i++)
		f();
}

int main()
{
	FOO f2;
	call_ntimes(3, f1); // ok
	call_ntimes(3, f2); // error
}