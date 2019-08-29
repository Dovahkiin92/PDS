#pragma once
#include "Base.h"
class File :
	public Base
{
	string name;
	 uintmax_t size;
public:
	File();
	File(string name, uintmax_t size) :name(name), size(size) {};
	uintmax_t getSize() const;
	void ls(int indent = 0) const override;
	int mType() const override;

	~File();
};

