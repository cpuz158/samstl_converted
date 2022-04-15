#include <memory>
#include <iostream>

int main()
{
	std::unique_ptr<int> up(new int);
	std::shared_ptr<int> sp(new int);


	// 다음중 에러는 ?
	std::shared_ptr<int> sp1 = up;	// error
	std::shared_ptr<int> sp2 = std::move(up); // ok

	std::unique_ptr<int> up1 = sp; // error
	std::unique_ptr<int> up2 = std::move(sp); // error
}

// 아래 Alloc 에서 반환값을 "int*" 대신 스마트 포인터로 하기로 했습니다.
// shared_ptr 로 할까요 ? unique_ptr로 할까요 ?
//int* Alloc()
//std::shared_ptr<int> Alloc() // 호출자는 반드시 shared_ptr로만 받아야 합니다.
std::unique_ptr<int> Alloc()   // 호출자는 shared_ptr 또는 unique_ptr을 선택가능
{
	//return new int;
	return std::unique_ptr<int>(new int);
}

int main()
{
	std::shared_ptr<int> sp1 = Alloc();
	std::unique_ptr<int> up1 = Alloc();
}


