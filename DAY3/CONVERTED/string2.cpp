#include <iostream>
#include <string>
#include "debug_alloc.h"

using debug_string = std::basic_string<char,
						std::char_traits<char>, debug_alloc<char>>;

int main()
{
//	debug_string s1 = "abcd";

}