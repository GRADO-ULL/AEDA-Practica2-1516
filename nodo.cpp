#include <iostream>     // std::cin, std::cout
#include <string>       // std::string
#include <cctype>       // std::isdigit
#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"

using namespace std;

nodo::nodo()
{
  siguiente = NULL;
}

nodo::~nodo()
{
  siguiente = NULL;
}

nodo::nodo(TDATO d)
{
    dato = d;
    siguiente = NULL;
}

nodo::nodo(TDATO d,nodo* sig)
{
    dato = d;
    siguiente = sig;
}

TDATO nodo::get_dato(void)
{
    return dato;
}

void nodo::set_dato(TDATO d)
{
    dato = d;
}

void nodo::set_siguiente(nodo* next)
{
   siguiente = next;
}

nodo* nodo::get_siguiente(void)
{
    return siguiente;
}
