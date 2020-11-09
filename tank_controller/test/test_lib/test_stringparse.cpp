#ifdef UNIT_TEST

#include <unity.h>

#include "stringparse.h"

void test_mod1() {
    TEST_ASSERT_EQUAL(1, 1);
}

int main( int argc, char **argv) {
    UNITY_BEGIN();

    RUN_TEST(test_mod1);

    UNITY_END();
}

#endif