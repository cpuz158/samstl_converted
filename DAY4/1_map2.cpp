#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <map>
#include <algorithm>

int main()
{
	std::map< std::string, std::list<int> > indexMap;

	std::ifstream f("readme.txt");

	int no = 0; // line number 관리

	std::string s;

	while ( std::getline(f, s) )   // 파일에서 부터 한줄 읽기
	{
		++no;
		std::istringstream iss(s);  // 한줄의 문장을
		std::string word;
		while (iss >> word)			// 단어별로 분리
		{
			// map["키"] : 키가 있으면 value 반환, 
			//			   없으면 "키" 생성
			indexMap[word].push_back(no);
		}
	}
}


