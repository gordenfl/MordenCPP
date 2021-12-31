#pragma once
#ifndef __LAMBDA_H__
#define __LAMBDA_H__
#include<vector>

void Lambda_Test();


/*
typedef void (*func)(std::vector<int>&); 

typedef struct Boo {
	int a;
	char b;

	void onUpdate(func c) { 
		std::vector<int> t();
		c(t); }
} Boo;


class Foo {
public:
	Foo();

	void Init() {
		_boo.onUpdate(
			[this](const auto data) {
				this->doSomething(data);
			}
		);
	}

	void doSomething(std::vector<int>& data) { return; }
private:
	Boo _boo;
};
*/
#endif