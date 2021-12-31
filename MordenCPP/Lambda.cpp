#include"Lambda.h"

#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
#include<functional>

bool compare(const std::pair<int, int>& a, const std::pair<int, int>& b) {
	return a.second < b.second;
}

void beforeLambda() {
	std::vector<std::pair<int, int>> data{ {0,4}, {1,9}, {2,3},{3,1},{4,0},{5,7} };
	std::sort(begin(data), end(data), compare);

	for (auto d : data) {
		std::cout << d.first << ":" << d.second << std::endl;
	}
	return;
}

void afterLambda() {
	std::vector<std::pair<int, int>> data{ {0,4}, {1,9}, {2,3},{3,1},{4,0},{5,7} };
	std::sort(begin(data), end(data),
		[](const auto& a, const auto& b) {return a.second < b.second; }
	);

	for (auto d : data) {
		std::cout << d.first << ":" << d.second << std::endl;
	}
}

void lambda_argument_byvalue() {
	int a = 1;
	auto foo = [&a] {a += 1; }; // here a is pass into lambda as a reference 
	foo();
	std::cout << "after foo() call, a = " << a << std::endl;


	int b = 2, c = 3, d = 4;
	auto foo1 = [=, &a] {a = a + b + c + d; return a; }; // a as a reference other value is value, other vals is read-only
	int v = foo1();
	std::cout << "after foo1 the return value is :" << v << std::endl;
	std::cout << "after foo1 the a value is :" << a << std::endl;
}

void lambda_argument_byreference() {
	int a = 1;
	int b = 2, c = 3, d = 4;
	auto foo = [&] {a++; b++; c++; d++; }; // define a function in another function
	std::cout << "before foo: a=" << a << ", b=" << b << ", c=" << c << ", d=" << d << std::endl;
	foo();
	std::cout << "after foo: a=" << a << ", b=" << b << ", c=" << c << ", d=" << d << std::endl;

}
void lambda_define_func_in_func() {
	int a = 4;
	int b = 56;

	std::function<int(int&, int&)> func = [&](int& a, int& b) {a = a + b; b = a; return a; };


	std::cout << "before function call a:" << a << "  , b=" << b << std::endl;
	std::cout << "func result is:" << func(a, b) << "  a:"<< a<< "   b:"<< b<< std::endl;
	return;
}
void Lambda_Test() {
	beforeLambda();
	afterLambda();

	lambda_argument_byvalue();
	lambda_argument_byreference();
	lambda_define_func_in_func();
}
