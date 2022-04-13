#include <vector>
#include <iostream>
#include <algorithm>
#include "show.h"

int main()
{
	// 사용자가 -1을 입력할때 까지 계속 입력 받아서 보관하고 싶다.
	std::vector<int> v;

	int num = 0;

	while (1)
	{
		std::cin >> num;
		
		if (num == -1) break;

		v.push_back(num);
	}

}




