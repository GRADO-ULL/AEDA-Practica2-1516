#include <iostream>
#include "complejo.h"

using namespace std;


complejo::complejo()
{
	real = 0;
	imaginaria = 0;
	signo = false;
}

complejo::complejo(d_complejo real_,d_complejo imaginaria_)
{
	real = real_;
	imaginaria = imaginaria_;
}

complejo::~complejo()
{
	real = 0;
	imaginaria = 0;
}

d_complejo complejo::get_real(void)
{
	return real;
}

d_complejo complejo::get_imaginaria(void)
{
	return imaginaria;
}	

void complejo::set_real(d_complejo real_)
{
	real = real_;
}

void complejo::set_imaginaria(d_complejo imaginaria_)
{
	imaginaria = imaginaria_;
}

//operadores
complejo& complejo::operator+(const complejo &complejo_)
{
	return *(new complejo(real+complejo_.real, imaginaria + complejo_.imaginaria));
}

complejo& complejo::operator-(const complejo &complejo_)
{
	return *(new complejo(real-complejo_.real, imaginaria - complejo_.imaginaria));
}

complejo& complejo::operator*(const complejo &complejo_)
{
	return *(new complejo(real*complejo_.real,imaginaria*complejo_.imaginaria));
}

complejo& complejo::operator/(const complejo &complejo_)
{
	return *(new complejo(real/complejo_.real,imaginaria/complejo_.imaginaria));
}


ostream& operator<<(ostream &salida_pantalla, const complejo &complejo_)
{
	salida_pantalla << complejo_.real;
	salida_pantalla << "+";
	salida_pantalla << complejo_.imaginaria;
	salida_pantalla << "i";
	return salida_pantalla;
}
istream& operator>>(istream &entrada_pantalla, complejo &complejo_)
{
	char signo;
	entrada_pantalla >> complejo_.real;
	entrada_pantalla >> signo;
	if(signo == '+')
		complejo_.signo = true;
	else
		complejo_.signo = false;
	entrada_pantalla >> complejo_.imaginaria;
	entrada_pantalla >> complejo_.variable_imaginaria;
	return entrada_pantalla;
}