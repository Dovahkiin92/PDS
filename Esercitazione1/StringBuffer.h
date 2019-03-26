#pragma once
#include <stdlib.h>
#define INIT_DIMENSION 1024
class StringBuffer
{
	unsigned int max;
	unsigned int dim;
	char* buffer;

public:
	StringBuffer() :max(INIT_DIMENSION), dim(0) { buffer = (char*)calloc(INIT_DIMENSION, sizeof *buffer); };
	StringBuffer(const char * str);
	StringBuffer(const StringBuffer& sb);
	StringBuffer& operator= (const StringBuffer& sb);
	size_t size() { return dim; };
	size_t capacity() { return max; };
	void clear() { dim = 0; };
	void insert(const char* str, size_t pos);
	void insert(const StringBuffer& sb, size_t pos);
	void append(const char* str);
	void append(const StringBuffer& sb);
	const char* c_str();
	void set(const char* str);
	void set(const StringBuffer& sb);
	~StringBuffer();
};

