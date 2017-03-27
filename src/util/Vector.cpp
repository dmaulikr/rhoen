#include <util.h>
namespace util {

Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2::~Vector2()
{
}

Vector2::Vector2(const Vector2 &vec)
{
	x = vec.x;
	y = vec.y;
}

Vector2::Vector2(const float vx, const float vy)
{
	x = vx;
	y = vy;
}

void Vector2::Set(const float vx, const float vy)
{
	x = vx;
	y = vy;
}

bool Vector2::Compare(const Vector2 &vec) const
{
	return ((x == vec.x) && (y == vec.y));
}

float Vector2::Length() const
{
	return Sqrt((x * x) + (y * y));
}

float Vector2::operator[](int index) const
{
	return (&x)[index];
}

float &Vector2::operator[](int index)
{
	return (&x)[index];
}

void Vector2::operator=(const Vector2 &vec)
{
	x = vec.x;
	y = vec.y;
}

Vector2 &Vector2::operator+=(const Vector2 &vec)
{
	x += vec.x;
	y += vec.y;
	return *this;
}

Vector2 &Vector2::operator-=(const Vector2 &vec)
{
	x -= vec.x;
	y -= vec.y;
	return *this;
}

bool operator==(const Vector2 &a, const Vector2 &b)
{
	return a.Compare(b);
}

bool operator!=(const Vector2 &a, const Vector2 &b)
{
	return !(a.Compare(b));
}

Vector2 operator+(const Vector2 &a, const Vector2 &b)
{
	return Vector2((a.x+b.x), (a.y+b.y));
}

Vector2 operator-(const Vector2 &a, const Vector2 &b)
{
	return Vector2((a.x-b.x), (a.y-b.y));
}

} // namespace util


