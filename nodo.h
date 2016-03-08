#ifndef _NODO_H
#define _NODO_H
#include <iostream>     // std::cin, std::cout
#include <string>       // std::string
#include <cctype>       // std::isdigit
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef int TDATO;

class nodo
{
private:
  TDATO dato;
  nodo* siguiente;
public:
  nodo();
  ~nodo();
  nodo(TDATO d);
  nodo(TDATO d, nodo* sig);
  TDATO get_dato(void);
  void set_dato(TDATO d);
  void set_siguiente(nodo* next);
  nodo* get_siguiente(void);
};

#endif