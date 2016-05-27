#pragma once
#include "polinom.h"

using namespace std;

class NodeTable {
private:					
	string name;			//ключ
	PList *element;			//полином
public:
	NodeTable();
	NodeTable(const NodeTable &t);
	NodeTable(string name_, PList* elem);
	string GetKey() const;
	PList* GetElement() const;
	NodeTable& operator=(NodeTable &t);
	bool operator==(const NodeTable &t);

};

class Table
{
public:	
	virtual int Find(string key) = 0;
	virtual void Insert(string key, PList *p) = 0;
	virtual void Delete(string key) = 0;
	virtual PList* GetNode(string key) = 0 ;
};

class SortedTable: public Table
{
private:
	int kol;			//текущая позиция
	int max_size;		//размер таблицы
	NodeTable* data;
	bool IsFull();
	void SortedAdd(string key, PList *p);
	void Mem();
	int Find(string key);
public:
	int search(string key){return Find(key);} //для тестов
	SortedTable();
	~SortedTable();
	int GetKol(){return kol;}
	int GetMaxSize(){return max_size;}
	void Insert(string key, PList *p);
	void Delete(string key);
	PList* GetNode(string key);
	NodeTable GetData(int pos){return data[pos];}
	friend ostream& operator<<(ostream &out, SortedTable t);
};


class HashTable:public Table 
{
public:
	NodeTable **data;
	int max_size;
	int row_size;
	int *flag;								//в каждом элементе массива хранится длина цепочки для определенного
	int getflag(int pos){return flag[pos];}
	int hashfunc(string s);
	int Find(string key) { return 0; }
	HashTable();
	~HashTable();
	void Mem();
	void Insert(string key, PList *p);
	void Delete(string key);
	PList* GetNode(string key);
	friend ostream& operator<<(ostream &out,HashTable t);
	void print();
};

