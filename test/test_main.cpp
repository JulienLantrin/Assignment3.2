#include <Arduino.h>
#include <unity.h>
#include <fifo.h>


void reset_test(void){
    Fifo fifo;
    fifo.put(5);
    fifo.reset();
    TEST_ASSERT_TRUE(fifo.is_empty());
}

void normal_flow_test(void){
    Fifo fifo;
    fifo.put(1);
    fifo.put(4);
    fifo.get();
    TEST_ASSERT_TRUE(4==fifo.get());
}

void underflow_test(void){
    Fifo fifo;
    fifo.put(1);
    fifo.get();
    TEST_ASSERT_TRUE(fifo.is_empty());
}

void overflow_full_test(void){
    Fifo fifo;
    fifo.put(1);
    fifo.put(1);
    fifo.put(1);
    fifo.put(1);
    fifo.put(1);
    TEST_ASSERT_TRUE(fifo.is_full());
}

void overflow_test(void){
    Fifo fifo;
    fifo.put(1);
    fifo.put(2);
    fifo.put(3);
    fifo.put(4);
    fifo.put(5);
    fifo.put(6);
    TEST_ASSERT_TRUE(6==fifo.get());
}


void setup(){
    delay(2000);

    UNITY_BEGIN();

    RUN_TEST(reset_test);
    RUN_TEST(normal_flow_test);
    RUN_TEST(underflow_test);
    RUN_TEST(overflow_full_test);
    RUN_TEST(overflow_test);
    UNITY_END();

    // UNITY_BEGIN();
    // RUN_TEST(underflow_test);
    // UNITY_END();
}

void loop(){
    delay(100);
}