#include <iostream>     // std::cin, std::cout
#include <string>       // std::string
#include <cctype>       // std::isdigit
#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

using namespace std;

pila::pila()
{
	list_;
	top_=-1;
}

pila::~pila()
{
	if(list_.is_empty() != true)
	{
		while(list_.is_empty())
		{
			pop();
		}
	}
}

void pila::push(int d)
{
	list_.insertar_final(d);
	top_++;
}

TDATO pila::pop(void)
{
	int res =0;

	res = list_.extraer_final();

	top_--;
	return res;
}

TDATO pila::get_top(void)
{
	return top_;
}

void pila::mostrar_pila()
{
	if(is_empty()==true)
		cout << "Pila vacia"<<endl;
	else
		list_.mostrar_lista();

}

bool pila::is_empty(void)
{
	if(top_==-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void pila::borrar(void)
{
    if(is_empty() == true)
    {
      cout << "La lista esta vacia..." << endl;
    }
    else
    {
      while(is_empty() != true)
      {
        pop();
      }
    }
}

void pila::borrar_hasta(TDATO d)
{
    if(is_empty() == true)
    {
      cout << "La pila esta vacia..." << endl;
    }
    else
    {
      TDATO auxiliar = pop();
      while(auxiliar != d)
      {
        auxiliar = pop();
      }
    }
}

void pila::borrar_pila(void)
{
    if(is_empty()==true)
		cout << "Pila vacia"<<endl;
	else
	{
        while(is_empty() == true)
        {
            pop();
        }
	}
}

