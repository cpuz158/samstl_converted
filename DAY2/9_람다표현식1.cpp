#include <vector>
#include <algorithm>
#include <functional>	
#include "show.h"

class ClosureType
{
public:
	inline auto operator()(int a, int b) const
	{
		return a + b;
	}
};

int main()
{
	// 람다표현식을 사용하면
	// 1. 위와 같은 클래스를 컴파일러가 생성하고
	// 2. 람다표현식코드를 "생성된클래스의 임시객체를 생성"하는 코드로 변경
	[](int a, int b) { return a + b; };  // 이 부분을
	// ClosureType()					 // 이렇게 변경

	auto f = [](int a, int b) { return a + b; };
			 // ClosureType();

	std::cout << typeid(f).name() << std::endl; 

	std::cout << f(1, 2) << std::endl; // 3
	std::cout << f.operator()(1, 2) << std::endl; // 3
}