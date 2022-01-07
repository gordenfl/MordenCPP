#include"CPPCoreGuidelines.h"

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<span>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::span;

Month Date::month() const {
	return _month;
}

//for_each 在 algorithm 头文件里， 这个例子带一个lambda
void ExampleForEach() {
	std::vector<int> data{ 1,2,3,4,5,6,7,8,9 };
	for_each(begin(data), end(data), [](int v) {
		std::cout << v << " ";
		});
	std::cout << std::endl;
}

void Find(vector<string>& data, string& target) {
	auto p = find(begin(data), end(data), target); //return is an iterator
	if (p != data.end()) {
		std::cout << "Find the target:" << *p << std::endl;
	}
	else {
		std::cout << "Don't find target:" << target << std::endl;
	}
}


void Cpp_Core_Test() {
	cout << "||For: for_each learning" << endl;
	ExampleForEach();

	cout << "||For: find learning" << endl;
	auto data = vector<string>{ "AAA", "BBB", "CCC", "DDD", "target" };
	auto target = string("BBB");
	Find(data, target);


	// not_null,  code from:https://github.com/microsoft/GSL/blob/main/include/gsl/pointers
	//对空指针保护，自己定义个not_null的模板类，对这样更加友好


	//Do not pass an array as a single pointer
	//这里最好用span 模板将数组包装一次，这样可以保证不会越界访问，这样会安全，并且会减少一个表示大小的参数


	//避免复杂的初始化，比如需要传某个参数才能初始化的类，改成简单初始化，将某个参数在对象初始化以后调用某个函数初始化进去
	// file1.cpp
	// extern const X x;
	//const Y y = fun(x);
	// file2.cpp
	// extern const Y y;
	// const X x = func(y);
	//这里会出现死循环编辑错误
	/*
	file1.cpp
	extern const X;
	const Y y = createY();
	y.setX(X::getX());

	file2.cpp
	extern const Y;
	const X x = createX();
	x.setY(Y::getY());
	*/


	//尽量减少函数参数的个数，用各种方法：
	//用struct class 包装，类对象的成员变量设置等等

	//避免相邻的参数被当成不同含义的参数使用
	//例子:  void copy_n(T* p, T* q, int n); //copy from p to q, copy length is n. this is bad
	// void copy_n(const T* p, T* q, int n); //const of p, then p will not be used as target point
	// void copy_n(span<const T> p, span<T> q);  // this is good


	//抽象类尽量只定义接口，不要包含数据，成员变量等等


	//如果需要交叉编译（在一个平台上编译在另外一个平台上运行的程序），最好用C-Style 子集


	//如果出于特殊原因需要用到一些比较丑陋的代码和不安全的代码，请将代码保留在内部，不要感染接口


}