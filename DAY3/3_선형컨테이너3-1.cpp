#include <vector>
#include <iostream>
#include <algorithm>
#include "show.h"

int main()
{
	// 사용자가 -1을 입력할때 까지 계속 입력 받아서 보관하고 싶다.
//	std::vector<int> v(100); // 이렇게 해 놓면 
							 // 항상 size = 100 이므로 
							 // 몇개 입력 되었는지 파악이 안됩니다.

	std::vector<int> v;
	v.reserve(100); // 100 개를 미리 확보..

	int num = 0;

	while (1)
	{
		std::cin >> num;
		
		if (num == -1) break;

		v.push_back(num);
	}
	std::cout << v.size() << std::endl;

}




