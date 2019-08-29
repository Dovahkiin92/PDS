#pragma once
using namespace std;
#include <string>

class Base
{
protected:
	string name;
	Base();
public:
	string getName() const;
	virtual int mType() const = 0;
	virtual void ls(int indent = 0) const = 0;
	~Base();
};

