#include "unity.h"
#include "lv_can_manager.h"
#include "test_stubs.h"

void setUp(void)
{
    Test_Stubs_Reset();
}

void tearDown(void)
{
}

void test_LV_CAN_Manager_Init_success(void)
{
    osMessageQueueId_t results[1] = { (void*)0x1 };
    Test_SetQueueNewResults(results, 1);

    TEST_ASSERT_EQUAL(HAL_OK, LV_CAN_Manager_Init());
    TEST_ASSERT_EQUAL_UINT32(1, Test_GetQueueNewCallCount());
}

void test_LV_CAN_Manager_Init_tx_queue_fail(void)
{
    osMessageQueueId_t results[2] = { NULL, (void*)0x2 };
    Test_SetQueueNewResults(results, 2);

    TEST_ASSERT_EQUAL(HAL_ERROR, LV_CAN_Manager_Init());
    TEST_ASSERT_EQUAL_UINT32(1, Test_GetQueueNewCallCount());
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_LV_CAN_Manager_Init_success);
    RUN_TEST(test_LV_CAN_Manager_Init_tx_queue_fail);

    return UNITY_END();
}
