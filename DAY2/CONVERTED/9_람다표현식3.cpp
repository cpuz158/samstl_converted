#include <vector>
#include <algorithm>
#include <functional>	
#include "show.h"

int main()
{
	// 아래 코드를 보고 sort() 함수는 몇개 일지 예측해 보세요
	// => 같은 람다 표현식이라도, 다른 타입입니다.
	std::sort(x, x + 10, [](int a, int b) { return a < b; });
	std::sort(x, x + 10, [](int a, int b) { return a < b; });
	std::sort(x, x + 10, [](int a, int b) { return a < b; });

	// 동일한 람다표현식을 여러번 사용한다면 
	// "auto 변수에 담아 놓고 사용하는 것이 좋을때가 있습니다."
	auto cmp = [](int a, int b) { return a < b; };
	std::sort(x, x + 10, cmp);
	std::sort(x, x + 10, cmp);
	std::sort(x, x + 10, cmp);
}


