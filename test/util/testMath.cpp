#include <util.h>
#include <catch.h>

TEST_CASE("Square root can be calculated", "[util::Common]")
{
	REQUIRE(util::sqrt(0) == 0.0f);
	REQUIRE(util::sqrt(1) == 1.0f);
	REQUIRE(util::sqrt(4) == 2.0f);
	REQUIRE(util::sqrt(100) == 10.0f);
}
