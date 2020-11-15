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

void test_initial_degree_motor_value() {
    MotorValue subject;

    initMotorValue(&subject);
    TEST_ASSERT_EQUAL_INT(0,getLeftMotorValue(&subject));
    TEST_ASSERT_EQUAL_INT(0,getRightMotorValue(&subject));

    // FORWARD
    parseMotorControlInputDegree(&subject,70);
    TEST_ASSERT_EQUAL_INT(255,getLeftMotorValue(&subject));
    TEST_ASSERT_EQUAL_INT(255,getRightMotorValue(&subject));

    parseMotorControlInputDegree(&subject,65);
    TEST_ASSERT_EQUAL_INT(255,getLeftMotorValue(&subject));
    TEST_ASSERT_EQUAL_INT(255,getRightMotorValue(&subject));

    parseMotorControlInputDegree(&subject,114);
    TEST_ASSERT_EQUAL_INT(255,getLeftMotorValue(&subject));
    TEST_ASSERT_EQUAL_INT(255,getRightMotorValue(&subject));

    //FORWARD RIGHT
    parseMotorControlInputDegree(&subject,115);
    TEST_ASSERT_EQUAL_INT(128,getRightMotorValue(&subject));
    TEST_ASSERT_EQUAL_INT(255,getLeftMotorValue(&subject));

    parseMotorControlInputDegree(&subject,130);
    TEST_ASSERT_EQUAL_INT(128,getRightMotorValue(&subject));
    TEST_ASSERT_EQUAL_INT(255,getLeftMotorValue(&subject));

    parseMotorControlInputDegree(&subject,169);
    TEST_ASSERT_EQUAL_INT(128,getRightMotorValue(&subject));
    TEST_ASSERT_EQUAL_INT(255,getLeftMotorValue(&subject));

    // ROTATE RIGHT
    parseMotorControlInputDegree(&subject,170);
    TEST_ASSERT_EQUAL_INT(-255,getRightMotorValue(&subject));
    TEST_ASSERT_EQUAL_INT(255,getLeftMotorValue(&subject));

    parseMotorControlInputDegree(&subject,180);
    TEST_ASSERT_EQUAL_INT(-255,getRightMotorValue(&subject));
    TEST_ASSERT_EQUAL_INT(255,getLeftMotorValue(&subject));

    parseMotorControlInputDegree(&subject,180);
    TEST_ASSERT_EQUAL_INT(-255,getRightMotorValue(&subject));
    TEST_ASSERT_EQUAL_INT(255,getLeftMotorValue(&subject));

    // BACK RIGHT
    parseMotorControlInputDegree(&subject,190);
    TEST_ASSERT_EQUAL_INT(-128,getRightMotorValue(&subject));
    TEST_ASSERT_EQUAL_INT(-255,getLeftMotorValue(&subject));

    parseMotorControlInputDegree(&subject,230);
    TEST_ASSERT_EQUAL_INT(-128,getRightMotorValue(&subject));
    TEST_ASSERT_EQUAL_INT(-255,getLeftMotorValue(&subject));

    parseMotorControlInputDegree(&subject,254);
    TEST_ASSERT_EQUAL_INT(-128,getRightMotorValue(&subject));
    TEST_ASSERT_EQUAL_INT(-255,getLeftMotorValue(&subject));

    //BACK
     parseMotorControlInputDegree(&subject,255);
    TEST_ASSERT_EQUAL_INT(-255,getRightMotorValue(&subject));
    TEST_ASSERT_EQUAL_INT(-255,getLeftMotorValue(&subject));

    parseMotorControlInputDegree(&subject,280);
    TEST_ASSERT_EQUAL_INT(-255,getRightMotorValue(&subject));
    TEST_ASSERT_EQUAL_INT(-255,getLeftMotorValue(&subject));

    parseMotorControlInputDegree(&subject,299);
    TEST_ASSERT_EQUAL_INT(-255,getRightMotorValue(&subject));
    TEST_ASSERT_EQUAL_INT(-255,getLeftMotorValue(&subject));

    //BACK LEFT
     parseMotorControlInputDegree(&subject,300);
    TEST_ASSERT_EQUAL_INT(-255,getRightMotorValue(&subject));
    TEST_ASSERT_EQUAL_INT(-128,getLeftMotorValue(&subject));

    parseMotorControlInputDegree(&subject,325);
    TEST_ASSERT_EQUAL_INT(-255,getRightMotorValue(&subject));
    TEST_ASSERT_EQUAL_INT(-128,getLeftMotorValue(&subject));

    parseMotorControlInputDegree(&subject,349);
    TEST_ASSERT_EQUAL_INT(-255,getRightMotorValue(&subject));
    TEST_ASSERT_EQUAL_INT(-128,getLeftMotorValue(&subject));

    //LEFT
    parseMotorControlInputDegree(&subject,350);
    TEST_ASSERT_EQUAL_INT(255,getRightMotorValue(&subject));
    TEST_ASSERT_EQUAL_INT(-255,getLeftMotorValue(&subject));

    parseMotorControlInputDegree(&subject,355);
    TEST_ASSERT_EQUAL_INT(255,getRightMotorValue(&subject));
    TEST_ASSERT_EQUAL_INT(-255,getLeftMotorValue(&subject));

    parseMotorControlInputDegree(&subject,360);
    TEST_ASSERT_EQUAL_INT(255,getRightMotorValue(&subject));
    TEST_ASSERT_EQUAL_INT(-255,getLeftMotorValue(&subject));

    parseMotorControlInputDegree(&subject,0);
    TEST_ASSERT_EQUAL_INT(255,getRightMotorValue(&subject));
    TEST_ASSERT_EQUAL_INT(-255,getLeftMotorValue(&subject));

    parseMotorControlInputDegree(&subject,5);
    TEST_ASSERT_EQUAL_INT(255,getRightMotorValue(&subject));
    TEST_ASSERT_EQUAL_INT(-255,getLeftMotorValue(&subject));

    parseMotorControlInputDegree(&subject,9);
    TEST_ASSERT_EQUAL_INT(255,getRightMotorValue(&subject));
    TEST_ASSERT_EQUAL_INT(-255,getLeftMotorValue(&subject));

    //FORWARD LEFT
     parseMotorControlInputDegree(&subject,10);
    TEST_ASSERT_EQUAL_INT(255,getRightMotorValue(&subject));
    TEST_ASSERT_EQUAL_INT(128,getLeftMotorValue(&subject));

    parseMotorControlInputDegree(&subject,50);
    TEST_ASSERT_EQUAL_INT(255,getRightMotorValue(&subject));
    TEST_ASSERT_EQUAL_INT(128,getLeftMotorValue(&subject));

    parseMotorControlInputDegree(&subject,64);
    TEST_ASSERT_EQUAL_INT(255,getRightMotorValue(&subject));
    TEST_ASSERT_EQUAL_INT(128,getLeftMotorValue(&subject));

}

int main( int argc, char **argv) {
    UNITY_BEGIN();
        RUN_TEST(test_validate_input_name);
        RUN_TEST(test_validate_input_value);
        RUN_TEST(test_initial_degree_motor_value);
    UNITY_END();
}


#endif