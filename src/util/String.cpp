#include <util.h>
namespace util {

// Replaces strcmp from standard library
int strcmp(const char *a, const char *b)
{
	while((*a && *b) && (*a == *b)) {
		a++; b++;
	}
	return *a - *b;
}

// Replaces strlen from standard library
int strlen(const char *str)
{
	int len;

	len = 0;
	while (*str++) {
		len++;
	}
	return len;
}

// Replaces strcpy from standard library
char *strcpy(char *dst, const char *src)
{
	char *ret;

	ret = dst;
	while ((*dst++ = *src++));
	return ret;
}

// Replaces memcpy from standard library
void *memcpy(void* dst, const void* src, int size)
{
	char *dst_b, *src_b;

	dst_b = (char*) dst;
	src_b = (char*) src;
	while (size--) {
		*dst_b++ = *src_b++;
	}
	return dst;
}

String::String()
{
	Init();
}

String::String(const String &str)
{
	Init();
	length = str.Length();
	Enalloc(length+1);
	strcpy(data, str.data);
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

String::String(const char ch)
{
	Init();
	Enalloc(2);
	data[length++] = ch;
	data[length] = '\0';
}

String::~String()
{
}

int String::Length() const
{
	return length;
}

bool String::IsEmpty() const
{
	return (length == 0);
}

// FIXME: reuse function below
void String::Append(const String &str)
{
	int i, len;
	int newlen;

	len = str.Length();
	newlen = length + len;
	Enalloc(newlen+1);
	for (i = 0; i < len; i++) {
		data[length+i] = str[i];
	}
	length = newlen;
	data[length] = '\0';
}

void String::Append(const char *str)
{
	int i, len;
	int newlen;

	if (!str) {
		return;
	}
	len = strlen(str);
	newlen = length + len;
	Enalloc(newlen+1);
	for (i = 0; i < len; i++) {
		data[length+i] = str[i];
	}
	length = newlen;
	data[length] = '\0' ;
}

void String::Append(const char ch)
{
	Enalloc(length+2);
	data[length++] = ch;
	data[length] = '\0';
}

char *String::c_str() const
{
	return data;
}

String &String::ToLower()
{
	for (int i = 0; i < length; i++) {
		if(data[i] >= 65 && data[i] <= 90) {
			data[i] = data[i] + 32;
		}
	}
	return *this;
}

String &String::ToUpper()
{
	for (int i = 0; i < length; i++) {
		if(data[i] >= 97 && data[i] <= 122) {
			data[i] = data[i] - 32;
		}
	}
	return *this;
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
	int len, diff, i;

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
		diff = str - data;
		for (i = 0;  str[i]; i++) {
			data[i] = str[i];
		}
		data[i] = '\0';
		length -= diff;
		return;
	}
	len = strlen(str);
	Enalloc(len+1, false);
	strcpy(data, str);
	length = len;
}

String &String::operator+=(const String &str)
{
	Append(str);
	return *this;
}

String &String::operator+=(const char *str)
{
	Append(str);
	return *this;
}

String &String::operator+=(const char ch)
{
	Append(ch);
	return *this;
}

char String::operator[](int index) const
{
	return data[index];
}

char &String::operator[](int index)
{
	return data[index];
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
	int mod, newsize;
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

bool operator==(const String &a, const String &b)
{
	return (!util::strcmp(a.data, b.data));
}

bool operator==(const String &a, const char *b)
{
	return (!util::strcmp(a.data, b));
}

bool operator==(const char *a, const String &b)
{
	return (!util::strcmp(a, b.data));
}

bool operator!=(const String &a, const String &b)
{
	return !(a == b);
}

bool operator!=(const String &a, const char *b)
{
	return !(a == b);
}

bool operator!=(const char *a, const String &b)
{
	return !(a == b);
}

String operator+(const String &a, const String &b)
{
	String newstr(a);
	newstr.Append(b);
	return newstr;
}

String operator+(const String &a, const char *b)
{
	String newstr(a);
	newstr.Append(b);
	return newstr;
}

String operator+(const String &a, const char b)
{
	String newstr(a);
	newstr.Append(b);
	return newstr;
}

String operator+(const char *a, const String &b)
{
	String newstr(a);
	newstr.Append(b);
	return newstr;
}

String operator+(const char a, const String &b)
{
	String newstr(a);
	newstr.Append(b);
	return newstr;
}

} // namespace util
