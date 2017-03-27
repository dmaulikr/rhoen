#include <util.h>
#include <catch.h>

TEST_CASE("Square root can be calculated", "[util::Common]")
{
	REQUIRE(util::Sqrt(0) == 0);
	REQUIRE(util::Sqrt(1) == 1);
	REQUIRE(util::Sqrt(4) == 2);
	REQUIRE(util::Sqrt(100) == 10);
}
