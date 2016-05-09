// ����� ������� - ������������� ����������� ������ �������
// ������������ �������� ������, ������� ������
// ����� ������, �������� ���������(������� ������������� �������), 
// ��������� ���������

#include "monom.h"
#pragma once

class PNode {						//����� �����

public:
	Monom data;						//������ ������ �����
	PNode *next;					//��������� �� ���������
	PNode();						//�����������
	PNode(const PNode &p);			//����������� �����������
	PNode(Monom m, PNode* _next);	//�������������
};





class PList {						//����� ������ ���������

public:
	PNode *head;					
	PList();						//����������� �� ���������
	~PList();						//����������
	PList(const PList &p);			//����������� �����������
	void Insert(Monom m);			//������� �����
	
	
	
	void operator=(const PList &p);	//���������� =	
	PList operator-(PList& p2);		//���������� -
	PList operator+(const PList& p2);	//���������� +
	PList operator*(const PList &p);	//���������� *
	PList multy_on_scalar(const double num); //��������� ��������� �� ������
	bool Search (const Monom &m);
	friend ostream& operator<<(ostream &out, const PList &p); ////���������� <<	
	
};

