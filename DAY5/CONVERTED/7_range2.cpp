// 7_range1
#include <iostream>
#include <vector>

// 아래 클래스가 하는 일을 잘 생각해 보세요
template<typename R>
class take_view
{
	R& range;
	std::size_t count;
public:
	take_view(R& r, std::size_t sz) : range(r), count(sz) {}
	
	auto begin() { return range.begin(); }
	auto end()   { return range.begin() + count; }
};

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	// tv 는 v와 3을 보관하고 있습니다.
//	take_view< std::vector<int> > tv(v, 3);
	take_view tv(v, 3);

//	for (auto e : v)
//	for (auto e : tv)
	for (auto e : take_view(v, 3) )
	{
		std::cout << e << std::endl;
	}

}