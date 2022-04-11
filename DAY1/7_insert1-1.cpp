// 7_insert1-1
#include <iostream>

template<typename T>
T square(T a)
{
	return a * a;
}

int main()
{
	// 다음중 쉬워 보이는 것은 ?
	square<int>(3); // 1
	square(3);		// 2
}