#ifndef _LISTA_H
#define _LISTA_H
#include <iostream>     // std::cin, std::cout
#include <string>       // std::string
#include <cctype>       // std::isdigit
#include <stdio.h>
#include <stdlib.h> 
#include "nodo.h"

using namespace std;

class lista
{
private:
  nodo* inicio;
  nodo* final;
public:
  lista();

  lista(nodo* ini);

  ~lista();
  
  bool is_empty(void);

  void insertar_final(TDATO d);

  void insertar_principio(TDATO d);

  int extraer_inicio(void);

  int extraer_final(void);

  int* borrar_hasta(TDATO d);

  void borrar_todo(void);

  void mostrar_lista(void);

};

#endif