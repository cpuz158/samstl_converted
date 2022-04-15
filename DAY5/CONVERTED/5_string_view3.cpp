#include <iostream>

class string_view
{
	const char* s;
	std::size_t sz;
public:
	string_view(const char* p) : s(p)
	{
		sz = strlen(s);
	}
	string_view(const std::string& str)
	{
		s = str.c_str();
		sz = strlen(s);
	}
};
int main()
{
	string_view sv1("hello");

	std::string s = "hello";
	string_view sv2 = s;
}