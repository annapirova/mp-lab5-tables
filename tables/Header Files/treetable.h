#pragma once	
#include "polinom.h"
using namespace std;

class NodeTree 
{
	public:
		string key;											//ключ
		PList *poly;										//данные
		NodeTree *Left;										//укаатель на левого потомка
		NodeTree *Right;									//указатель на правого потомка
		NodeTree *Parent;									//указатель на родителя
		NodeTree();											//конструктор инициализации
		NodeTree(const NodeTree &t);						//конструктор копирования				 
		~NodeTree ();										//деструктор
		NodeTree& operator=(const NodeTree &t);				//оператор присваивания
		bool operator==(const NodeTree &t);					//оператор сравнения
		friend ostream& operator<<(ostream &out, const NodeTree &t); // вывод
};

class TreeTable
{
	public:
		NodeTree * root;								//корень дерева
		TreeTable ();									//конструктор инициализатор
		~TreeTable();									//деструктор
		NodeTree* Find(NodeTree * curr, string key);    //поиск записи
		NodeTree * SearchMin(NodeTree * root);			//поиск минимума(самый левый в дереве)	
		NodeTree * SearchMax(NodeTree * root);			//поиск максимума(самый правый в дереве)
		NodeTree * SearchNext(NodeTree * root);			//поиск следующего по ключу(минимум в правом поддереве)
		NodeTree * SearchPrev(NodeTree * root);			//поиск предыдущего по ключу(максимум в левом поддереве)
		void Insert (NodeTree &t);                      //вставка в дерево
		void Delete (string key);						//удаление
		bool IsEmpty();									//пусто ли дерево
		void Print(NodeTree *curr);						//вывод
};

