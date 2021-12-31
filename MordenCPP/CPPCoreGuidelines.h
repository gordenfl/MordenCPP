#pragma once
#ifndef __CPP_CORE_GUIDELINES_H__
#define __CPP_CORE_GUIDELINES_H__

typedef int Month;
class Date {
public:
	Date() {}
	Month month() const;
private:
	Month _month;
};

void Cpp_Core_Test();
#endif