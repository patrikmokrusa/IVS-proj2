//============================================================================//
//
// Purpose:     tests for mathlib.cpp
//
// $NoKeywords: $kalkulacka $mathlib.cpp
// $Author:    Patrik Mokruša <xmokrup00@stud.fit.vutbr.cz>
// $Date:       $2024-19-04
//============================================================================//
/**
 * @file test_mathlib.cpp
 * @author Patrik Mokruša
 *
 * @brief testy pro matematickou knihovnu zapomoci googletest.
 * kazdy test zahrnuje test na spravnost vysledku a chybove inputy (desetinne cisla, zaporne cisla a zaporne desetinne cisla).
 */


// Includes
#include "../mathlib.cpp"
#include "gtest/gtest.h"


/**
 * @brief Slouzi hlavne k rozeznani testu Basic (jednoduzsich) funkci matematicke knihovny
*/
class Basic_math_test : public ::testing::Test {};

/**
 * @brief Slouzi hlavne k rozeznani testu Advanced (slozitejsich) funkci matematicke knihovny
*/
class Advanced_math_test : public ::testing::Test {};

TEST_F(Basic_math_test, Plus) {
  double base_num = 5;
  double num = 3;
  double val = k_plus(base_num, num);

  EXPECT_EQ(val, 8);

  num = 0.3;
  double val2 = k_plus(5, num);
  EXPECT_EQ(val2, 5.3);
}

TEST_F(Basic_math_test, Minus) {
  double base_num = 5;
  double num = 3;
  double val = k_minus(base_num, num);

  EXPECT_EQ(val, 2);

  num = 0.3;
  val = k_minus(base_num, num);
  EXPECT_EQ(val, 4.7);
}

TEST_F(Basic_math_test, Krat) {
  double base_num = 5;
  double num = 3;
  double val = k_krat(base_num, num);

  EXPECT_EQ(val, 15);

  num = 0.3;
  val = k_krat(base_num, num);
  EXPECT_EQ(val, 1.5);
}

TEST_F(Basic_math_test, Deleno) {
  double base_num = 6;
  double num = 2;
  double val = k_deleno(base_num, num);

  EXPECT_EQ(val, 3);

  num = 0.3;
  val = k_deleno(base_num, num);
  EXPECT_EQ(val, 20);

  EXPECT_THROW(k_deleno(10, 0), std::overflow_error);
}

TEST_F(Advanced_math_test, Faktorial) {
  double base_num = 5;
  double val = k_faktorial(base_num);

  EXPECT_EQ(val, 120);

  base_num = -1.2;
  EXPECT_THROW(k_faktorial(base_num), std::out_of_range);
}

TEST_F(Advanced_math_test, Mocnina) {
  double base_num = 2;
  double num = 3;
  double val = k_mocnina(base_num, num);

  EXPECT_EQ(val, 8);

  double num1 = 0.3;
  EXPECT_THROW(k_mocnina(10, num1), std::out_of_range);

  double num2 = -3;
  EXPECT_THROW(k_mocnina(10, num2), std::out_of_range);

  double num3 = -0.3;
  EXPECT_THROW(k_mocnina(10, num3), std::out_of_range);
}

TEST_F(Advanced_math_test, Odmocnina) {
  // basic odmocnina (odmocnitel == 2)
  double val = k_odmocnina(169, 2);
  EXPECT_EQ(val, 13);
  EXPECT_THROW(k_odmocnina(-10, 2), std::invalid_argument);

  // obecna odmocnina
  double base_num = 8;
  double num = 3;
  double val2 = k_odmocnina(base_num, num);
  EXPECT_EQ(val2, 2);

  EXPECT_THROW(k_odmocnina(-10, 2), std::invalid_argument);

  EXPECT_THROW(k_odmocnina(10, 0.3), std::out_of_range);

  EXPECT_THROW(k_odmocnina(10, -3), std::out_of_range);

  EXPECT_THROW(k_odmocnina(10, -0.3), std::out_of_range);

  double val3 = k_odmocnina(16, 4);
  EXPECT_EQ(val3, 2);

  double val4 = k_odmocnina(1024, 10);
  EXPECT_EQ(val4, 2);
}


TEST_F(Advanced_math_test, Obracena_hodnota) {
  double base_num = 2;
  double val = k_obracena_hodnota(base_num);

  EXPECT_EQ(val, 0.5);
  EXPECT_EQ(4, k_obracena_hodnota(0.25));
  EXPECT_EQ(-4, k_obracena_hodnota(-0.25));

  EXPECT_THROW(k_obracena_hodnota(0), std::overflow_error);
}
