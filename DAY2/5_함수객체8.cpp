#include <vector>
#include <algorithm>
#include "show.h"

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };

	// STL 에서 sort()를 사용하는 방법
	// 1. 비교 정책을 전달 안하는 경우
	std::sort(v.begin(), v.end());


}