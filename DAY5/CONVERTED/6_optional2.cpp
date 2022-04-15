// 6_optional
#include <iostream>
#include <optional> // C++17 부터 나온 도구 입니다.

// 실패의 가능성이 있는 함수를 만들때
// 1. 예외를 사용하거나
// 2. optional 로 하자.
std::optional<int> foo()
{
	if (1)
	{
		return std::nullopt;
	}
	return 100;
}

int main()
{
	auto ret = foo();
	if (ret) // ret != std::nullopt
	{
		int n = *ret;
	}
}
