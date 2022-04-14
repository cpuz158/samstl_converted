#include <memory>
#include <string>
#include <iostream>

struct People
{
	std::string name;

	People(std::string n) : name(n) {}
	~People() { std::cout << name << " 파괴" << std::endl; }

//	People* bf;

	std::weak_ptr<People> bf; // 참조계수가 증가 하지 않는 스마트 포인터
							  // 객체의 파괴 여부도 조사 가능하다.
};

int main()
{
	std::shared_ptr<People> sp1(new People("kim"));
	{
		std::shared_ptr<People> sp2(new People("lee"));

		sp1->bf = sp2;
		sp2->bf = sp1;
	}

	if (sp1->bf.expired() )
	{
		std::cout << "객체가 파괴 되었음." << std::endl;
	}
	else
	{
		std::cout << "객체가 파괴 되지 않음" << std::endl;
	}
}


