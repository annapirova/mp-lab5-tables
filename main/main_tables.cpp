#include "tables.h"
#include "treetable.h"

void main(){

	setlocale (LC_ALL,"Russian");
	int z=0;		//��� switch
	PList l1;		//�������(���� ��� ���� �������)
	l1.Insert(Monom(1,111));
	
	cout<<"�������� �������:"<<endl<<"1)�������������"<<endl<<"2)���-�������"<<endl<<"3)��������� ������"<<endl;
	cin>>z;
	switch(z){
	case 3:{
		//������������ ������ �� ��������
		int kol=0;
		
		TreeTable tr;
		cout<<"������� ���������� �������, ������� �� ������ ��������:";
			cin>>kol;
			for(int i=0;i<kol;i++){
				NodeTree trNode;
				trNode.poly=&l1;
				string a;
				cout<<"������� ����:";
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
			//������������ ������
			//NodeTable tab("abc",&l1);
			SortedTable tabs;
			int kol=0;
			string a;
			cout<<"������� ���������� �������, ������� �� ������ ��������:";
			cin>>kol;
			for(int i=0;i<kol;i++){
				cout<<"������� ����:";
				cin>>a;
				tabs.Insert(a,&l1);}
			cout<<endl<<"������������� �������:"<<endl<<tabs<<endl;	
			break;
		}
	case 2:
		{
			HashTable t;
			string a;
			int kol=0;
			cout<<"������� ���������� �������, ������� �� ������ ��������:";
			cin>>kol;
			for(int i=0;i<kol;i++){
				cout<<"������� ����:";
				cin>>a;
				t.Insert(a,&l1);}
			cout<<endl<<"���-�������:"<<endl;
			//t.Delete("bc");
			//cout<<t.GetNode("a")->head->next->data.deg<<endl;
			t.print();
			break;
		}
	}

	getch();
}