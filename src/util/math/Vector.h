namespace util {
	class Vector;
}

/**
 * Container for storing floating point values.
 * Can be used like an array and often describes a point or
 * distances in space. Mathematical operations can be performed
 * with vectors and matrices, which makes it possible to rotate
 * transform or translate the defined points in 3D perspective.
 */
/// @ingroup util
class util::Vector
{
public:
	Vector();
	~Vector();
};
