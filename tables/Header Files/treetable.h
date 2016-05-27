#pragma once	
#include "polinom.h"
using namespace std;

class NodeTree 
{
	public:
		string key;											//����
		PList *poly;										//������
		NodeTree *Left;										//�������� �� ������ �������
		NodeTree *Right;									//��������� �� ������� �������
		NodeTree *Parent;									//��������� �� ��������
		NodeTree();											//����������� �������������
		NodeTree(const NodeTree &t);						//����������� �����������				 
		~NodeTree ();										//����������
		NodeTree& operator=(const NodeTree &t);				//�������� ������������
		bool operator==(const NodeTree &t);					//�������� ���������
		friend ostream& operator<<(ostream &out, const NodeTree &t); // �����
};

class TreeTable
{
	public:
		NodeTree * root;								//������ ������
		TreeTable ();									//����������� �������������
		~TreeTable();									//����������
		NodeTree* Find(NodeTree * curr, string key);    //����� ������
		NodeTree * SearchMin(NodeTree * root);			//����� ��������(����� ����� � ������)	
		NodeTree * SearchMax(NodeTree * root);			//����� ���������(����� ������ � ������)
		NodeTree * SearchNext(NodeTree * root);			//����� ���������� �� �����(������� � ������ ���������)
		NodeTree * SearchPrev(NodeTree * root);			//����� ����������� �� �����(�������� � ����� ���������)
		void Insert (NodeTree &t);                      //������� � ������
		void Delete (string key);						//��������
		bool IsEmpty();									//����� �� ������
		void Print(NodeTree *curr);						//�����
};

