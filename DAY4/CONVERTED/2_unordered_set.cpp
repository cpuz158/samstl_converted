#include <iostream>
#include <string>
#include <unordered_set>
#include "show.h"

// unordered_set 

int main()
{
	// C++ 표준이 제공하는 "hash 함수"들
	// "함수객체"로 되어 있습니다.
	std::hash<int> hi;
	std::hash<double> hd;
	std::hash<std::string> hs;

	std::cout << hi(30) << std::endl;
	std::cout << hi(40) << std::endl;
	std::cout << hd(3.4) << std::endl;

	std::cout << hs("hello") << std::endl;
}

