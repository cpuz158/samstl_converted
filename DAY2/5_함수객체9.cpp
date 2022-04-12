#include <vector>
#include <algorithm>
#include <functional>	
#include "show.h"

// 람다표현식을 보고 컴파일러가 만드는 클래스..
// 클래스이름 자체는 컴파일러가 임으로 결정합니다.
class ClosureType
{
public:
	inline auto operator()(int a, int b) const
	{
		return a < b;
	}
};
int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };

//	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; } );

	std::sort(v.begin(), v.end(), ClosureType() ); // 위 코드는 결국 이렇게
													// 변경됩니다.
	std::sort(v.begin(), v.end(), std::less<int>());// 결국 이것과
												    // 완벽히 동일한 효과
}