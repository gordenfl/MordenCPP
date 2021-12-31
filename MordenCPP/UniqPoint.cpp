#include"UniqPoint.h"

#include<memory>
#include<string>
#include<iostream>

void printInfo(std::unique_ptr<MyString> name, std::unique_ptr<MyString> address) {
	std::cout << *name << std::endl;
	std::cout << *address << std::endl;
}

void Unique_Point_Test() {
	auto name = std::unique_ptr<MyString>(new MyString("Gordon"));
	auto address = std::unique_ptr<MyString>(new MyString("10 silver lace ct"));
	printInfo(std::move(name), std::move(address));

	std::cout << "printInfo has been done!" << std::endl;
}