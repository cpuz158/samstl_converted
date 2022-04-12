#include <vector>
#include <algorithm>
#include <functional>	
#include "show.h"
/*
class ClosureType1
{
public:
	inline auto operator()(int a, int b) const  { return a + b;	}
};

class ClosureType2
{
public:
	inline auto operator()(int a, int b) const { return a + b; }
};
*/
int main()
{
	// 모든 람다 표현식은 다른 타입입니다.
	auto f = [](int a, int b) { return a + b; };
	auto g = [](int a, int b) { return a + b; };

	std::cout << typeid(f).name() << std::endl;
	std::cout << typeid(g).name() << std::endl;

	// bool b1 =  (f == g);  // error. 서로 다른 타입을 == 할수 없습니다
	// bool b2 =  (&f == &g);// error. 다른 타입이고, 객체 자체도 다른 객체.

//	auto f = [](int a, int b) { return a + b; };
//	auto f = ClosureType(); // 임시객체가 생성되고 f가 임시객체를 가리키는것이 아니라
							// "ClosureType f" 입니다.
							// ClosureType 의 객체 f
}


