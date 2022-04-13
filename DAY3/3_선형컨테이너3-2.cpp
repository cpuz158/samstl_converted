#include <vector>
#include <iostream>
#include <algorithm>
#include "show.h"

int main()
{
	std::vector<int> v = { 1,2,3,1,2,3,1,2,3,1 };

	// 3을 모두 제거하고 싶다.
	auto p = std::remove(v.begin(), v.end(), 3);

	std::cout << v.size() << ", " << v.capacity() << " : "; show(v);

	v.erase(p, v.end());

	std::cout << v.size() << ", " << v.capacity() << " : "; show(v);

}




