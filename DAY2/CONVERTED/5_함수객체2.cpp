#include <iostream>

// 0 ~ 9 사이의 "중복 되지 않은" 난수를 반환하는 함수

// 함수는 동작이 있는데, 상태가 없습니다.
// => 함수 수행중 만들어진 데이타를 보관해 놓고 싶어도, 보관할 곳이 없습니다.
// => 그래서, 보통 전역변수등을 많이 사용합니다.
int urand()
{
	return rand() % 10;
}

int main()
{
	for (int i = 0; i < 10; i++)
		std::cout << urand() << std::endl;
}





