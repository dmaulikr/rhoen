#define CATCH_CONFIG_MAIN
#include <util.h>
#include <catch.h>

TEST_CASE("strings can be initialized and assigned", "[string]")
{
	util::String string_without_arguments;
	util::String string_from_char_array("Foo");
	util::String string_from_char('B');
	util::String string_empty("");

	SECTION("initialized string have expected length") {
		REQUIRE(string_without_arguments.Length() == 0);
		REQUIRE(string_from_char_array.Length() == 3);
		REQUIRE(string_from_char.Length() == 1);
		REQUIRE(string_empty.Length() == 0);
	}

	SECTION("assigning new values updates string length") {
		string_empty = string_from_char_array;
		REQUIRE(string_empty.Length() == 3);
		string_empty = string_without_arguments;
		REQUIRE(string_empty.Length() == 0);
		string_empty = "Foobar";
		REQUIRE(string_empty.Length() == 6);
		string_empty = 'A';
		REQUIRE(string_empty.Length() == 1);
	}

	SECTION("checking if empty returns expected value") {
		REQUIRE(string_empty.IsEmpty());
		REQUIRE(string_without_arguments.IsEmpty());
		REQUIRE_FALSE(string_from_char_array.IsEmpty());
		REQUIRE_FALSE(string_from_char.IsEmpty());
		string_from_char_array = "";
		REQUIRE(string_from_char_array.IsEmpty());
	}
}

TEST_CASE("strings can be compared with other strings", "[string]")
{
	util::String string_without_arguments;
	util::String string_equal_one("Foo");
	util::String string_equal_two("Foo");
	util::String string_not_equal("foo");
	util::String string_empty("");

	SECTION("testing for equality gives expected results") {
		REQUIRE(string_without_arguments == string_empty);
		REQUIRE(string_equal_one == string_equal_two);
		REQUIRE(string_equal_one == "Foo");
		REQUIRE("Foo" == string_equal_one);
		REQUIRE_FALSE(string_not_equal == string_equal_one);
		REQUIRE_FALSE(string_not_equal == string_without_arguments);
		REQUIRE_FALSE(string_not_equal == string_empty);
		REQUIRE_FALSE(string_not_equal == "Foo");
		REQUIRE_FALSE("Foo" == string_not_equal);
	}

	SECTION("testing for inequality gives expected results") {
		REQUIRE(string_not_equal != string_empty);
		REQUIRE(string_not_equal != string_equal_one);
		REQUIRE(string_not_equal != string_without_arguments);
		REQUIRE(string_not_equal != "Foo");
		REQUIRE("Foo" != string_not_equal);
		REQUIRE_FALSE(string_without_arguments != string_empty);
		REQUIRE_FALSE(string_equal_one != string_equal_two);
		REQUIRE_FALSE(string_not_equal != "foo");
		REQUIRE_FALSE("foo" != string_not_equal);
		
	}
}

TEST_CASE("strings can be accessed like arrays", "[string]")
{
	util::String string_variable("Foo");
	const util::String string_constant("Bar");

	SECTION("reading by index returns value") {
		REQUIRE(string_variable[0] == 'F');
		REQUIRE(string_variable[2] == 'o');
	}

	SECTION("reading constant returns value") {
		REQUIRE(string_constant[0] == 'B');
		REQUIRE(string_constant[2] == 'r');
	}

	SECTION("writing to index updates value") {
		string_variable[0] = 'A';
		string_variable[1] = 'B';
		REQUIRE(string_variable[0] == 'A');
		REQUIRE(string_variable[1] == 'B');
	}
}

TEST_CASE("strings can be concatenated", "string")
{
	util::String string_result;
	util::String string_one("foo");
	util::String string_two("bar");

	SECTION("adding two strings returns new value") {
		string_result = string_one + string_two;
		REQUIRE(string_result.Length() == 6);
		string_result = string_one + "barbaz";
		REQUIRE(string_result.Length() == 9);
		string_result = "bazbarbuz" + string_one;
		REQUIRE(string_result.Length() == 12);
		string_result =  string_one + 'a';
		REQUIRE(string_result.Length() == 4);
		string_result = 'a' + string_one;
		REQUIRE(string_result.Length() == 4);
		REQUIRE(string_one.Length() == 3);
		REQUIRE(string_two.Length() == 3);
	}

	SECTION("compound operator modifies value") {
		string_result += string_one;
		string_result += string_two;
		REQUIRE(string_result.Length() == 6);
	}
}

TEST_CASE("strings can be converted to different case", "[string]")
{
	util::String string_empty;
	util::String string_lower("abcdef");
	util::String string_upper("ABCDEF");

	SECTION("ToLower converts to lower case") {
		REQUIRE(string_empty.ToLower() == "");
		REQUIRE(string_lower.ToLower() == "abcdef");
		REQUIRE(string_upper.ToLower() == "abcdef");
	}

	SECTION("ToUpper converts to upper case") {
		REQUIRE(string_empty.ToUpper() == "");
		REQUIRE(string_lower.ToUpper() == "ABCDEF");
		REQUIRE(string_upper.ToUpper() == "ABCDEF");
	}
}
