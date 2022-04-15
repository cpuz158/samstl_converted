#include <iostream>
#include <iterator>
#include <list>
#include <algorithm> 
#include <fstream> 

int main()
{
	std::ifstream fin("1_stream4.cpp"); // 현재 소스 이름 넣으세요

	std::istream_iterator<char> p(fin); // 입력 스트림 반복자
	std::cout << *p << std::endl;
	++p;
	std::cout << *p << std::endl;
}