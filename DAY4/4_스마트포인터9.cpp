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
		
		// 파괴 되지 않은 경우.. 객체에 접근하려면
		// 1. weak 로는 접근할수 없습니다.
		//	=> weak 는 객체 수명에 관여하지 않으므로(참조계수 증가 안함)
		//  => 객체의 멤버 함수 호출중에 객체가 파괴 될수도 있습니다.
		//     그래서 weak 로 객체 접근 안됩니다.
		//auto ret = sp1->bf->name; // error. weak 는 -> 연산자 제공안함

		// weak 를 가지고 shared 를 만들어서 접근해야 합니다.
		std::shared_ptr<People> sp = sp1->bf.lock();

		if (sp) // 다시 유효성 확인후 사용
		{
			std::cout << sp->name << std::endl;
		}
	}
}


