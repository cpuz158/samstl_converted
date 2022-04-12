#include <iostream>
#include <vector>
#include <functional>
using namespace std::placeholders;

class Button
{
public:
	void click()
	{
		// 버튼이 눌린 사실을 위부에 알려야 합니다.
	}
};

int main()
{
	Button b1, b2; // 2개의 버튼 만들기
	b1.click();
}