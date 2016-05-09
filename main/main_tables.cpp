#include "tables.h"

void main(){
	
	setlocale (LC_ALL,"Russian");
	PList l1,l2, l3, l4;
	l1.Insert(Monom(1,111));
	l2.Insert(Monom(2,222));
	l3.Insert(Monom(3,333));
	l4.Insert(Monom(4,444));

	//NodeTable tab("abc",&l1);
	SortedTable tabs;
	tabs.Insert("b",&l2);
	tabs.Insert("a",&l1);
	tabs.Insert("c",&l3);
	tabs.Insert("d",&l4);
	cout<<tabs<<endl;
	
	HashTable t;
	t.Insert("bc",&l1);
	t.Insert("ad",&l2);
	t.Insert("k",&l2);
	t.Insert("c",&l3);
	t.Insert("d",&l4);
	t.Delete("bc");
	//cout<<t.GetNode("a")->head->next->data.deg<<endl;
	t.print();
	getch();
}