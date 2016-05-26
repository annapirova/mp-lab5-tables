#include "tables.h"
#include "treetable.h"

void main(){
	
	setlocale (LC_ALL,"Russian");
	PList l1,l2,l3,l4,l5,l6,l7,l8;
	l1.Insert(Monom(1,111));
	l2.Insert(Monom(2,222));
	l3.Insert(Monom(3,333));
	

	//Тестирование таблиц на деревьях
	NodeTree trNode1,trNode3,trNode4,trNode5,trNode6,trNode7,trNode8;
	trNode1.poly=&l1;

	NodeTree trNode2(trNode1);
	trNode3=trNode2;
	trNode4.poly=&l1;
	trNode5.poly=&l2;
	trNode6.poly=&l3;
	trNode7.poly=&l1;
	trNode8.poly=&l2;
	
	trNode1.key="5";
	trNode2.key="3";
	trNode3.key="1";
	trNode4.key="4";
	trNode5.key="2";
	trNode6.key="9";
	trNode7.key="7";
	trNode8.key="6";
	
	
	TreeTable tr;
	tr.Insert(trNode1);
	tr.Insert(trNode2);
	tr.Insert(trNode3);
	tr.Insert(trNode4);
	tr.Insert(trNode5);
	tr.Insert(trNode6);
	tr.Insert(trNode7);
	tr.Insert(trNode8);

	tr.Print(tr.root);
	//cout<<trNode1;

	//Тестирование таблиц
	/*NodeTable tab("abc",&l1);
	SortedTable tabs;
	tabs.Insert("b",&l2);
	tabs.Insert("a",&l1);
	tabs.Insert("c",&l3);
	tabs.Insert("d",&l4);
	cout<<"Сортированная таблица:"<<endl<<tabs<<endl<<endl<<"Хэш таблица:"<<endl;
	
	HashTable t;
	t.Insert("bc",&l1);
	t.Insert("ad",&l2);
	t.Insert("k",&l2);
	t.Insert("c",&l3);
	t.Insert("d",&l4);
	//t.Delete("bc");
	//cout<<t.GetNode("a")->head->next->data.deg<<endl;
	t.print();*/


	getch();
}