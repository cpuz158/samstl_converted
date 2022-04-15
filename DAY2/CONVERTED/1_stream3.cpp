#include <iostream>
#include <iterator>
#include <list>
#include <algorithm> 
#include <fstream> // C++ 표준 파일 클래스

int main()
{
//	std::ostream_iterator<int> p(std::cout, " ");

	std::istream_iterator<int> p(std::cin); // 입력 스트림 반복자
//	*p = 10; // error. p는 출력은 안됩니다

	int n = *p; // std::cin >> n 과 같은 의미..

	std::cout << n << std::endl;


}