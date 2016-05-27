#include "monom.h"

Monom :: Monom(double _coef, int _deg)//����������� �������������
{
		coef = _coef;
		deg = _deg;
}




Monom::~Monom(){};

Monom::Monom (const Monom &m)
{
	coef=m.coef;
	deg=m.deg;
}

Monom& Monom::operator=(const Monom &m)
{
	if(this == &m)
		return *this;
	else
	{
		coef=m.coef;
		deg=m.deg;
		return *this;
	}
}
bool Monom :: operator ==(const Monom &m) const  // ���������
{
	if((m.coef==coef)||(m.deg==deg))
		return true;
	else 
		return false;
}
bool Monom :: operator !=(const Monom &m) const  // ���������
{
	if((m.coef!=coef)||(m.deg!=deg))
		return true;
	else 
		return false;
}

std::ostream& operator<<(ostream &out, const Monom &m)
  {
	  out << '(' << m.coef << ';' << m.deg << ')'<<endl;
	  return out;
  }


