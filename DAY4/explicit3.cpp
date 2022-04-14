#include <memory>

void push_back( std::shared_ptr<int> sp )
{
}

int main()
{
	// 1. shared_ptr 생성자는 explicit 입니다.
	std::shared_ptr<int> sp1 = new int; // error
	std::shared_ptr<int> sp2(new int);  // ok

	// 2. 
	push_back(new int); // std::shared_ptr<int> sp = new int; 이므로 error
	push_back(std::shared_ptr<int>(new int));
			// std::shared_ptr<int> sp = std::shared_ptr<int>(new int);
			//	ok.. 위 코드는 복사 생성자 사용. explicit 아님.

	push_back( std::make_shared<int>(0) );
		// std::shared_ptr<int> sp = std::make_shared<int>(0)
}