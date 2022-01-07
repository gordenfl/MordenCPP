#include"CPPCoreGuidelines.h"

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<span>
#include<chrono>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::span;

Month Date::month() const {
	return _month;
}

//for_each �� algorithm ͷ�ļ�� ������Ӵ�һ��lambda
void ExampleForEach() {
	std::vector<int> data{ 1,2,3,4,5,6,7,8,9 };
	for_each(begin(data), end(data), [](int v) {
		std::cout << v << " ";
		});
	std::cout << std::endl;
}

void Find(vector<string>& data, string & target) {
	auto p = find(begin(data), end(data), target); //return is an iterator
	if (p!=data.end()) {
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
	auto data = std::vector<std::string>{ "AAA", "BBB", "CCC", "DDD", "target"};
	auto target = string("BBB");
	Find(data, target);


	// not_null,  code from:https://github.com/microsoft/GSL/blob/main/include/gsl/pointers
	//�Կ�ָ�뱣�����Լ������not_null��ģ���࣬���������Ѻ�


	//Do not pass an array as a single pointer
	//���������span ģ�彫�����װһ�Σ�������Ա�֤����Խ����ʣ�����ᰲȫ�����һ����һ���ʾ��С�Ĳ���


	//���⸴�ӵĳ�ʼ����������Ҫ��ĳ�������ܳ�ʼ�����࣬�ĳɼ򵥳�ʼ������ĳ������ڶ����ʼ���Ժ����ĳ�����ʼ����ȥ
	// file1.cpp
	// extern const X x;
	//const Y y = fun(x);
	// file2.cpp
	// extern const Y y;
	// const X x = func(y);
	//����������ѭ���༭����
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


	//������ٺ������ĸ����ø��ַ�����
	//��struct class ��װ�������ĳ�Ա������õȵ�

	//�������ڵĲ���ɲ�ͬ����Ĳ���ʹ��
	//����:  void copy_n(T* p, T* q, int n); //copy from p to q, copy length is n. this is bad
	// void copy_n(const T* p, T* q, int n); //const of p, then p will not be used as target point
	// void copy_n(span<const T> p, span<T> q);  // this is good


	//�����ྡ�ֻ����ӿڣ���Ҫ����ݣ���Ա����ȵ�


	//�����Ҫ������루��һ��ƽ̨�ϱ���������һ��ƽ̨�����еĳ��򣩣������C-Style �Ӽ�


	//����������ԭ����Ҫ�õ�һЩ�Ƚϳ�ª�Ĵ���Ͳ���ȫ�Ĵ��룬�뽫���뱣�����ڲ�����Ҫ��Ⱦ�ӿ�


}