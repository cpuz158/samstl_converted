#include <iostream>
#include <memory>

class Car
{
public:
	void Go() {}
	~Car() { std::cout << "~Car" << std::endl; }
};
int main()
{
	std::weak_ptr<Car>   wp;
	{
		std::shared_ptr<Car> p(new Car);

		wp = p;

	} // <== p가 파괴되므로 객체 파괴

//	if (!wp.expired()) // 결국 아래 if(sp)로 조사하게 되므로 없어도 됩니다.
	{

		std::shared_ptr<Car> sp = wp.lock();

		if (sp)
		{
			sp->Go();
		}
		else
		{
			std::cout << "sp 유효 하지 않음" << std::endl;
		}
	}
	

}

