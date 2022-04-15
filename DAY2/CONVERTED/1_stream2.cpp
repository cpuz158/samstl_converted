#include <iostream>
#include <iterator>
#include <list>
#include <algorithm> 
#include <fstream> // C++ 표준 파일 클래스

int main()
{
	std::ofstream fout("a.txt");
	fout << "hello"; // 파일에 쓰기


	std::ostream_iterator<int> p(fout, " ");
	*p = 100; // fout << 100 << " "

	std::list<int> s = { 1,2,3 };


	std::copy(s.begin(), s.end(), p);
}