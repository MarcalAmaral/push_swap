#include "push_swap.h"
#include <gtest/gtest.h>

TEST(ValidationsTests, InvalidParam)
{
	EXPECT_EQ(invalid_param(ft_split("20 1a", ' ')), TRUE);
	EXPECT_EQ(invalid_param(ft_split("20 a --2000", ' ')), TRUE);
}

TEST(ValidationsTests, BiggerOrSmallerInt)
{
	EXPECT_EQ(bigger_or_smaller_int(ft_split("32132132132123132 132132132132", ' ')), TRUE);
	EXPECT_EQ(bigger_or_smaller_int(ft_split("-32132132132123132 132132132132", ' ')), TRUE);
	EXPECT_EQ(bigger_or_smaller_int(ft_split("-321322 31321", ' ')), FALSE);
}

TEST(ValidationsTests, DuplicatedValues)
{
	EXPECT_EQ(duplicated_values(formated_array(ft_split("20 2323 01 20", ' '), 1), 4), TRUE);
	EXPECT_EQ(duplicated_values(formated_array(ft_split("20 2323 01 25", ' '), 1), 4), FALSE);
}