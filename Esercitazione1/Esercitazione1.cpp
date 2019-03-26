// Esercitazione1
//Class StringBuffer and methods


#include <iostream>
#include "StringBuffer.h"
int main()
{
	StringBuffer s1("Hello");
	StringBuffer s2("world!");
	s1.append(" ");
	s1.append(s2);
	printf(s1.c_str()); //Hello world!
	s1 = s2;
	s1.set("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.");
			s1.append("\n");
	printf("%zu", s1.size()); //124
	s2.clear();
	for (int i = 0; i < 10; i++)
		s2.insert(s1, s2.size());
	printf(s2.c_str()); //Lorem ipsum ... 10 volte
	printf("%zu", s2.size()); //1240

}
