#pragma once
#ifndef __FEATURES_H__
#define __FEATURES_H__


#include<string>
#include<iostream>


void AutoKeyword_Test();
void InitializerList_Test();

void Lambda_Test();

/// <summary>
/// String view 就是一个裸指针加上一个长度
/// 
/// </summary>
void StringView_Test();


void StructuredBind_Test();


class MyString : public std::string {
public:
	MyString(const char* data);
	virtual ~MyString();
};
void Unique_Point_Test();
void Span_Test();

#endif