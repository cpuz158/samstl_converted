#include <iostream>
#include <unordered_set>
#include "show.h"

// ����� ���� Ÿ���� unordered(hash)�� �ֱ�

struct People
{
	std::string name;
	int  age;
	People(std::string n, int a) : name(n), age(a) {}
};

// People �� ���� hash �Լ� ��ü�� �ʿ� �մϴ�.
struct PeopleHash
{
	std::size_t operator()(const People& p) const 
	{
		std::hash<int> hi;
		std::hash<std::string> hs;
		return hs(p.name) + hi(p.age);
	}
};

// People ��ü 2���� ���Ҽ� �ִ� �Լ� ��ü
struct PeopleEqual
{
	inline bool operator()(const People& p1, const People& p2) const
	{
		return p1.name == p2.name && p1.age == p1.age;
	}
};

int main()
{
	std::unordered_set<People, PeopleHash, PeopleEqual> s;

	s.emplace("kim", 20); // s.insert( People("kim",20))
	s.emplace("lee", 25);
	s.emplace("park", 30);


	People peo("lee", 25);
	auto p = s.find( peo );

	std::cout << (*p).name << std::endl;
}
