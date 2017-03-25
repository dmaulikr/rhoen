namespace util {
	class String;
	const int STR_BUF_BASE = 16; ///< String buffer base size
	const int STR_BUF_GRAN = 32; ///< String allocation granularity
}

/**
 * Container for storing characters sequences.
 * Keeps an internal buffer to hold any sequence of characters. Will reallocate
 * more memory if the data length exceeds its buffer size, keeping the memory
 * size a multiple of STR_BUF_GRAN. This should be a pretty basic implementation
 * of a C++ string. New features will be added as needed by other submodules.
 */
/// @ingroup util
class util::String
{
public:
	String();
	String(String &str);
	String(char *str);
	~String();

private:
	char buffer[STR_BUF_BASE]; ///< Base buffer which can grow if necessary.
	int allocated; ///< Number of bytes currently allocated for buffer.
	char *head; ///< Pointer to first character in the buffer.
	int length; ///< Number of characters that are stored.
};
