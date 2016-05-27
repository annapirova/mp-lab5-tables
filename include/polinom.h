// класс Полином - упорядоченный односвязный список Мономов
// поддерживает операции Печать, Вставка монома
// Поиск монома, Сложение полиномов(слияние упорядоченных списков), 
// Умножение полиномов

#include "monom.h"
#pragma once

class PNode {						//Класс звено

public:
	Monom data;						//данные одного звена
	PNode *next;					//указатель на следующий
	PNode();						//Конструктор
	PNode(const PNode &p);			//Конструктор Копирования
	PNode(Monom m, PNode* _next);	//Инициализация
};





class PList {						//Класс список полиномов

public:
	PNode *head;					
	PList();						//Конструктор по умолчанию
	~PList();						//Деструктор
	PList(const PList &p);			//Конструктор копирования
	void Insert(Monom m);			//Вставка звена
	
	
	
	void operator=(const PList &p);	//Перегрузка =	
	PList operator-(PList& p2);		//Перегрузка -
	PList operator+(const PList& p2);	//Перегрузка +
	PList operator*(const PList &p);	//Перегрузка *
	PList multy_on_scalar(const double num); //Перегузка умножения на скаляр
	bool Search (const Monom &m);
	friend ostream& operator<<(ostream &out, const PList &p); ////Перегрузка <<	
	
};

