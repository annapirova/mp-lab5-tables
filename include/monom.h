// класс или структура Монома (coef-коэффициент, deg-целая свернутая степень)
#pragma once
#include <iostream>
#include <locale>
#include <conio.h>
#include <string>
#include <cstdio>
using namespace std;

class Monom {
public:
	double coef;
	int deg;
	
	Monom (double a=0,int deg=0);									//Конструктор инициализации
	Monom (const Monom &m);											//Конструктор копирования	
	~Monom();														//Деструктор
	Monom& operator=(const Monom &m);								//Присваивание	
	bool operator ==(const Monom &m) const;							//сравнение =
	bool operator !=(const Monom &m) const;							//сравнение не равно	
	friend ostream& operator<<(ostream &out, const Monom &m);		//вывод монома
};


