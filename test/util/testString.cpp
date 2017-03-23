#define CATCH_CONFIG_MAIN
#include <util.h>
#include <catch.h>

TEST_CASE("Strings can be initialized", "[String]") {
    REQUIRE(1 == 1);
    REQUIRE(2 == 2);
    REQUIRE(3 == 3);
}
