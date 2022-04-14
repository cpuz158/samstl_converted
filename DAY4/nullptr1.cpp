// nullptr1
#include <iostream>

void fn(int   n) { std::cout << "int"   << std::endl; } // 1
void fn(void* n) { std::cout << "void*" << std::endl; } // 2

int main()
{
	fn(0); // ?
}
