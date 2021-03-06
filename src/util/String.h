namespace util {

const int STR_BUF_BASE = 16; ///< String buffer base size
const int STR_BUF_GRAN = 32; ///< String allocation granularity
char *strcpy(char *dst, const char *src); ///< Replacement for strcpy
void *memcpy(void* dst, const void* src, int size); ///< Replacement for memcpy
int strcmp(const char *a, const char *b); ///< Replacement for strcmp
int strlen(const char *str); ///< Replacement for strlen

/**
 * Container for storing characters sequences.
 * Keeps an internal buffer to hold any sequence of characters. Will reallocate
 * more memory if the data length exceeds its buffer size, while keeping memory
 * size a multiple of STR_BUF_GRAN. This is a pretty basic implementation of a
 * C++ string. New features will be added as required by other submodules.
 * @ingroup util
 */
class String
{
public:
	String(); ///< Default constructor
	String(const String &str); ///< Copy constructor
	String(const char *str); ///< Copy constructor
	String(const char ch); ///< Copy constructor
	~String(); ///< Destructor

	int Length() const; ///< Returns length of String
	bool IsEmpty() const; ///< Checks if String is empty
	void Append(const String &str); ///< Appends String
	void Append(const char *str); ///< Appends char array
	void Append(const char ch); ///< Appends single char
	char *c_str() const; ///< Returns value as char array
	String &ToLower(); ///< Converts to lower case
	String &ToUpper(); ///< Converts to upper case

	char operator[](int index) const; ///< Subscript operator for constant
	char &operator[](int index); ///< Subscript operator for variable
	void operator=(const String &str); ///< Assignment operator
	void operator=(const char *str); ///< Assignment operator
	String &operator+=(const String &str); ///< Concatenation operator
	String &operator+=(const char *str); ///< Concatenation operator
	String &operator+=(const char ch); ///< Concatenation operator

	/// @{ Case sensitive comparison operator
	friend bool operator==(const String &a, const String &b);
	friend bool operator==(const String &a, const char *b);
	friend bool operator==(const char *a, const String &b);
	friend bool operator!=(const String &a, const String &b);
	friend bool operator!=(const String &a, const char *b);
	friend bool operator!=(const char *a, const String &b);
	/// @}

	/// @{ Concatenation operator
	friend String operator+(const String &a, const String &b);
	friend String operator+(const String &a, const char *b);
	friend String operator+(const String &a, const char b);
	friend String operator+(const char *a, const String &b);
	friend String operator+(const char a, const String &b);
	/// @}

private:
	char buffer[STR_BUF_BASE]; ///< Dynamically managed base buffer
	int allocated; ///< Number of bytes currently allocated for buffer
	char *data; ///< Pointer to first character in buffer
	int length; ///< Number of characters in buffer

	void Init(); ///< Initializes private member variables
	void Enalloc(int size, bool copy = true); ///< Ensures there is enough memory
	void Realloc(int size, bool copy = true); ///< Reallocates buffer memory
};

} // namespace util
