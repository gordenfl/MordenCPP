#include"AutoKeyword.h"

#include<iostream>
#include<string>
#include<vector>

std::string vector2str(std::vector<int> input) {
	std::string ret;
	for (auto v : input) {
		ret+=std::to_string(v)+ " ";
	}
	return ret;
}
/// <summary>
/// Test type
/// </summary>
void TestType() {
	auto a = 1;
	auto b = 3.1; // here is double, not float;
	auto c = 0.2f; //here is float
	auto d = std::string("Hello world");
	auto e = "Hello Gordon";
	auto f = { 1,2,3,4,5 };
	auto g = std::vector<int>{ 1,2,3,4,5 };
	auto h = std::vector<int>(f);

	std::cout << a << ":" << typeid(a).name() << std::endl;
	std::cout << b << ":" << typeid(b).name() << std::endl; //double
	std::cout << c << ":" << typeid(c).name() << std::endl;
	std::cout << d << ":" << typeid(d).name() << std::endl;
	std::cout << e << ":" << typeid(e).name() << std::endl;
	
	std::cout << vector2str(f) << ":" << typeid(f).name() << std::endl;
	std::cout << vector2str(g) << ":" << typeid(g).name() << std::endl;
	std::cout << vector2str(h) << ":" << typeid(h).name() << std::endl;

	//good!!
	auto foo = std::make_unique<int>(10);


	std::vector<int> data{ 1,2,3,4,5,6,7,8,9,10 };
	for (auto i : data) {
		std::cout << i;
	}
	std::cout << std::endl;
}

void AutoKeyword_Test() {
	TestType();

	
}
