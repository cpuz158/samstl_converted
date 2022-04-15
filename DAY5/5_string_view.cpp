// 5_string_view
#include <iostream>
#include <string>
#include <string_view> // C++17 에서 추가

int main()
{
	std::string s1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 


	// "s2" 와 "sv" 의 메모리 그림을 잘 알아 두세요
	std::string s2 = s1; // s1 의 문자열을 깊은복사해서
						 // s2 이 별도의 메모리로 소유

	std::string_view sv = s1;	
						// sv 는 문자열을 소유하지 않고
						// s1 문자열을 공유
						// 단, sv로는 읽기만 가능
	auto ret = sv[0]; // ok

	sv[0] = 'A'; // error
}