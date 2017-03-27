namespace util {

/**
 * Container for storing floating point values.
 * Can be used like an array and often describes a point or
 * distances in space. Mathematical operations can be performed
 * with vectors and matrices, which makes it possible to rotate
 * transform or translate defined points in 3D perspective.
 * @ingroup util
 */
class Vector2
{
public:
	float x; ///< x value of Vector
	float y; ///< y value of Vector

	Vector2(); ///< Default constructor
	Vector2(const Vector2 &vec); ///< Copy constructor
	Vector2(const float vx, const float vy); ///< Copy constructor
	~Vector2(); ///< Destructor

	void Set(const float vx, const float vy); ///< Sets values of Vector
	bool Compare(const Vector2 &vec) const; ///< Compares with Vector
	float Length() const; ///< Returns length of Vector

	float operator[](int index) const; ///< Subscript operator for constant
	float &operator[](int index); ///< Subscript operator for variable
	void operator=(const Vector2 &vec); ///< Assignment operator
	Vector2 &operator+=(const Vector2 &vec); ///< Addition compound operator
	Vector2 &operator-=(const Vector2 &vec); ///< Subtraction compound operator
};

/// @{ Vector2 non-member, non-friend operator
bool operator==(const Vector2 &a, const Vector2 &b);
bool operator!=(const Vector2 &a, const Vector2 &b);
Vector2 operator+(const Vector2 &a, const Vector2 &b);
Vector2 operator-(const Vector2 &a, const Vector2 &b);
/// @}

} // namespace util
