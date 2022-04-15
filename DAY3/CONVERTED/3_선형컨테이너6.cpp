#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <string>
#include <fstream>
#include "show.h"

class FindChar
{
	std::string data;
public:
	FindChar(const std::string& s) : data(s) {}

	inline bool operator()(char c) const 
	{
		return std::find(data.begin(), data.end(), c) != data.end();
	}
};


int main()
{
	std::vector<std::string> v;

	std::ifstream f("3_선형컨테이너6.cpp"); // 현재 파일이름

	std::string s;

	// f >> s        : 파일에서 한단어 읽기  
	// getline(f, s) : 파일에서 한 문장     getline(std::cin, s)도 됩니다.
	
	while (std::getline(f, s))
		v.push_back(s);
	//----------------------------

//	std::reverse(v.begin(), v.end()); // 파일의 내용을 상하 뒤집기.
//	std::reverse(v[0].begin(), v[0].end()); // 1번째 줄만 좌우 뒤집기

	for (auto& e : v)
	{
//		std::reverse(e.begin(), e.end());
//		std::replace(e.begin(), e.end(), 'i', ' ');

		// 모든 모음을 공백 처리해 달라.
//		std::replace_if(e.begin(), e.end(), 
//						[](char c) { return c == 'a' || c == 'e'; },
//						' ');

//		FindChar fc("aeiouAEIOU");
//		bool b = fc('a'); // true
		FindChar fc("0123456789");

		std::replace_if(e.begin(), e.end(), fc,	' ');


	}

	//-------------------------------------
	for (auto& n : v)
		std::cout << n << std::endl;
}


