#ifdef UNIT_TEST

#include <unity.h>
#include <MotorControlUtil.h>

void test_validate_input_name() {
    String value = parseMotorControlInputValue("test:1", ':', 0);
    const char* subject = value.c_str();
    TEST_ASSERT_EQUAL_STRING("test",subject);
}

void test_validate_input_value() {
    String value = parseMotorControlInputValue("test:1", ':', 1);
    const char* subject = value.c_str();
    TEST_ASSERT_EQUAL_STRING("1",subject);
}

int main( int argc, char **argv) {
    UNITY_BEGIN();
        RUN_TEST(test_validate_input_name);
        RUN_TEST(test_validate_input_value);
    UNITY_END();
}


#endif