#pragma once
#include "Base.h"
#include "File.h"
#include <map>
#include <string>
using namespace std;

class Directory :
	public Base
{	
	static shared_ptr<Directory> root;
	weak_ptr<Directory> self;
	weak_ptr<Directory> parent;
	map<string,shared_ptr<Directory>> folders;
	map<string,shared_ptr<File>> files;
	
protected:
	Directory(); //protected, singleton
	Directory(string name);
public:
	~Directory();
	static shared_ptr<Directory> getRoot();
	shared_ptr<Directory> addDirectory(string name);
	shared_ptr<File> addFile(string nome, uintmax_t size);
	shared_ptr<Base> get(string name);
	shared_ptr<Directory> getDir(string name);
	shared_ptr<File> getFile(string name);
	void remove(string nome);
	void ls(int indent = 0) const override;
	int mType() const override;
};

