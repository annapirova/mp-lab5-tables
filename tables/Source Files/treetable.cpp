#include "treetable.h"

NodeTree ::NodeTree() //конструктор инициализации
{
	poly= NULL;
	key ="-1";
	Parent=NULL;
	Left=NULL;
	Right=NULL;
}

NodeTree:: NodeTree(const NodeTree &t)	//конструктор копировани€	
{
	key = t.key;
	poly=t.poly;
	Parent=t.Parent;
	Left=t.Left;
	Right=t.Right;
}

NodeTree ::~NodeTree ()//деструктор
{
}

NodeTree& NodeTree:: operator=(const NodeTree &t) //оператор присваивани€
{
	if(this!=&t)
	{
		key =t.key;
		poly=t.poly;
		Parent=t.Parent;
		Left=t.Left;
		Right=t.Right;
	}
	return *this;
}

bool NodeTree:: operator==(const NodeTree &t) //оператор сравнени€
{
	if(t.key==key)
		return true;
	else 
		return false;
}

std::ostream& operator<<(ostream &out, const NodeTree &t) //вывод
{
	out << t.key<<"";
	if(t.Parent!=NULL)
		out<<"-родитель:"<<t.Parent->key<<";"<<endl;
	else 
		out<<"-корень дерева"<< endl;
	
    return out;
}

TreeTable :: TreeTable ()													//конструктор инициализации
{
	root=new NodeTree;
}
TreeTable:: ~TreeTable()													//деструктор
{
	delete root;
}

NodeTree* TreeTable:: Find(NodeTree * curr, string key )			        //поиск записи
{
	NodeTree *tmp=curr;
	if(tmp!=NULL)
	{
		while(tmp->key!=key)
			{
				if(tmp->key>key)
				{
					if(tmp->Left!=NULL)
						tmp=tmp->Left;
					else
					{
						tmp=NULL;
						break;
					}
				}
				else 
				{
					if(tmp->Right!=NULL)
						tmp=tmp->Right;
					else
					{
						tmp=NULL;
						break;
					}
				}
			}
	}
	return tmp;
}

NodeTree * TreeTable::SearchMin(NodeTree * root)		//поиск минимума(самый левый)
{
	NodeTree * tmp=root;
	while(tmp->Left!=NULL)
	{
		tmp=tmp->Left;
	}
	return tmp;
}

NodeTree * TreeTable::SearchMax(NodeTree * root)		//поиск максимума(самый правый)
{
	NodeTree * tmp=root;
	while(tmp->Right!=NULL)
	{
		tmp=tmp->Right;
	}
	return tmp;
}

NodeTree *TreeTable:: SearchNext(NodeTree * root)		//поиск следующего ключа(минимум в правом поддереве)
{
	NodeTree * res=NULL;
	if(root->Right!=NULL)
		res=SearchMin(root->Right);
	return res;
}

NodeTree *TreeTable:: SearchPrev(NodeTree * root)		//поиск предыдущего ключа(макиисмум в левом поддереве)
{
	NodeTree *res=NULL;
	if(root->Left!=NULL)
		res=SearchMax(root->Left);
	else if(root->Parent!=NULL)
		res=root->Parent;
	return res;
}

void TreeTable:: Insert (NodeTree &t)                    
{
	if(this->IsEmpty())
	{
		root=new NodeTree(t);
	}
	else if(Find(root,t.key)!=NULL)
	{
		cout <<"¬ставка невозможна!"<<endl;
		throw "Error 1";
	}
	else
	{
		NodeTree *tmp=root;
		NodeTree *prev=root;
		while(tmp!=NULL)
		{
			prev=tmp;
			if(tmp->key<t.key)
				tmp=tmp->Right;
			else
				tmp=tmp->Left;
		}
		if(prev->key>t.key)
		{
			prev->Left=new NodeTree(t);//&t
			prev->Left->Parent=prev;
		}
		else
		{
			prev->Right=new NodeTree(t);	//&t
			prev->Right->Parent=prev;
		}
	}
}

void TreeTable::Delete (string key)                 
{
	if(this->IsEmpty())
	{
		cout <<"ƒерево пусто!"<<endl;
		throw "Error 2.";
	}
	else 
	{
		NodeTree * tmp;
		tmp=Find(root,key);
		if (tmp==NULL)
		{
			cout<<"¬ дереве нет полинома с таким ключом."<<endl;
			throw "Error 3";
		}
		else
		{
			NodeTree *tmp_x;
			NodeTree * tmp_y;
			if((tmp->Left!=NULL)&&(tmp->Right!=NULL))
				tmp_y=SearchNext(tmp);
			else
				tmp_y=tmp;
			if(tmp_y->Left!=NULL)
				tmp_x=tmp_y->Left;
			else
				tmp_x=tmp_y->Right;
			if(tmp_x!=NULL)
				tmp_x->Parent=tmp_y->Parent;
			if(tmp_y->Parent!=NULL)
			{
				if(tmp_y==tmp_y->Parent->Left)
					tmp_y->Parent->Left=tmp_x;
				else
					tmp_y->Parent->Right=tmp_x;
			}
			if(tmp_y!=tmp)
			{
				tmp->key=tmp_y->key;
				PNode *temp;
				temp =tmp->poly->head->next;
				while (temp!=NULL)
				{
					PNode *toDelete = temp;
					temp=temp->next;
					delete toDelete;
				}
				tmp->poly->head->next=NULL;
				tmp->poly=tmp_y->poly;
			}
			else
			{
				PNode *temp;
				temp =tmp->poly->head->next;
				while (temp!=NULL)
				{
					PNode *toDelete = temp;
					temp=temp->next;
					delete toDelete;
				}
				tmp->poly->head->next=NULL;
				tmp->key="-1";
			}
		}
	}

}

bool TreeTable ::IsEmpty()						  
{
	if(root->key=="-1")
		return true;
	else
		return false;
}

void TreeTable ::Print(NodeTree *curr)			
{
	if(curr->Left!=NULL)
		Print(curr->Left);
	if(curr->Right!=NULL)
		Print (curr->Right);
	cout << *(curr);
}