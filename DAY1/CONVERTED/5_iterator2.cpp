#include <iostream>
#include <list>
#include <filesystem> // C++17 

int main()
{
	// 반복자는 컨테이너로 부터 꺼내는 것 외에도 많은 종류가 있습니다.
	std::filesystem::directory_iterator p("C:\\windows");

	std::cout << *p << std::endl;
	++p;
	std::cout << *p << std::endl;
}










