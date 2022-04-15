#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include "show.h"

// 컨테이너를 보관하는 컨테이너

int main()
{
	std::vector<int> v1(10, 0);
	v1[0] = 10;

	// vector 를 가지고 matrix 처럼 사용하는 기술
	std::vector< std::vector<int> > v2(10, std::vector<int>(10));

	v2[0][0] = 10; 



	std::vector< std::list<int> > v3(10);
	
	v3[0].push_back(10);
	v3[0].push_back(20);
	v3[0].push_back(30);

	v3[1].push_back(1);
	v3[2].push_back(2);
	v3[3].push_back(3);

}