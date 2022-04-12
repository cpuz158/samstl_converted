// QA
#include <iostream>
#include <functional>

template<typename T>
void Sort(int*, int sz, T cmp)
{
	cmp(0, 1);
}

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	int k = 0;

	Sort(x, x + 10, k); // ????

}