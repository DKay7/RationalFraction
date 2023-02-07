#include <gtest/gtest.h>
#include "rational.h"
#include <iostream>

TEST(RationalFracTest, Construt) {
    RationalFrac frac;
    
    EXPECT_EQ(frac.get_numerator(), 0);
    EXPECT_EQ(frac.get_denominator(), 1);

    RationalFrac frac1{-1, 2};

    EXPECT_EQ(frac1.get_numerator(), -1);
    EXPECT_EQ(frac1.get_denominator(), 2);
}

TEST(RationalFracTest, Simplification) {
    RationalFrac frac{4, 8};

    EXPECT_EQ(frac.get_numerator(), 1);
    EXPECT_EQ(frac.get_denominator(), 2);

    RationalFrac frac1{4, -8};

    EXPECT_EQ(frac1.get_numerator(), -1);
    EXPECT_EQ(frac1.get_denominator(), 2);

}

TEST(RationalFracTest, InputOutput) {
    std::stringstream stream;
    RationalFrac frac;
    
    stream << "1/2";
    stream >> frac;
    EXPECT_EQ(frac.get_numerator(), 1);
    EXPECT_EQ(frac.get_denominator(), 2);

    stream.clear();
    stream << "3/-4";
    stream >> frac;
    EXPECT_EQ(frac.get_numerator(), -3);
    EXPECT_EQ(frac.get_denominator(), 4);
}

TEST(RationalFracTest, Addition) {
    RationalFrac frac1(1, 2);
    RationalFrac frac2(1, 3);
    RationalFrac frac3 = frac1 + frac2;
    EXPECT_EQ(frac3.get_numerator(), 5);
    EXPECT_EQ(frac3.get_denominator(), 6);
}

TEST(RationalFracTest, AdditionAssigment) {
    RationalFrac frac1(1, 2);
    RationalFrac frac2(1, 3);
    frac1 += frac2;
    EXPECT_EQ(frac1.get_numerator(), 5);
    EXPECT_EQ(frac1.get_denominator(), 6);
}

TEST(RationalFracTest, Subtraction) {
    RationalFrac frac1(1, 2);
    RationalFrac frac2(1, 3);
    RationalFrac frac3 = frac1 - frac2;
    EXPECT_EQ(frac3.get_numerator(), 1);
    EXPECT_EQ(frac3.get_denominator(), 6);
}

TEST(RationalFracTest, SubtractionAssigment) {
    RationalFrac frac1(1, 2);
    RationalFrac frac2(1, 3);
    frac1 -= frac2;
    EXPECT_EQ(frac1.get_numerator(), 1);
    EXPECT_EQ(frac1.get_denominator(), 6);
}

TEST(RationalFracTest, Multiplication) {
    RationalFrac frac1(1, 2);
    RationalFrac frac2(1, 3);
    RationalFrac frac3 = frac1 * frac2;
    EXPECT_EQ(frac3.get_numerator(), 1);
    EXPECT_EQ(frac3.get_denominator(), 6);
}

TEST(RationalFracTest, Division) {
    RationalFrac frac1(1, 2);
    RationalFrac frac2(1, 3);
    RationalFrac frac3 = frac1 / frac2;
    EXPECT_EQ(frac3.get_numerator(), 3);
    EXPECT_EQ(frac3.get_denominator(), 2);
}

TEST(RationalFracTest, Comparison) {
    RationalFrac frac1(1, 2);
    RationalFrac frac2(1, 3);
    RationalFrac frac3(1, 2);

    EXPECT_TRUE(frac1 > frac2);
    EXPECT_TRUE(frac1 >= frac2);
    EXPECT_TRUE(frac2 < frac1);
    EXPECT_TRUE(frac2 <= frac1);
    EXPECT_TRUE(frac1 == frac3);
    EXPECT_TRUE(frac1 >= frac3);
    EXPECT_TRUE(frac1 <= frac3);
}

TEST(RationalFracTest, PrefixIncrement) {
    RationalFrac frac1(1, 2);
    RationalFrac expected(3, 2);

    EXPECT_EQ(++frac1, expected);
}

TEST(RationalFracTest, PostfixIncrement) {
    RationalFrac frac1(1, 2);

    RationalFrac expected_1(1, 2);
    RationalFrac expected_2(3, 2);

    EXPECT_EQ(frac1++, expected_1);
    EXPECT_EQ(frac1, expected_2);
}

TEST(RationalFracTest, PrefixDecrement) {
    RationalFrac frac1(1, 2);
    RationalFrac expected(-1, 2);

    EXPECT_EQ(--frac1, expected);
}

TEST(RationalFracTest, PostfixDecrement) {
    RationalFrac frac1(1, 2);
    RationalFrac expected_1(1, 2);
    RationalFrac expected_2(-1, 2);

    EXPECT_EQ(frac1--, expected_1);
    EXPECT_EQ(frac1, expected_2);
}
