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
	const util::Vector2 vec2(3.0f, 4.0f);

	REQUIRE(vec1[0] == 1.0f);
	REQUIRE(vec1[1] == 2.0f);
	REQUIRE(vec2[0] == 3.0f);
	REQUIRE(vec2[1] == 4.0f);
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

TEST_CASE("Vector2 values can be assigned", "[util::Vector2]")
{
	util::Vector2 vec1(1.0f, 2.0f);
	util::Vector2 vec2(3.0f, 4.0f);
	util::Vector2 vec3, vec4;

	vec3 = vec1;
	REQUIRE(vec3 == vec1);

	vec4 = vec2;
	REQUIRE(vec4 == vec2);
}

TEST_CASE("Vector2 values can be added", "[util::Vector2]")
{
	util::Vector2 vec1, vec2, vec3;
	util::Vector2 vec4(1.0f, 2.0f);
	util::Vector2 vec5(2.0f, 4.0f);
	util::Vector2 vec6(3.0f, 6.0f);

	vec1 = vec2 + vec4;
	REQUIRE(vec1 == vec4);

	vec2 = vec1 + vec4;
	REQUIRE(vec2 == vec5);

	vec3 += vec1;
	vec3 += vec2;
	REQUIRE(vec3 == vec6);
}

TEST_CASE("Vector2 values can be subtracted", "[util::Vector2]")
{
	util::Vector2 vec1, vec2, vec3;
	util::Vector2 vec4(3.0f, 6.0f);
	util::Vector2 vec5(2.0f, 4.0f);
	util::Vector2 vec6(1.0f, 2.0f);
	util::Vector2 vec7(0.0f, 0.0f);

	vec1 = vec4 - vec5;
	REQUIRE(vec1 == vec6);

	vec2 = vec5 - vec6;
	REQUIRE(vec2 == vec6);

	vec3 = vec4;
	vec3 -= vec5;
	vec3 -= vec6;
	REQUIRE(vec3 == vec7);
}
