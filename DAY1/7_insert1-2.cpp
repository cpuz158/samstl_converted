#include <iostream>
#include <list>
#include <vector>

int main()
{
	std::list<int>   s = { 1,2,3 };
	std::vector<int> v = { 1,2,3 };

	// 삽입반복자란 ?
	// => 컨테이너에 요소를 추가 할때 사용하는 반복자
	
	// 사용하는 방법 1. 삽입반복자 클래스 이름 직접 사용.
	std::back_insert_iterator< ? > p1(s);
	std::back_insert_iterator< ? > p2(v);
}