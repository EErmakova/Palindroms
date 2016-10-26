#include <gtest/gtest.h>
#include "IsPalindrom.h"

TEST(Palindrom, empty_list_is_palindrom)
{
	EXPECT_TRUE(IsPalindrom(NULL));
}

TEST(Palindrom, one_elem_is_palindrom)
{
	CNode seven(7);
	EXPECT_TRUE(IsPalindrom(&seven));
}

TEST(Palindrom, even_list_is_not_palindrom)
{
	const int size = 10;
	CNode list[size];
	for (int i = 0; i < size-1; ++i)
	{
		list[i].data = 10-i;
		list[i].next = &list[i + 1];
	}
	list[size - 1] = (size - 9);

	EXPECT_FALSE(IsPalindrom(list));
}

TEST(Palindrom, odd_list_is_not_palindrom)
{
	const int size = 9;
	CNode list[size];
	int a[size] = { 1, 2, 3, 4, 5, 3, 4, 2, 1 };
	for (int i = 0; i < size - 1; ++i)
	{
		list[i].data = a[i];
		list[i].next = &list[i + 1];
	}
	list[size - 1] = a[size - 1];

	EXPECT_FALSE(IsPalindrom(list));
}

TEST(Palindrom, even_list_is_palindrom)
{
	const int size = 10;
	CNode list[size];
	for (int i = 0; i < size / 2; i++)
	{
		list[i].data = i;
		list[i].next = &list[i + 1];
	}
	for (int i =  size / 2; i < size - 1; i++)
	{
		list[i].data = size - i - 1;
		list[i].next = &list[i + 1];
	}
	list[size - 1] = 0;

	EXPECT_TRUE(IsPalindrom(list));
}

TEST(Palindrom, odd_list_is_palindrom)
{
	const int size = 9;
	CNode list[size];
	int a[size] = { 1, 3, 5, 7, 9, 7, 5, 3, 1 };
	for (int i = 0; i < size - 1; ++i)
	{
		list[i].data = a[i];
		list[i].next = &list[i + 1];
	}
	list[size - 1] = a[size - 1];

	EXPECT_TRUE(IsPalindrom(list));
}

int main(int ac, char* av[])
{
  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}