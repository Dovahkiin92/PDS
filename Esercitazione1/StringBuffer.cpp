#include "StringBuffer.h"
#include <string>
using namespace std;

StringBuffer::StringBuffer(const char* str)
{
	this->max = strlen(str)+1;
	this->dim = max - 1;
	this->buffer =(char*) calloc(this->max, sizeof(char));
	memcpy(this->buffer, str,this->max);	
}
StringBuffer::StringBuffer(const StringBuffer& sb)
{
	this->max = sb.max;
	this->dim = this->max - 1;
	this->buffer= (char*)calloc(this->max, sizeof(char));
	memcpy(this->buffer, sb.buffer, this->max);
}
StringBuffer& StringBuffer::operator= (const StringBuffer& sb)
{
	if (this != &sb)
	{
		free(this->buffer);
		this->max = sb.max;
		this->dim = this->max - 1;
		this->buffer =(char*) calloc(max,sizeof(char));
		memcpy(this->buffer, sb.buffer,max);
	}
	return *this;
}
void  StringBuffer::insert(const char* str, size_t pos)
{
	int size = strlen(str);
	if (dim + size + 1 > max) //not enough space-> realloc
	{
		this->buffer = (char*)realloc(this->buffer, dim + size + 1);
		this->max = dim + size + 1;
	}
	if (pos > dim)
	{
		memset(this->buffer + size, ' ', pos - this->dim);
		memcpy(this->buffer + pos, str, size);
	}
	else
	{
		char* tmp = (char*)malloc((dim - pos)* sizeof(char));
		memcpy(tmp, this->buffer + pos, dim - pos); //split buffer
		memcpy(this->buffer + pos, str,size);
		memcpy(this->buffer + pos + size, tmp, dim - pos);
		free(tmp);
		tmp = NULL;
	}

	this->dim +=  size;	
	this->buffer[dim] = '\0';
}
void StringBuffer::insert(const StringBuffer& sb, size_t pos)
{
	this->insert(sb.buffer,pos);
}
void StringBuffer::append(const char* str)
{
	int size = strlen(str);
	if (max < dim + size + 1)
	{
		this->buffer = (char*)realloc(this->buffer, dim + size + 1);
		this->max = dim + size + 1;
	}
	memcpy(this->buffer + dim , str, size);
	this->dim += size;
	this->buffer[dim] = '\0';

}
void StringBuffer::append(const StringBuffer& sb)
{
	this->append(sb.buffer);
}
const char* StringBuffer::c_str() 
{
	char* str;
	str = (char*)calloc(dim + 1, sizeof(char));
	memcpy(str, this->buffer, dim);
	return str;
}

void StringBuffer::set(const char* str)
{
	this->clear();
	this->insert(str, 0);
}
void StringBuffer::set(const StringBuffer& sb)
{
	this->clear();
	this->insert(sb.buffer, 0);
}
StringBuffer::~StringBuffer()
{
	free(this->buffer);
	this->buffer = NULL;
}
