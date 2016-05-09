#include "tables.h"

NodeTable::NodeTable() {
	name = "";
	element = new PList;
}

NodeTable::NodeTable(const NodeTable& t) {
	name = t.GetKey();
	element = new PList(*t.GetElement());
}

NodeTable::NodeTable(string name_, PList* elem) {
	name = name_;
	element = elem;
}

NodeTable& NodeTable::operator=(NodeTable& t) {
	if (this == &t) {
		return *this;
	}
	name = t.GetKey();
	element = t.GetElement();
	return *this;
}

bool NodeTable::operator==(const NodeTable& t)
{
	return t.GetKey() == GetKey();
}

string NodeTable::GetKey() const{
	return name;
}
PList* NodeTable::GetElement() const{
	return element;
}

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
	delete[] data;	
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
	for (int i = pos; i < kol-1; i++)
	{
		data[i] = data[i + 1];
	}
	data[kol - 1] = NodeTable("",NULL);
	kol--;
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
		out<<t.GetData(i).GetKey()<<";";
	}
	return out;
}

HashTable::HashTable(){
	max_size = 10;
	row_size=1;
	flag=new int[max_size];
	for(int i=0;i<max_size;i++) 
		flag[i]=0;

	data = new NodeTable*[max_size];
	for (int i = 0; i < max_size; i++)
	{
		data[i]=new NodeTable[row_size];
	}
}

HashTable::~HashTable(){
	cout<<"сработал";
	delete []flag;
	for(int i=1;i<max_size;i++)
		delete []data[i];
	delete []data;
}


void HashTable::Mem()
{
	NodeTable** temp = new NodeTable*[max_size];
	for (int i = 0; i < max_size; i++)
	{
		temp[i]=new NodeTable[row_size+1];
	}
	for (int i = 0; i < max_size; i++)
		for(int j=0;j<row_size;j++)
			temp[i][j]=data[i][j];
	for(int i=1;i<max_size;i++)
		  delete []data[i];
	  delete []data;
	  row_size =row_size+1;
	  data = temp;
}


void HashTable::Insert(string key, PList* p)
{
	
	int hash = hashfunc(key);
	if (flag[hash]==row_size)
	{
		Mem();
	}
	if(hashfunc(data[hash][0].GetKey())==hash)
	{
		data[hash][flag[hash]]=NodeTable(key,p);
		flag[hash]++;
	}
	else{
		data[hash][0]=NodeTable(key,p);
		flag[hash]++;}
}


void HashTable::Delete(string key)
{
	int hash = hashfunc(key);
	for(int i=0;i<row_size;i++)
		if(data[hash][i].GetKey()==key)
			data[hash][i]=data[hash][flag[hash]-1];
	data[hash][flag[hash]-1]=NodeTable("",NULL);
}

PList* HashTable::GetNode(string key) {
	int hash = hashfunc(key);
	for(int i=0;i<max_size;i++)
		if(data[hash][i].GetKey()==key)
			return data[hash][i].GetElement();
	return NULL;
}


int HashTable::hashfunc(string s){
	int res=0;
	for (int i = 0; i < s.size(); i++)
		res += s[i];
	return res%max_size;
}
	
std :: ostream& operator<<(ostream &out,HashTable t){
	for (int i = 0; i < t.max_size; i++){
		for (int j = 0; j<t.getflag(i);j++)
			if((t.data[i][j].GetKey())!="")
				out<<t.data[i][j].GetKey()<<";";
		 if(t.data[i][0].GetKey()!="")
			out<<endl;
	}
	return out;
}

void HashTable::print(){
	for (int i = 0; i < this->max_size; i++){
		for (int j = 0; j<this->getflag(i);j++)
			if((this->data[i][j].GetKey())!="")
				cout<<this->data[i][j].GetKey()<<";";
		 if(this->data[i][0].GetKey()!="")
			cout<<endl;
	}
}