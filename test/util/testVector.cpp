#include <util.h>
#include <catch.h>

TEST_CASE("Vector2 can be initialized", "[util::Vector2]")
{
	util::Vector2 vec1(6.0f, 8.0f);
	util::Vector2 vec2;

	REQUIRE(vec1.Length() == 10.0f);
	REQUIRE(vec2.Length() == 0.0f);
}

TEST_CASE("Vector2 values can be accessed", "[util::Vector2]")
{
	util::Vector2 vec1(1.0f, 2.0f);

	REQUIRE(vec1[0] == 1.0f);
	REQUIRE(vec1[1] == 2.0f);
}

TEST_CASE("Vector2 values can be assigned", "[util::Vector2]")
{
	util::Vector2 vec1(6.0f, 8.0f);
	util::Vector2 vec2;

	vec2 = vec1;
	REQUIRE(vec2.Length() == 10.0f);
}

TEST_CASE("Vector2 values can be compared", "[util::Vector2]")
{
	util::Vector2 vec1(1.0f, 2.0f);
	util::Vector2 vec2(1.0f, 2.0f);
	util::Vector2 vec3(1.1f, 2.1f);
	util::Vector2 vec4(1.1f, 2.1f);

	REQUIRE(vec1 == vec2);
	REQUIRE(vec2 != vec3);
	REQUIRE(vec3 == vec4);
	REQUIRE(vec4 != vec1);
}
