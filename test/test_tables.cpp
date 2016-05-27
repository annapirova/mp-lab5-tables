#include "gtest.h"
#include "tables.h"
#include "treetable.h"

 
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

TEST(NodeTree, can_create) {
	PList l;
	l.Insert(Monom(1,111));
	NodeTree t;
	t.poly=&l;
	t.key="a";
	EXPECT_EQ(t.key,"a");
}

TEST(TreeTable, can_find) {
	PList l1,l2,l3,l4,l5;
	l1.Insert(Monom(1,111));
	l2.Insert(Monom(2,222));
	l3.Insert(Monom(3,333));
	
	NodeTree n1,n2,n3,n4,n5;
	NodeTree *f;
	n1.poly=&l1;
	n2.poly=&l2;
	n3.poly=&l3;
	n4.poly=&l1;
	n5.poly=&l2;
	
	n1.key="5";
	n2.key="3";
	n3.key="1";
	n4.key="4";
	n5.key="9";

	TreeTable tr;
	tr.Insert(n1);
	tr.Insert(n2);
	tr.Insert(n3);
	tr.Insert(n4);
	tr.Insert(n5);
	f=tr.Find(tr.root,"4");
	EXPECT_EQ(f->key,"4");
}

TEST(NodeTree, can_equate) {
	PList l;
	l.Insert(Monom(1,111));
	NodeTree t1,t2;
	t1.poly=&l;
	t1.key="a";
	t2=t1;
	EXPECT_TRUE(t1.operator==(t2));
}

TEST(TreeTable, can_insert) {
	PList l1;
	NodeTree n;
	l1.Insert(Monom(1,111));
	n.poly=&l1;
	n.key="a";
	TreeTable t;
	t.Insert(n);
	EXPECT_EQ(t.root->key,"a");
}

TEST(TreeTable, can_ins) {
	PList l1,l2,l3,l4,l5;
	l1.Insert(Monom(1,111));
	l2.Insert(Monom(2,222));
	l3.Insert(Monom(3,333));
	
	NodeTree n1,n2,n3,n4,n5;
	n1.poly=&l1;
	n2.poly=&l2;
	n3.poly=&l3;
	n4.poly=&l1;
	n5.poly=&l2;
	
	n1.key="5";
	n2.key="3";
	n3.key="1";
	n4.key="4";
	n5.key="9";

	TreeTable tr;
	tr.Insert(n1);
	tr.Insert(n2);
	tr.Insert(n3);
	tr.Insert(n4);
	tr.Insert(n5);
	EXPECT_EQ(tr.root->key,"5");
	EXPECT_EQ(tr.root->Right->key,"9");
	EXPECT_EQ(tr.root->Left->key,"3");
	EXPECT_EQ(tr.root->Left->Right->key,"4");
	EXPECT_EQ(tr.root->Left->Left->key,"1");
	
}


TEST(TreeTable, can_del1) {		//узел
	PList l1,l2,l3;
	l1.Insert(Monom(1,111));
	l2.Insert(Monom(2,222));
	l3.Insert(Monom(3,333));
	
	NodeTree n1,n2,n3,n4,n5;
	n1.poly=&l1;
	n2.poly=&l2;
	n3.poly=&l3;
	n4.poly=&l1;
	n5.poly=&l2;
	
	n1.key="6";
	n2.key="3";
	n3.key="1";
	n4.key="4";
	

	TreeTable tr;
	tr.Insert(n1);
	tr.Insert(n2);
	tr.Insert(n3);
	tr.Insert(n4);
	tr.Delete("3");
	EXPECT_EQ(tr.root->key,"6");
	EXPECT_EQ(tr.root->Left->key,"4");
	EXPECT_EQ(tr.root->Left->Left->key,"1");	
}

TEST(TreeTable, can_del2) {		//лист
	PList l1,l2,l3;
	l1.Insert(Monom(1,111));
	l2.Insert(Monom(2,222));
	l3.Insert(Monom(3,333));
	
	NodeTree n1,n2,n3,n4,n5;
	n1.poly=&l1;
	n2.poly=&l2;
	n3.poly=&l3;
	n4.poly=&l1;
	n5.poly=&l2;
	
	n1.key="6";
	n2.key="3";
	n3.key="1";
	n4.key="4";
	

	TreeTable tr;
	tr.Insert(n1);
	tr.Insert(n2);
	tr.Insert(n3);
	tr.Insert(n4);
	tr.Delete("1");
	NodeTree *tmp = NULL;
	EXPECT_EQ(tr.root->key,"6");
	EXPECT_EQ(tr.root->Left->key,"3");
	EXPECT_EQ(tr.root->Left->Left,tmp);
	EXPECT_EQ(tr.root->Left->Right->key,"4");	

}

