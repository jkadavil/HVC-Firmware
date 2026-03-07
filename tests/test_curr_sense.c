#include "unity.h"
#include "curr_sense.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_Curr_CalculateCurrentSense_returns_expected_value_near_zero_crossing(void)
{
    TEST_ASSERT_EQUAL_UINT32(347U, Curr_CalculateCurrentSense(1552U));
}

void test_Curr_CalculateCurrentSense_returns_expected_value_at_mid_scale(void)
{
    TEST_ASSERT_EQUAL_UINT32(200201U, Curr_CalculateCurrentSense(2048U));
}

void test_Curr_CalculateCurrentSense_returns_expected_value_at_full_scale(void)
{
    TEST_ASSERT_EQUAL_UINT32(1025000U, Curr_CalculateCurrentSense(4095U));
}

void test_Curr_CalculateCurrentSense_increases_with_adc_value_in_positive_region(void)
{
    uint32_t low = Curr_CalculateCurrentSense(1600U);
    uint32_t mid = Curr_CalculateCurrentSense(3000U);
    uint32_t high = Curr_CalculateCurrentSense(4095U);

    TEST_ASSERT_TRUE(low < mid);
    TEST_ASSERT_TRUE(mid < high);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_Curr_CalculateCurrentSense_returns_expected_value_near_zero_crossing);
    RUN_TEST(test_Curr_CalculateCurrentSense_returns_expected_value_at_mid_scale);
    RUN_TEST(test_Curr_CalculateCurrentSense_returns_expected_value_at_full_scale);
    RUN_TEST(test_Curr_CalculateCurrentSense_increases_with_adc_value_in_positive_region);
    return UNITY_END();
}
