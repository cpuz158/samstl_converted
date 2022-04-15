#include <iostream>
#include <vector>

template<typename R>
class reverse_view
{
	R& range;
public:
	reverse_view(R& r) : range(r) {}

	auto begin() { return range.rbegin(); }
	auto end()   { return range.rend(); }
};

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	for (auto e : reverse_view(v) )
	{
		std::cout << e << std::endl;
	}

}