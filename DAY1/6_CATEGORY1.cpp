#include <forward_list> // 싱글리스트 입니다 - C++11 에서 추가.
#include <list>			// 더블리스트 입니다 - C++98 에서 추가

int main()
{
	std::forward_list<int> s1 = { 1,2,3 };

	std::list<int> s2 = { 1,2,3 };

	auto p1 = s1.begin();
	auto p2 = s2.begin();
	
	// 아래 4줄에서 에러를 찾아 보세요
	++p1;
	--p1; // error. 싱글리스트는 자료 구조 특성상 뒤로 밖에 이동할수 없습니다.
		  // 그래서 싱글리스트의 반복자는 -- 연산이 불가능합니다.
	++p2;
	--p2;

}