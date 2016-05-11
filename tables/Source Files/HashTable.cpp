#include "tables.h"

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
	//cout<<"сработал";
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