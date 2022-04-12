#include <iostream>
#include <vector>
#include <functional>
using namespace std::placeholders;

class Machine
{
public:
	void mf1(int a) { std::cout << "mf1" << std::endl; }
	void mf2(int a, int b) {  std::cout << "mf2" << std::endl; } 
};
void f0() { printf("f0\n"); }
void f1(int a) { printf("f1 : %d\n", a); }

class Button
{
	using HANDLER = std::function<void()>; 

	std::vector< HANDLER > v;
public:
	Button(HANDLER h = 0 )
	{
		if (h != 0)
			v.push_back(h);
	}
	void addHandler(HANDLER h) { v.push_back(h); }

	void click()
	{
		for (auto f : v) 
			f();  // f 는 결국 function 이므로 ()로 호출하면 됩니다.
	}
};

int main()
{
	Button b1(&f0);
	Button b2(std::bind(&f1, 2));
	Button b3(std::bind(&f1, 3));

	b1.addHandler([]() { std::cout << "lambda" << std::endl; });
	b1.addHandler(std::bind(&Machine::mf1, Machine(), 10));

	b1.click();
}
