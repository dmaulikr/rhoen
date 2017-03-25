#define CATCH_CONFIG_MAIN
#include <util.h>
#include <catch.h>

TEST_CASE("Strings can be initialized", "[String]")
{
	util::String str_a;
	REQUIRE(str_a.Length() == 0);

	util::String str_b("0123456789");
	REQUIRE(str_b.Length() == 10);

	util::String str_c(str_b);
	REQUIRE(str_c.Length() == 10);
}
