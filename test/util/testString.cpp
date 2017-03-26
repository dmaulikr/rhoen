#define CATCH_CONFIG_MAIN
#include <util.h>
#include <catch.h>

TEST_CASE("Char arrays can be compared", "[util::strcmp]")
{
	int val_a = util::strcmp("string", "string");
	REQUIRE(val_a == 0);

	int val_c = util::strcmp("abcdef", "ABCDEF");
	REQUIRE(val_c > 0);

	int val_d = util::strcmp("ABCDEF", "abcdef");
	REQUIRE(val_d < 0);
}

TEST_CASE("Strings can be initialized", "[util::String]")
{
	util::String str_a;
	REQUIRE(str_a.Length() == 0);

	util::String str_b("0123456789");
	REQUIRE(str_b.Length() == 10);

	util::String str_c(str_b);
	REQUIRE(str_c.Length() == 10);
}

TEST_CASE("Strings can be assigned", "[util::String]")
{
	util::String str_a;
	util::String str_b;

	str_a = "Foo";
	str_b = "Foobar";

	util::String str_c = str_a;
	REQUIRE(str_c.Length() == 3);

	util::String str_d = str_b;
	REQUIRE(str_d.Length() == 6);
}

TEST_CASE("Strings can be compared", "[util::String]")
{
	util::String str_a("Foo");
	util::String str_b("Foo");
	util::String str_c("foo");

	REQUIRE(str_a == str_b);
	REQUIRE(str_a != str_c);

	REQUIRE("Foo" == str_a);
	REQUIRE("foo" != str_a);

	REQUIRE(str_a == "Foo");
	REQUIRE(str_a != "foo");
}
