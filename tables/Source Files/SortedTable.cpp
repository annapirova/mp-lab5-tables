#include "tables.h"


bool SortedTable::IsFull() {
	if (kol == max_size) 
		return true;
	return false;
}

SortedTable::SortedTable()
{
	kol = 0;
	max_size = 1;
	data = new NodeTable[max_size];
}

SortedTable::~SortedTable()
{
	//delete []data;	
}

void SortedTable::Mem()
{
	NodeTable* temp = new NodeTable[max_size*2];
	for (int i = 0; i < max_size; i++)
	{
		temp[i] = data[i];
	}
	delete[] data;
	max_size = 2 * max_size;
	data = temp;
}

int SortedTable::Find(string key)
{
	if (kol==0)
	{
		return -1;
	}
	int l = -1;                    
	int r = kol;
	int m;
	while (l < r - 1) {            
		m = (l + r) / 2;          
		if (data[m].GetKey() < key)
			l = m;
		else
			r = m;
	}
	return r;
}

void SortedTable::SortedAdd(string key, PList *p)
{
	if (kol == 0)
	{
		data[0] = NodeTable(key, p);
		kol++;
		return;
	}
	if (key<data[0].GetKey())
	{
		for (int i = kol; i > 0; i--) {
			data[i] = data[i-1];
		}
		data[0] = NodeTable(key, p);
		kol++;
		return;
	}
	if (key>data[kol-1].GetKey()) {
		data[kol] = NodeTable(key, p);
		kol++;
		return;
	}

	int index = Find(key);
	for (int i = kol; i > index; i--) 
	{
		data[i] = data[i - 1];
	}
	data[index] = NodeTable(key, p);
	kol++;
	return;
}

void SortedTable::Insert(string key, PList* p)
{

	if (kol==max_size)
	{
		Mem();
	}
	SortedAdd(key, p);
}

void SortedTable::Delete(string key)
{
	int pos = Find(key);
	if(pos==-1)
		cout<<"Запись не найдена"<<endl;
	else{
	for (int i = pos; i < kol-1; i++)
	{
		data[i] = data[i + 1];
	}
	data[kol - 1] = NodeTable("",NULL);
	kol--;
	}
}

PList* SortedTable::GetNode(string key)
{
	int pos = Find(key);
	if (pos == -1)
	{
		return NULL;
	}
	return data[pos].GetElement();
}
std :: ostream& operator<<(ostream &out, SortedTable t){
	
	for (int i = 0; i < t.GetMaxSize(); i++)
	{
		if(t.GetData(i).GetKey()!="")
		out<<t.GetData(i).GetKey()<<";";
	}
	return out;
}