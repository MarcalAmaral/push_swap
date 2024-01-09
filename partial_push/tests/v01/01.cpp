#include "push_swap.h"
#include <gtest/gtest.h>

TEST(ValidationsTests, InvalidParam)
{
	EXPECT_EQ(invalid_param(ft_split("20 1a", ' ')), TRUE);
	EXPECT_EQ(invalid_param(ft_split("20 a --2000", ' ')), TRUE);
	// EXPECT_EQ(invalid_param({"20", "1a"}), TRUE);
	// EXPECT_EQ(invalid_param({"20", "1a"}), TRUE);
}