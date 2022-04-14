// equality, Equivalency
#include "show.h"
#include <set>
#include "debug_alloc.h"

struct Point
{
	int x, y;
	Point(int a = 0, int b = 0) : x(a), y(b) {}

	bool operator<(const Point& pt) const  {	return x < pt.x;	}
};

int main()
{
	std::set<Point> s;  

	s.emplace(3, 2);	
	s.emplace(2, 1);
	s.emplace(1, 5);

}


















