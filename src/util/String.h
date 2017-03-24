/**
 * @brief Container class for managing characters sequences.
 * Keeps an internal buffer to store any sequence of characters. Will also
 * allocate more memory if the string length exceeds its buffer size. This
 * implementation should be pretty standard for a C++ string. New features
 * will be added when they are needed by other parts of the project.
 */
class String
{
public:
	String();
	~String();

	int Length() const; ///< Get length of string
	int Cmp(const char *str) const; ///< Compare string with char array
};
