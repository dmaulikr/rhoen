namespace util {
	class String;
}

/**
 * Container for storing characters sequences.
 * Keeps an internal buffer to hold any sequence of characters. Will also
 * allocate more memory if the string length exceeds its buffer size. This
 * implementation should be pretty standard for a C++ string. New features
 * will be added when they are needed by other parts of the project.
 */
class util::String
{
public:
	String();
	~String();

	int Length() const; ///< Gets length of string
	int Cmp(const char *str) const; ///< Compares string with char array
};
