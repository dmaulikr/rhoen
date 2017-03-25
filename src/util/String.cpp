#include <string.h> // strcpy, strlen
#include <util.h>
using namespace util;

String::String()
{
	Init();
}

String::String(String &str)
{
	Init();
	length = str.Length();
	Enalloc(length+1);
	strcpy(str.data, data);
}

String::String(const char *str)
{
	Init();
	if (!str) {
		return;
	}
	length = strlen(str);
	Enalloc(length+1);
	strcpy(data, str);
}

String::~String()
{
}

int String::Length() const
{
	return length;
}

void String::Init()
{
	length = 0;
	allocated = STR_BUF_BASE;
	data = buffer;
	data[0] = '\0';
}

void String::Enalloc(int size, bool copy)
{
	if (size > allocated) {
		Realloc(size, copy);
	}
}

void String::Realloc(int size, bool copy)
{
	int mod;
	int newsize;
	char *newbuffer;

	if (size <= 0) {
		return;
	}

	mod = size % STR_BUF_GRAN;
	if (!mod) {
		newsize = size;
	} else {
		newsize = size + STR_BUF_GRAN - mod;
	}
	allocated = newsize;
	newbuffer = new char[allocated];
	if (data) {
		if (copy) {
			strcpy(newbuffer, data);
		}
		if (data != buffer) {
			delete[] data;
		}
	}
	data = newbuffer;
}
