#include <vector>
#include <algorithm>
#include "show.h"

int main()
{
	// 배열 과 vector
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };			// 모든 요소가 stack
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };	// 모든 요소가 heap

	x[0] = 10;
	v[0] = 10;
}
