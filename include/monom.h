// ����� ��� ��������� ������ (coef-�����������, deg-����� ��������� �������)
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
	
	Monom (double a=0,int deg=0);									//����������� �������������
	Monom (const Monom &m);											//����������� �����������	
	~Monom();														//����������
	Monom& operator=(const Monom &m);								//������������	
	bool operator ==(const Monom &m) const;							//��������� =
	bool operator !=(const Monom &m) const;							//��������� �� �����	
	friend ostream& operator<<(ostream &out, const Monom &m);		//����� ������
};


