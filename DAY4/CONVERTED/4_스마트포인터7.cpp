#include <memory>
#include <string>
#include <iostream>

struct People
{
	std::string name;

	People(std::string n) : name(n) {}
	~People() { std::cout << name << " 파괴" << std::endl; }

	std::shared_ptr<People> bf; // best friend
};

int main()
{
	std::shared_ptr<People> sp1(new People("kim"));
	std::shared_ptr<People> sp2(new People("lee"));

	// shared_ptr 사용시
	// 상호 참조, 순환 참조(cycle reference) 발생시
	// 자원은 파괴되지 않습니다.
	sp1->bf = sp2;
	sp2->bf = sp1;
}


