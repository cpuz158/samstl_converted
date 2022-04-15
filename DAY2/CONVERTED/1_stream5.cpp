#include <iostream>
#include <iterator>
#include <list>
#include <algorithm> 
#include <fstream> 

int main()
{
	std::ifstream fin("1_stream5.cpp"); 

	// istream_iterator 는 white space(space, tab, enter 등)을 무시
//	std::istream_iterator<char> p1(fin); 
//	std::istream_iterator<char> p2; // 생성자 인자를 전달하지 않으면 EOF를
									// 나타냅니다.

	// 아래 반복자는 공백도 입력 가능합니다
	std::istreambuf_iterator<char> p1(fin); 
	std::istreambuf_iterator<char> p2; 


	std::ostream_iterator<char> p3(std::cout, "");

	std::copy(p1, p2, p3);

}