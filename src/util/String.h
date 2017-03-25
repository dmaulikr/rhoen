namespace util
{
	class String;

	const int STR_BUF_BASE = 16; ///< String buffer base size
	const int STR_BUF_GRAN = 32; ///< String allocation granularity

	char *strcpy(char *dst, const char *src); ///< Replacement for strcpy
	int strcmp(const char *a, const char *b); ///< Replacement for strcmp
	int strlen(const char *str); ///< Replacement for strlen
}

/**
 * Container for storing characters sequences.
 * Keeps an internal buffer to hold any sequence of characters. Will reallocate
 * more memory if the data length exceeds its buffer size, while keeping memory
 * size a multiple of STR_BUF_GRAN. This is a pretty basic implementation of a
 * C++ string. New features will be added as required by other submodules.
 */
/// @ingroup util
class util::String
{
public:
	String(); ///< Default constructor
	String(String &str); ///< Copy constructor
	String(const char *str); ///< Copy constructor
	~String(); ///< Destructor

	int Length() const; ///< Returns length of String

private:
	char buffer[STR_BUF_BASE]; ///< Dynamically managed base buffer
	int allocated; ///< Number of bytes currently allocated for buffer
	char *data; ///< Pointer to first character in buffer
	int length; ///< Number of characters in buffer

	void Init(); ///< Initializes private member variables
	void Enalloc(int size, bool copy = true); ///< Ensures there is enough memory
	void Realloc(int size, bool copy = true); ///< Reallocates buffer memory
};

