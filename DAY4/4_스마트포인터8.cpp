#include <memory>
#include <string>
#include <iostream>

struct People
{
	std::string name;

	People(std::string n) : name(n) {}
	~People() { std::cout << name << " 파괴" << std::endl; }

//	std::shared_ptr<People> bf; // best friend

	// shared_ptr 대신 raw pointer 를 사용하면
	// 자원 누수 문제는 해결되었습니다.
	// 그런데, 한개의 문제가 있습니다.(8-1번 소스참고)
	People* bf; // raw pointer 이므로 참조계수 증가 안함
};

int main()
{
	std::shared_ptr<People> sp1(new People("kim"));
	std::shared_ptr<People> sp2(new People("lee"));


	sp1->bf = sp2.get();
	sp2->bf = sp1.get();
}


