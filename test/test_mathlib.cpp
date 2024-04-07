#include "gtest/gtest.h"
#include "../libs/mathlib.h"

class Basic_math_test : public ::testing::Test {
};

class Advanced_math_test : public ::testing::Test {
};

TEST_F(Basic_math_test, Plus){
    float base_num = 5;
    float num = 3;
    auto error = k_plus(base_num, num);
    EXPECT_EQ(error, 0);
    EXPECT_EQ(base_num, 8);

    num = 0.3;
    error = k_plus(base_num, num);
    EXPECT_EQ(base_num, 8.3);
    EXPECT_EQ(error, 0);
}

TEST_F(Basic_math_test, Minus){
    float base_num = 5;
    float num = 3;
    auto error = k_minus(base_num, num);
    EXPECT_EQ(error, 0);
    EXPECT_EQ(base_num, 2);

    num = 0.3;
    error = k_minus(base_num, num);
    EXPECT_EQ(base_num, 1.7);
    EXPECT_EQ(error, 0);
}

TEST_F(Basic_math_test, Krat){
    float base_num = 5;
    float num = 3;
    auto error = k_krat(base_num, num);
    EXPECT_EQ(error, 0);
    EXPECT_EQ(base_num, 15);

    num = 0.3;
    error = k_krat(base_num, num);
    EXPECT_EQ(base_num, 4.5);
    EXPECT_EQ(error, 0);
}

TEST_F(Basic_math_test, Deleno){
    float base_num = 6;
    float num = 2;
    auto error = k_deleno(base_num, num);
    EXPECT_EQ(error, 0);
    EXPECT_EQ(base_num, 3);

    num = 0.3;
    error = k_deleno(base_num, num);
    EXPECT_EQ(base_num, 10);
    EXPECT_EQ(error, 0);

    num = 0;
    error = k_deleno(base_num, num);
    EXPECT_EQ(error, 1);
}

TEST_F(Advanced_math_test, Faktorial){
    float base_num = 5;
    auto error = k_faktorial(base_num);
    EXPECT_EQ(error, 0);
    EXPECT_EQ(base_num, 8);

    base_num = 1.2;
    error = k_faktorial(base_num);
    EXPECT_EQ(error, 1);
}

TEST_F(Advanced_math_test, Mocnina){
    float base_num = 2;
    float num = 3;
    auto error = k_mocnina(base_num, num);
    EXPECT_EQ(error, 0);
    EXPECT_EQ(base_num, 8);

    num = 0.3;
    error = k_mocnina(base_num, num);
    EXPECT_EQ(error, 1);

    num = -0.3;
    error = k_mocnina(base_num, num);
    EXPECT_EQ(error, 1);
}

TEST_F(Advanced_math_test, Odmocnina){
    float base_num = 8;
    float num = 3;
    auto error = k_mocnina(base_num, num);
    EXPECT_EQ(error, 0);
    EXPECT_EQ(base_num, 2);

    num = 0.3;
    error = k_mocnina(base_num, num);
    EXPECT_EQ(error, 1);

    num = -0.3;
    error = k_mocnina(base_num, num);
    EXPECT_EQ(error, 1);
}

/**
 * @todo dodelat test na custom
*/