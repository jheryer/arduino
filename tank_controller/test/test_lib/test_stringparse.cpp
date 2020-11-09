#ifdef UNIT_TEST

#include <unity.h>
#include <MotorControlUtil.h>

void test_validate_input_name() {

    String value = parseValue("test:1", ':', 0);
    const char* subject = value.c_str();
    TEST_ASSERT_EQUAL_STRING("test",subject);
    TEST_ASSERT_EQUAL(1, 1);
}

int main( int argc, char **argv) {
    UNITY_BEGIN();

    RUN_TEST(test_validate_input_name);

    UNITY_END();
}

#endif