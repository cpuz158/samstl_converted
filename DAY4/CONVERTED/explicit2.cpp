#include <string>
#include <vector>

void f1(std::string s)      {}
void f2(std::vector<int> v) {}

int main()
{
	std::string      s1("A"); // ok
	std::string      s2 = "A";// ok.. explicit 아님.

	std::vector<int> v1(10);  // ok
	std::vector<int> v2 = 10; // error.

	// 아래 2줄을 잘 생각해 보세요.. 되는게 좋을까요 ? 안되는게 좋을까요 ?
	f1("A"); // ok.  std::string s = "A" 허용. 즉, explicit 생성자 아님.

	f2(10);  // error. std::vector<int> v = 10; 가 안됨. 
			//						즉, explicit 생성자

}