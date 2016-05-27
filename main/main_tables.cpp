#include "tables.h"
#include "treetable.h"

void main(){

	setlocale (LC_ALL,"Russian");
	int z=0;		//для switch
	PList l1;		//полином(один для всех записей)
	l1.Insert(Monom(1,111));
	
	cout<<"Выберите таблицу:"<<endl<<"1)Сортированная"<<endl<<"2)Хеш-таблица"<<endl<<"3)Поисковое дерево"<<endl;
	cin>>z;
	switch(z){
	case 3:{
		//Тестирование таблиц на деревьях
		int kol=0;
		
		TreeTable tr;
		cout<<"Введите количество записей, которое вы хотите добавить:";
			cin>>kol;
			for(int i=0;i<kol;i++){
				NodeTree trNode;
				trNode.poly=&l1;
				string a;
				cout<<"Введите ключ:";
				cin>>a;
				trNode.key=a;
				tr.Insert(trNode);
			}
			cout<<endl;
		tr.Print(tr.root);
		break;
		   }

	case 1:
		{
			//Тестирование таблиц
			//NodeTable tab("abc",&l1);
			SortedTable tabs;
			int kol=0;
			string a;
			cout<<"Введите количество записей, которое вы хотите добавить:";
			cin>>kol;
			for(int i=0;i<kol;i++){
				cout<<"Введите ключ:";
				cin>>a;
				tabs.Insert(a,&l1);}
			cout<<endl<<"Сортированная таблица:"<<endl<<tabs<<endl;	
			break;
		}
	case 2:
		{
			HashTable t;
			string a;
			int kol=0;
			cout<<"Введите количество записей, которое вы хотите добавить:";
			cin>>kol;
			for(int i=0;i<kol;i++){
				cout<<"Введите ключ:";
				cin>>a;
				t.Insert(a,&l1);}
			cout<<endl<<"Хеш-таблица:"<<endl;
			//t.Delete("bc");
			//cout<<t.GetNode("a")->head->next->data.deg<<endl;
			t.print();
			break;
		}
	}

	getch();
}