#include <util.h>
#include <catch.h>

TEST_CASE("vectors can be initalized and assigned", "[vector]")
{
	util::Vector2 vector_without_arguments;
	util::Vector2 vector_with_arguments(15.0f, 20.0f);
	util::Vector2 vector_copy(vector_with_arguments);
	util::Vector2 vector_zero(0.0f, 0.0f);

	SECTION("initialing vectors gives expected length") {
		REQUIRE(vector_without_arguments.Length() == 0);
		REQUIRE(vector_with_arguments.Length() == 25.0f);
		REQUIRE(vector_copy.Length() == 25.0f);
		REQUIRE(vector_zero.Length() == 0);
	}

	SECTION("assigning new values updates vector length") {
		vector_without_arguments = vector_copy;
		REQUIRE(vector_without_arguments.Length() == 25.0f);
		vector_without_arguments = vector_zero;
		REQUIRE(vector_without_arguments.Length() == 0);
	}
}

TEST_CASE("vectors can be compared with other vectors", "[vector]")
{
	util::Vector2 vector_without_arguments;
	util::Vector2 vector_equal_one(15.0f, 20.0f);
	util::Vector2 vector_equal_two(15.0f, 20.0f);
	util::Vector2 vector_not_equal(30.0f, 40.0f);
	util::Vector2 vector_zero(0.0f, 0.0f);

  	SECTION("testing for equality gives expected results") {
		REQUIRE(vector_without_arguments == vector_zero);
		REQUIRE(vector_equal_one == vector_equal_two);
		REQUIRE_FALSE(vector_not_equal == vector_equal_one);
		REQUIRE_FALSE(vector_not_equal == vector_without_arguments);
		REQUIRE_FALSE(vector_not_equal == vector_zero);
	}

	SECTION("testing for inequality gives expected results") {
		REQUIRE(vector_not_equal != vector_zero);
		REQUIRE(vector_not_equal != vector_equal_one);
		REQUIRE(vector_not_equal != vector_without_arguments);
		REQUIRE_FALSE(vector_without_arguments != vector_zero);
		REQUIRE_FALSE(vector_equal_one != vector_equal_two);
	}
}

TEST_CASE("vector can be accessed like arrays", "[vector]")
{
	util::Vector2 vector_variable(50.0f, 100.0f);
	const util::Vector2 vector_constant(75.0f, 150.0f);

	SECTION("reading by index returns value") {
		REQUIRE(vector_variable[0] == 50.0f);
		REQUIRE(vector_variable[1] == 100.0f);
	}

	SECTION("reading constant returns value") {
		REQUIRE(vector_constant[0] == 75.0f);
		REQUIRE(vector_constant[1] == 150.0f);
	}

	SECTION("writing to index updates size") {
		vector_variable[0] = 15.0f;
		vector_variable[1] = 20.0f;
		REQUIRE(vector_variable.Length() == 25);
	}
}

TEST_CASE("vectors can be added", "[vector]")
{
	util::Vector2 vector_result;
	util::Vector2 vector_one(10.0f, 5.0f);
	util::Vector2 vector_two(5.0f, 15.0f);

	SECTION("adding two vectors returns new vector") {
		vector_result = vector_one + vector_two;
		REQUIRE(vector_result.Length() == 25);
		REQUIRE(vector_one.Length() != 25);
	}

	SECTION("compound addition modifies value") {
		vector_result += vector_one;
		vector_result += vector_two;
		REQUIRE(vector_result.Length() == 25);
	}
}

TEST_CASE("vectors can be subtracted", "[vector]")
{
	util::Vector2 vector_result;
	util::Vector2 vector_one(30.0f, 40.0f);
	util::Vector2 vector_two(15.0f, 20.0f);

	SECTION("subtracting two vectors returns new vector") {
		vector_result = vector_one - vector_two;
		REQUIRE(vector_result.Length() == 25);
		REQUIRE(vector_one.Length() != 25);
	}

	SECTION("compound subraction modifies value") {
		vector_one -= vector_two;
		vector_one -= vector_two;
		REQUIRE(vector_one.Length() == 0);
	}
}
