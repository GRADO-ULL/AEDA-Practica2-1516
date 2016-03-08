#ifndef _PILA_H
#define _PILA_H
#include <iostream>     // std::cin, std::cout
#include <string>       // std::string
#include <cctype>       // std::isdigit
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

using namespace std;

class pila
{
private:
	lista list_;
	int top_;
public:
	pila();

	~pila();
	
	void push(TDATO d);

	TDATO pop(void);

	TDATO get_top(void);

	void mostrar_pila();

	bool is_empty(void);

  void borrar(void);

  void borrar_hasta(TDATO d);

	void borrar_pila(void);

};

#endif