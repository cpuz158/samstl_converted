
#include <vector>
#include <iostream>
#include <algorithm>
#include "show.h"

int main()
{
	// 배열 vs vector
	// 배열    : 크기를 변경할수 없습니다. 지역변수라면 stack 
	// vector : 크기 변경이 가능(동적배열), v 가 지역변수라도, 요소 자체는 힙에생성
	//						
	int x[5];				
	std::vector<int> v(5);	
	v.resize(10); // 크기 변경
	

	// 1. 생성
	std::vector<int> v1;		// 크기 0
	std::vector<int> v2(10);	// 크기 10, 모든 요소 0으로 초기화
	
	std::vector<int> v3(10, 3);	// 크기 10, 모든 요소 3으로 초기화
//	std::vector<int> v5 = {10, 3};
	std::vector<int> v5 { 10, 3 }; // 이 코드는 위와 동일합니다.

	std::vector<int> v4(v3);	// v3와 동일한 vector

	std::vector<int> v6 = { 1,2,3 }; // 3개를 1,2,3 으로 초기화.
	

	// 2. 삽입 - 3가지 방법, 앞, 뒤, 임의
	v.push_back(10);
//	v.push_front(10); // vector 는 전방삽입 안됨.
	
	auto p = v.begin();
	++p;

	v.insert(p, 20); //  v.insert(위치, 값) - 위치 앞에 넣기 

	// 3. 제거, : pop_front(), pop_back(), erase() - 임의 위치

	// 4. 접근
	int n1 = v[0];    // list 안됨.
	int n2 = v.at(0); // list 안됨. 위와 차이점은 뒤에서 등장.
	int n3 = v.front(); // 삽입/삭제가 아니므로 vector도 가능
	int n4 = v.back();

	// 5. 요소 변경
	std::vector<int> v8 = { 1,2,3 };
	std::vector<int> v9 = { 1,2,3,4,5 };
	v8.assign(v9.begin(), v9.end());
	v8.clear(); // 모든 요소 제거

	// 6. 기타 함수들
	bool b = v.empty();
	int  n = v.size();

}