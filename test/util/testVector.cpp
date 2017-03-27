#include <util.h>
#include <catch.h>

TEST_CASE("Vector2 can be initialized", "[util::Vector2]")
{
	util::Vector2 vec1, vec2(6.0f, 8.0f);

	REQUIRE(vec1.Length() == 0.0f);
	REQUIRE(vec2.Length() == 10.0f);
}