TEST(TreeTable, can_del3) {		//корень
	PList l1,l2,l3;
	l1.Insert(Monom(1,111));
	l2.Insert(Monom(2,222));
	l3.Insert(Monom(3,333));
	
	NodeTree n1,n2,n3,n4,n5;
	n1.poly=&l1;
	n2.poly=&l2;
	n3.poly=&l3;
	n4.poly=&l1;
	n5.poly=&l2;
	
	n1.key="6";
	n2.key="3";
	n3.key="1";
	n4.key="4";
	

	TreeTable tr;
	tr.Insert(n1);
	tr.Insert(n2);
	tr.Insert(n3);
	tr.Insert(n4);
	tr.Delete("6");
	EXPECT_EQ(tr.root->key,"-1");

}




TEST(TreeTable, can_search_min) {
	PList l1,l2,l3;
	l1.Insert(Monom(1,111));
	l2.Insert(Monom(2,222));
	l3.Insert(Monom(3,333));
	
	NodeTree n1,n2,n3,n4,n5;
	n1.poly=&l1;
	n2.poly=&l2;
	n3.poly=&l3;
	n4.poly=&l1;
	n5.poly=&l2;
	
	n1.key="7";
	n2.key="4";
	n3.key="6";
	n4.key="8";
	n5.key="3";
	
	TreeTable tr;
	tr.Insert(n1);
	tr.Insert(n2);
	tr.Insert(n3);
	tr.Insert(n4);
	tr.Insert(n5);
	
	EXPECT_EQ(tr.SearchMin(tr.root)->key,"3");
}

TEST(TreeTable, can_search_max) {
	PList l1,l2,l3;
	l1.Insert(Monom(1,111));
	l2.Insert(Monom(2,222));
	l3.Insert(Monom(3,333));
	
	NodeTree n1,n2,n3,n4,n5;
	n1.poly=&l1;
	n2.poly=&l2;
	n3.poly=&l3;
	n4.poly=&l1;
	n5.poly=&l2;
	
	n1.key="7";
	n2.key="4";
	n3.key="6";
	n4.key="8";
	n5.key="3";
	
	TreeTable tr;
	tr.Insert(n1);
	tr.Insert(n2);
	tr.Insert(n3);
	tr.Insert(n4);
	tr.Insert(n5);
	
	EXPECT_EQ(tr.SearchMax(tr.root)->key,"8");
}


TEST(TreeTable, can_search_next) {
	PList l1,l2,l3;
	l1.Insert(Monom(1,111));
	l2.Insert(Monom(2,222));
	l3.Insert(Monom(3,333));
	
	NodeTree n1,n2,n3,n4,n5;
	n1.poly=&l1;
	n2.poly=&l2;
	n3.poly=&l3;
	n4.poly=&l1;
	n5.poly=&l2;
	
	n1.key="7";
	n2.key="4";
	n3.key="6";
	n4.key="9";
	n5.key="8";
	
	TreeTable tr;
	tr.Insert(n1);
	tr.Insert(n2);
	tr.Insert(n3);
	tr.Insert(n4);
	tr.Insert(n5);
	
	EXPECT_EQ(tr.SearchNext(tr.root)->key,"8");
}

TEST(TreeTable, can_search_prev) {
	PList l1,l2,l3;
	l1.Insert(Monom(1,111));
	l2.Insert(Monom(2,222));
	l3.Insert(Monom(3,333));
	
	NodeTree n1,n2,n3,n4,n5;
	n1.poly=&l1;
	n2.poly=&l2;
	n3.poly=&l3;
	n4.poly=&l1;
	n5.poly=&l2;
	
	n1.key="7";
	n2.key="4";
	n3.key="6";
	n4.key="9";
	n5.key="8";
	
	TreeTable tr;
	tr.Insert(n1);
	tr.Insert(n2);
	tr.Insert(n3);
	tr.Insert(n4);
	tr.Insert(n5);
	
	EXPECT_EQ(tr.SearchPrev(tr.root)->key,"6");
}

