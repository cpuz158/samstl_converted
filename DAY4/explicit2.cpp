#include <string>
#include <vector>

void f1(std::string s)      {}
void f2(std::vector<int> v) {}

int main()
{
	std::string      s1("A"); // ok
	std::vector<int> v1(10);  // ok

	// 아래 2줄을 잘 생각해 보세요.. 되는게 좋을까요 ? 안되는게 좋을까요 ?
	f1("A"); // ?
	f2(10);  // ?

}