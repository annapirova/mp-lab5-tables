#include "polinom.h"

PNode::PNode() 
{							//Конустрктор по умолчанию	
	data=Monom();
	next=NULL;
}
				
PNode::PNode(const PNode &p)				//Конструктор копирования
{
	data=p.data;
	next=p.next;
}

PNode::PNode(Monom m,PNode* _next)			//Инициализация звена
{
	data=m;
	next=_next;
}


PList :: PList ()							//Конструктор по умолчанию
{
	head = new PNode;
}

PList :: PList(const PList &p)				//Конструктор копирования
{
	PNode *tmpA;
	PNode *tmpB;
	head = new PNode;
	tmpA= head;
	tmpB = p.head->next;

	while (tmpB != NULL)
	{
		tmpA->next = new PNode (tmpB->data, NULL);
		tmpA = tmpA->next;
		tmpB = tmpB->next;
	}
}

void PList:: operator =(const PList &p)		// Присваивание
{
	PNode *tmp1;
	PNode *tmp2;
	PNode *tmp;
	if (this->head!=p.head)
	{
		tmp = this->head->next;
		while (tmp!=NULL)
		{
			PNode *Del = tmp;
			tmp=tmp->next;
			delete Del;
		}
		tmp1=this->head;
		tmp2=p.head->next;

		while (tmp2 != NULL)
		{
			tmp1->next = new PNode (tmp2->data, NULL);
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
		}
	}

}


PList ::~PList()
{
	PNode *tmp;
	tmp = this->head->next;
	while (tmp!=NULL)
	{
		PNode *tmp2 = tmp;
		tmp=tmp->next;
		delete tmp2;
	}
	delete	head;
}

void PList::Insert (Monom m)
{	
	PNode *temp,*prev;
	prev=NULL;
	temp = head;
	int pow = 0;

	while ((temp->next != NULL) && (temp->next->data.deg <= m.deg))
	{
		prev=temp;
		temp = temp->next;
		pow = temp->data.deg;

	}
	if( pow == m.deg)
	{
		if (abs(temp->data.coef + m.coef)>1e-10)
			temp->data.coef = temp->data.coef + m.coef;
		else
		{
			prev->next=temp->next;
			delete temp;
		}
	}
	else if (abs(m.coef) > 1e-10)
	{
			temp->next = new PNode(m, temp->next);	
	}
}




PList PList  :: operator+(const PList &p2)
{
	PList C;
	PNode *tempA = this->head->next;
	PNode *tempB = p2.head->next;
	PNode *tempC =C.head;

	while ((tempA != NULL) && (tempB != NULL))
	{
		if (tempA->data.deg < tempB->data.deg) 
		{
			tempC->next = new PNode(tempA->data,NULL);
			tempA = tempA->next;
			tempC = tempC->next;
		}
		else if (tempA->data.deg > tempB->data.deg) 
		{
			tempC->next = new PNode(tempB->data, NULL);
			tempB = tempB->next;
			tempC = tempC->next;
		}
		else if (abs(tempA->data.coef + tempB->data.coef)> 1e-10)
		{
			double _coef=tempA->data.coef + tempB->data.coef;
			int _deg=tempA->data.deg;
			Monom m(_coef,_deg);
			tempC->next = new PNode(m, NULL);

			tempA = tempA->next;
			tempB = tempB->next;
			tempC= tempC->next;
		}		
		else
		{
			tempA=tempA->next;
			tempB=tempB->next;
		}
	}
	while (tempA!=NULL)
	{
		tempC->next=new PNode(tempA->data , NULL);
		tempA=tempA->next;
		tempC=tempC->next;
	}
	while (tempB!=NULL)
	{
		tempC->next=new PNode(tempB->data , NULL);
		tempB=tempB->next;
		tempC=tempC->next;
	}
	return C;
}




PList PList  :: operator-(PList &p)
{
	PList C1, C2;
	C1=p.multy_on_scalar(-1);
	C2=C1+*this;
	return C2;
}

PList PList :: operator*(const PList &p2) //умножение полиномов
{
	PList C;
	PNode *tempA=this->head->next;
	PNode *tempB=p2.head->next;
	double coef;
	int deg=0;

	while (tempA!=NULL) 
	{
		tempB=p2.head->next;
		while (tempB!=NULL)
		{
			if(((tempA->data.deg)/100+(tempB->data.deg)/100)>9||((tempA->data.deg)%10+(tempB->data.deg)%10)>9 || (((tempA->data.deg)/10)%10+((tempB->data.deg)/10)%10)>9 || deg<0)
			{
				throw "Ошибка, степень одной из переменных больше 9, возвращается первый множитель";
				return *this;
			}
			coef =(tempA->data.coef)*(tempB->data.coef);
			deg = tempA->data.deg + tempB->data.deg; 
			C.Insert(Monom(coef,deg));
			tempB=tempB->next;

		}
		tempA=tempA->next;
	}
	return C;
}

PList PList:: multy_on_scalar(const double num)
{
	PList C;
	PNode *temp =this->head->next; 
	PNode *tmp=C.head;
	while(temp != NULL)
	{
		tmp->next = new PNode(Monom(temp->data.coef*num,temp->data.deg),NULL);
		tmp=tmp->next;
		temp=temp->next;
	}
	return C;
}

bool PList ::Search (const Monom &m)			//поиск монома
{
	int flag=0;
	PNode *temp;
	temp=this->head;
	while(temp->next!=NULL)
	{
		if(temp->next->data!=m)
		{
			temp=temp->next;
		}
		else if(temp->next->data==m)
		{
			flag=1;
			break;
		}
	}
	if (flag==1)
		return true;
	else 
		return false;
}


std :: ostream& operator<<(ostream &out, const PList &p) // вывод
{
	PNode *temp =p.head->next;
	while(temp != NULL)
	{
		out << "(" << temp->data.coef << "; " << temp->data.deg << ")" << endl; 
		temp=temp->next;
	}
	return out;	
}
