#include "gtest.h"
#include "tables.h"

// тесты мономов и полиномов

TEST(Tables, can_create) {
	HashTable t;
	PList l;
	l.Insert(Monom(1,111));
	t.Insert("a",&l);
	EXPECT_EQ(t.GetNode("a")->head->next->data.deg,111);
}