#include <iostream>

// callback 방법
void call_ntimes(int n, void(*f)())
{
	for (int i = 0; i < n; i++)
		f();
}

void f1() { std::cout << "f1" << std::endl; }

int main()
{
	call_ntimes(3, f1); // f1을 3번 호출해 달라.
}