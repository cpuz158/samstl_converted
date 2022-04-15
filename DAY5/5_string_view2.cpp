// 5_string_view
#include <iostream>
#include <string>
#include <string_view>

void* operator new(std::size_t sz)
{
	std::cout << sz << "메모리 할당" << std::endl;
	return malloc(sz);
}

// 인자로 문자열을 받고 싶습니다.
// 1. 가장 나쁜 코드
// void foo(std::string name)  {}

// 2. 가장 좋은 코드
//void foo(std::string_view name) {}

// 3. 아래 코드를 하면되지 않나요 ?
void foo(const std::string& name) {}

int main()
{
//	std::string s = "sdjfsljflsjlsdkjfssfsd";
//	foo(s);

	// string_view 와 const string& 를 이해 하려면 아래 경우를 생각해 보세요
	foo("sdjfsljflsjlsasdadadasdkjfssfsd");
}







/*
void* operator new(std::size_t sz)
{
	std::cout << sz << "메모리 할당" << std::endl;
	return malloc(sz);
}
*/
