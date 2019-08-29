#include "Directory.h"
#include <string>
#include<iostream>
#define CODE_DIR 0

shared_ptr<Directory> Directory::root = NULL;

Directory::Directory()
{
	name = "/";
	folders = map<string,shared_ptr<Directory>>();
	files = map<string, shared_ptr<File>>();
}

Directory::Directory(string name)
{
	this->name = name;
	folders = map<string, shared_ptr<Directory>>();
	files = map<string, shared_ptr<File>>();
}

Directory::~Directory()
{
}

shared_ptr<Directory> Directory::getRoot()
{
	if (root == nullptr)
	{
		root = shared_ptr<Directory>(new Directory());
		root->self = root;
	}
	return root;
}

shared_ptr<Directory> Directory::addDirectory(string name)
{
	if (folders.find(name) != folders.end())
		throw new std::exception();
	
	auto ptr = shared_ptr<Directory>(new Directory(name));
	ptr->self = ptr;
	ptr->parent = shared_ptr<Directory>(this->self);
	this->folders.insert(std::pair<string, shared_ptr<Directory>>(name,ptr));
	return ptr ;
}
shared_ptr<File> Directory::addFile(string name, uintmax_t size)
{
	if (files.find(name) != files.end())
		throw new std::exception();

	auto ptr = shared_ptr<File>(new File(name,size));
	this->files.insert(std::pair<string, shared_ptr<File>>(name, ptr));
	return ptr;
}
shared_ptr<Base> Directory::get(string name) 
{
	shared_ptr<Base> ptr = nullptr;
	if (name == ".")
		if(!self.expired())
		ptr = self.lock();
	if(name =="..")
		if(!parent.expired())
		ptr = parent.lock() ;
	auto i = folders.find(name);
	if (i != folders.end())
		ptr =i->second;
	else
	{
		auto j = files.find(name);
		if (j != files.end())
			ptr = j->second;
	}
	return ptr;
}
shared_ptr<Directory> Directory::getDir(string name)
{
	auto ptr = get(name);
	return dynamic_pointer_cast<Directory>(ptr);
}

shared_ptr<File> Directory::getFile(string name)
{
	auto ptr = get(name);
	return dynamic_pointer_cast<File>(ptr);
}

void Directory::remove(string name)
{
	if (name == "." || name == "..")
		throw new std::exception();
	
	if (folders.erase(name) != 0)
		files.erase(name);

}
void Directory::ls(int indent) const 
{
	if (folders.size() == 0)
	{
		for (auto f : files)
			f.second->ls(indent+1);
		return;
	}
	for (auto d : folders) {
		std::cout << std::string(" ", indent) <<"--"<< d.first << endl;
		d.second->ls(indent+1);
	}
	for (auto f : files)
		f.second->ls(indent+1);
}

 int Directory::mType() const 
{
	return CODE_DIR;
}

