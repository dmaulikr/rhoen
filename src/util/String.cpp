#include <util.h>
using namespace util;

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

// Replaces strcpy from standard library
char *util::strcpy(char *dst, const char *src)
{
    char *ret = dst;
    while ((*dst++ = *src++));
    return ret;
}

// Replaces memcpy from standard library
void *util::memcpy(void* dst, const void* src, int size) {
	char* dstbyte = (char*) dst;
	char* srcbyte = (char*) src;
	while (size--) {
		*dstbyte++ = *srcbyte++;
	}
	return dst;
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

void String::operator=(const String &str)
{
	length = str.Length();
	Enalloc(length+1, false);
	memcpy(data, str.data, length);
	data[length] = '\0';
}

void String::operator=(const char *str)
{
	if (!str) {
		Enalloc(1, false);
		data[0] = '\0';
		length = 0;
		return;
	}
	if (str == data) {
		return;
	}
	// Check for aliasing
	if (str >= data && str <= data + length) {
		int i,  diff = str - data;
		for (i = 0;  str[i]; i++) {
			data[i] = str[i];
		}
		data[i] = '\0';
		length -= diff;
		return;
	}
	int len = strlen(str);
	Enalloc(len+1, false);
	strcpy(data, str);
	length = len;
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
