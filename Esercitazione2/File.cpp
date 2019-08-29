#include "File.h"
#include <string>
#include<iostream>
#define CODE_FILE 2


File::File()
{
	size = 0;
}

File::~File()
{
}

uintmax_t File::getSize() const 
{
	return size;
}
int File::mType() const 
{
	return CODE_FILE;
}
void File::ls(int indent) const
{
	cout << string(" ", indent) <<"./"<< name << " - " << size << endl;
}
