#include <util.h>
using namespace util;

// Replaces strcpy from standard library
char *util::strcpy(char *dst, const char *src)
{
    char *ret = dst;
    while ((*dst++ = *src++));
    return ret;
}

// Replaces strcmp from standard library
int util::strcmp(const char *a, const char *b)
{
	while((*a && *b) && (*a == *b)) {
		a++; b++;
	}
	return *a - *b;
}

// Replaces strlen from standard library
int util::strlen(const char *str)
{
	int len = 0;
	while (*str++) {
		len++;
	}
	return len;
}

String::String()
{
	Init();
}

String::String(String &str)
{
	Init();
	length = str.Length();
	Enalloc(length+1);
	util::strcpy(str.data, data);
}

String::String(const char *str)
{
	Init();
	if (!str) {
		return;
	}
	length = strlen(str);
	Enalloc(length+1);
	util::strcpy(data, str);
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
			util::strcpy(newbuffer, data);
		}
		if (data != buffer) {
			delete[] data;
		}
	}
	data = newbuffer;
}
