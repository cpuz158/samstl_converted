// iterator1.cpp
#include <iostream>
#include <list>
//using namespace std;

int main()
{
	std::list<int> s1 = { 1,2,3 };
	std::list      s2 = { 1,2,3 }; // C++17 부터는 요소 타입 생략가능합니다.



	int x[5] = { 1,2,3,4,5 };

	int* p = x;
	*p; ++p;


	std::list<int> s = { 1,2,3,4,5 };
	std::list<int>::iterator p2 = s.begin();
	*p2; 
	++p2;
}










