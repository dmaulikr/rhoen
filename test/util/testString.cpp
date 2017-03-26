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

TEST_CASE("Single Chars can be accessed", "[util::String]")
{
	util::String str_a("abcdefg");
	const util::String str_b("gfedcba");

	REQUIRE(str_a[0] == 'a');
	REQUIRE(str_a[6] == 'g');

	REQUIRE(str_b[0] == 'g');
	REQUIRE(str_b[6] == 'a');
}

TEST_CASE("Strings can be concatenated", "[util::String]")
{
	util::String str_a("abc");
	util::String str_b("def");
	util::String str_c, str_d;
	util::String str_e, str_f;
	util::String str_g, str_h;

	str_c = str_a + str_b;
	REQUIRE(str_c == "abcdef");
	REQUIRE(str_c.Length() == 6);

	str_d = str_a + "def";
	REQUIRE(str_d == "abcdef");
	REQUIRE(str_d.Length() == 6);

	str_e = "abc" + str_b;
	REQUIRE(str_e == "abcdef");
	REQUIRE(str_e.Length() == 6);

	str_f = str_a + 'd';
	REQUIRE(str_f == "abcd");
	REQUIRE(str_f.Length() == 4);

	str_g = 'c' + str_b;
	REQUIRE(str_g == "cdef");
	REQUIRE(str_g.Length() == 4);

	str_h += str_a;
	REQUIRE(str_h == "abc");
	REQUIRE(str_h.Length() == 3);

	str_h += str_b;
	REQUIRE(str_h == "abcdef");
	REQUIRE(str_h.Length() == 6);

	str_h += "ghi";
	REQUIRE(str_h == "abcdefghi");
	REQUIRE(str_h.Length() == 9);

	str_h += 'j';
	REQUIRE(str_h == "abcdefghij");
	REQUIRE(str_h.Length() == 10);
}
