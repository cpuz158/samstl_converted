// insert2.cpp
#include <iostream>
#include <algorithm>
#include <list>

// 함수 버전

int main(int argc, char** argv)
{
	int x[5] = { 10,20,30,40,50 };

	std::list<int> s = { 1, 2, 3, 4, 5 };
	

//	std::copy(x, x + 5, s.begin()); // 덮어쓴다.

//	std::copy(x, x + 5, s.end() );  // runtime-error. 할당되지 않은 메모리 덮어쓰기

	// 컨테이너의 끝에 추가하는 방법 1. for, push_back 사용
//	for (auto e : x)
//		s.push_back(e); // ok

	// 방법 2. 삽입반복자 사용
//	std::back_insert_iterator< std::list<int> > p1(s);
//	std::copy(x, x + 5, p1);

	// 방법 3. 삽입반복자 함수 버전 사용
	std::copy(x, x + 5, std::back_inserter(s) );


	for (auto& n : s)
		std::cout << n << std::endl; 
}
