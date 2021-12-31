#pragma once
#ifndef __UNIQUE_POINT_H__
#define __UNIQUE_POINT_H__
#include<string>
#include<iostream>
class MyString: public std::string {
public:
	MyString(const char* data) :std::string(data) {}
	virtual ~MyString() {
		std::cout<< *this << "has been distroyed" << std::endl;
	}
};
void Unique_Point_Test();

#endif