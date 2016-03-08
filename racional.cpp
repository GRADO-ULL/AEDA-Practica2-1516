#include <iostream>
#include "racional.h"


using namespace std;

racional::racional()
{
	numerador=0;
	denominador=1;
}

racional::racional(d_racional num_,d_racional den_)
{
	numerador = num_;
	if(den_!=0)
		denominador = den_;
}
racional::~racional()
{
	numerador = 0;
	denominador = 0;
}

d_racional racional::get_numerador(void)
{
	return numerador;
}

d_racional racional::get_denominador(void)
{
	return denominador;
}

void racional::set_numerador(d_racional num_)
{
	numerador = num_;
}

void racional::set_denominador(d_racional den_)
{
	if(den_!=0)
		denominador = den_;
}

d_racional racional::denominador_comun(d_racional a,d_racional b)
{
	if((a % b) == 0)
		return a;
	if((b % a) == 0)
		return b;
	if(((a % b) != 0) && ((b % a)!=0))
	{
		return a*b;
	}

}
racional& racional::operator+(const racional &rac_)
{
	d_racional num_;
	d_racional den_;
	den_=denominador_comun(rac_.denominador,denominador);

	return *(new racional((den_/rac_.denominador)*rac_.numerador + (den_/denominador)*numerador,den_));
}

racional& racional::operator-(const racional &rac_)
{
	d_racional num_;
	d_racional den_;
	den_=denominador_comun(rac_.denominador,denominador);
	return *(new racional((den_/denominador)*numerador - (den_/rac_.denominador)*rac_.numerador,den_));
}

racional& racional::operator*(const racional &rac_)
{
	return *(new racional(numerador * rac_.numerador,denominador * rac_.denominador));
}

racional& racional::operator/(const racional &rac_)
{
	return *(new racional(numerador * rac_.denominador,denominador * rac_.numerador));
}

bool racional::operator==(const racional &rac_)
{
	if((rac_.numerador == numerador) && (rac_.denominador == denominador))
		return true;
	else
	{
		return false;
	}
}

bool racional::operator<(const racional &rac_)
{

	bool comprobar = false;
	bool comprobar1= false;
	if(numerador > denominador)
	{
		comprobar = true;
	}
	if(rac_.numerador > rac_.denominador)
	{
		comprobar1 = true;
	}
	if(((comprobar == true)&&(comprobar1 == true))||((comprobar == false)&&(comprobar1==false)))
	{
			if(denominador == rac_.denominador)
			{

				if(numerador < rac_.numerador)
					return true;
				else
					return false;
			}
			else
			{
				d_racional den_;
				den_=denominador_comun(denominador,rac_.denominador);
				if(((den_ / denominador) * numerador) < ((den_ / rac_.denominador) * rac_.numerador))
					return true;
				else
					return false;
			}

	}
	else
	{
		if(comprobar == true && comprobar1 == false)
			return false;
		if(comprobar == false && comprobar1 == true)
			return true;
	}
}

bool racional::operator>(const racional &rac_)
{
	bool comprobar = false;
	bool comprobar1= false;
	if(numerador > denominador)
		comprobar = true;
	if(rac_.numerador > rac_.denominador)
		comprobar1 = true;
	if(((comprobar == true)&&(comprobar1 == true))||((comprobar == false)&&(comprobar1==false)))
	{
			
			if(denominador == rac_.denominador)
			{
				if(numerador > rac_.numerador)
					return true;
				else
				{

					return false;
				}
			}
			else
			{
				d_racional den_;
				den_=denominador_comun(denominador,rac_.denominador);
				if(((den_ / denominador) * numerador) > ((den_ / rac_.denominador) * rac_.numerador))
					return true;
				else
					return false;
			}
	}
	else
	{
		if(comprobar == true && comprobar1 == false)
			return true;
		if(comprobar == false && comprobar1 == true)
			return false;
	}	
}

ostream& operator<<(ostream& salida_pantalla,const racional &rac_)
{
	//rac_.minimizo();
	salida_pantalla << rac_.numerador << "/" << rac_.denominador << endl;
	return salida_pantalla;
}

istream& operator>>(istream& entrada_pantalla,racional &rac_)
{
	char caracter;
	entrada_pantalla >> rac_.numerador;
	entrada_pantalla >> caracter;
	entrada_pantalla >> rac_.denominador;
	return entrada_pantalla;
}

/*
void racional::minimizo(void)
{
	int maximo = mcd(numerador,denominador);
	set_numerador(numerador/maximo);
	set_denominador(denominador/maximo);
}

d_racional racional::mcd(d_racional num_,d_racional den_)
{
	while(num_!=den_)
	{
		if(num_>den_)
			num_=num_-den_;
		else
			den_=den_-num_;
	}
	return num_;
}*/
