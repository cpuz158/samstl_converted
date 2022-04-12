#include <iostream>


class URandom
{
public:
	int operator()()
	{
		return rand() % 10;
	}
};

URandom urand; // 이제, urand 는 함수가 아닌 객체입니다.
			   // 하지만, 함수처럼 사용가능합니다.

int main()
{
	for (int i = 0; i < 10; i++)
		std::cout << urand() << std::endl;
}





