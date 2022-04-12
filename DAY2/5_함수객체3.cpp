#include <iostream>
#include <bitset>  // STL 이 제공하는 "비트"를 관리하는 클래스

// 일반 함수는 "상태를 가질수 없지만"
// 함수 객체는 "상태를 가질수 있습니다." => 멤버 데이타를 만들수 있다는 의미.

class URandom
{
	std::bitset<10> bs;
	bool recycle;
public:
	URandom(bool b = false) : recycle(b)
	{
//		bs.set(5); // 5번째 비트만 1로
		bs.set();  // 모든 비트를 1로
	}

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





