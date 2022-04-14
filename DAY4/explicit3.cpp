#include <memory>

void push_back( std::shared_ptr<int> sp )
{
}

int main()
{
	std::shared_ptr<int> sp1 = new int;
	std::shared_ptr<int> sp2(new int);
}