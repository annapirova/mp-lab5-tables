#include "gtest.h"
#include "tables.h"

 
TEST(NodeTable, can_create)
{
	PList l;
	l.Insert(Monom(1,111));
	NodeTable t("a",&l);
	EXPECT_EQ(t.GetKey(),"a");
	EXPECT_EQ(t.GetElement()->head->next->data.deg,111);
}

TEST(NodeTable, can_compare)
{
	PList l;
	l.Insert(Monom(1,111));
	NodeTable t1("a",&l);
	NodeTable t2("a",&l);
	NodeTable t3("b",&l);
	EXPECT_TRUE(t1.operator==(t2));
	EXPECT_FALSE(t1.operator==(t3));
}

TEST(NodeTable, can_equate)
{
	PList l;
	l.Insert(Monom(1,111));
	NodeTable t1("a",&l);
	NodeTable t2;
	t2=t1;
	EXPECT_TRUE(t1.operator==(t2));
}

TEST(SortedTable, can_create)
{
	PList l1,l2,l3;
	l1.Insert(Monom(1,111));
	l2.Insert(Monom(2,222));
	l3.Insert(Monom(3,333));
	SortedTable t;
	t.Insert("b",&l2);
	t.Insert("a",&l1);
	t.Insert("c",&l3);
	EXPECT_EQ(t.GetData(0).GetKey(),"a");
	EXPECT_EQ(t.GetData(0).GetElement()->head->next->data.deg,111);
	EXPECT_EQ(t.GetData(1).GetKey(),"b");
	EXPECT_EQ(t.GetData(1).GetElement()->head->next->data.deg,222);
	EXPECT_EQ(t.GetData(2).GetKey(),"c");
	EXPECT_EQ(t.GetData(2).GetElement()->head->next->data.deg,333);
}

TEST(SortedTable, can_insert_with_mem)
{
	PList l1,l2,l3;
	l1.Insert(Monom(1,111));
	l2.Insert(Monom(2,222));
	l3.Insert(Monom(3,333));
	SortedTable t;
	int size1=0;
	int size2=0;
	t.Insert("b",&l2);
	size1=t.GetMaxSize();
	t.Insert("a",&l1);
	t.Insert("c",&l3);
	size2=t.GetMaxSize();
	EXPECT_EQ(size1,1);
	EXPECT_EQ(size2,4);
	
}

TEST(SortedTable, can_delete)
{
	PList l1,l2,l3;
	l1.Insert(Monom(1,111));
	l2.Insert(Monom(2,222));
	l3.Insert(Monom(3,333));
	SortedTable t;
	t.Insert("b",&l2);
	t.Insert("a",&l1);
	t.Insert("c",&l3);
	t.Delete("b");
	EXPECT_EQ(t.GetData(0).GetKey(),"a");
	EXPECT_EQ(t.GetData(0).GetElement()->head->next->data.deg,111);
	EXPECT_EQ(t.GetData(1).GetKey(),"c");
	EXPECT_EQ(t.GetData(1).GetElement()->head->next->data.deg,333);
}

TEST(SortedTable, can_find)
{
	PList l1,l2,l3;
	l1.Insert(Monom(1,111));
	l2.Insert(Monom(2,222));
	l3.Insert(Monom(3,333));
	SortedTable t;
	t.Insert("b",&l2);
	t.Insert("a",&l1);
	EXPECT_EQ(t.search("a"),0);
	EXPECT_EQ(t.search("b"),1);
}

TEST(HashTable, can_create) {
	HashTable t;
	PList l;
	l.Insert(Monom(1,111));
	t.Insert("a",&l);
	EXPECT_EQ(t.GetNode("a")->head->next->data.deg,111);
}

TEST(HashTable, insert_collision) 
{
	HashTable t;
	PList l1,l2;
	l1.Insert(Monom(1,111));
	l2.Insert(Monom(2,222));
	t.Insert("bc",&l1);
	t.Insert("ad",&l2);
	EXPECT_EQ(t.data[t.hashfunc("bc")][0].GetKey(),"bc");
	EXPECT_EQ(t.data[t.hashfunc("bc")][1].GetKey(),"ad");
}

TEST(HashTable, can_delete)
{
	PList l1,l2,l3;
	int flag=0;
	l1.Insert(Monom(1,111));
	l2.Insert(Monom(2,222));
	l3.Insert(Monom(3,333));
	HashTable t;
	t.Insert("a",&l1);
	t.Insert("b",&l2);
	t.Delete("b");
	for (int i = 0; i < t.max_size; i++)
		for (int j = 0; j<t.row_size;j++)
			if(t.data[i][j].GetKey()=="b")
				flag=1;
	EXPECT_EQ(flag,0);
}

TEST(HashTable, can_hashfunc) {
	HashTable t;
	PList l;
	l.Insert(Monom(1,111));
	t.Insert("ab",&l);
	int res=0;
	res=(int)('a')+(int)('b');
	EXPECT_EQ(res%t.max_size,t.hashfunc("ab"));
}

TEST(HashTable, insert_with_mem) {
	HashTable t;
	PList l;
	int row1=0;
	int row2=0;
	l.Insert(Monom(1,111));
	t.Insert("a",&l);
	t.Insert("b",&l);
	row1=t.row_size;
	t.Insert("bc",&l);
	t.Insert("ad",&l);
	t.Insert("k",&l);
	row2=t.row_size;
	EXPECT_EQ(row1,1);
	EXPECT_EQ(row2,4);
}


