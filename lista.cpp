#include <iostream>     // std::cin, std::cout
#include <string>       // std::string
#include <cctype>       // std::isdigit
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

using namespace std;

  lista::lista()
  {
    inicio = NULL;
    final = NULL;
  }
  lista::lista(nodo* ini)
  {
    inicio = ini;
    final = ini;
  }
  lista::~lista()
  {
    inicio = NULL;
    final = NULL;
  }
  bool lista::is_empty(void)
  {
    if((inicio == final) && (inicio == NULL) && (final == NULL))
    {
        return true;
    }
    else
    {
        return false;
    }
  }
  void lista::insertar_final(TDATO d)
  {
    nodo* nd = new nodo(d);
    if(is_empty() == true)
    {
      inicio = nd;
      final = nd;
    }
    else
    {
      final->set_siguiente(nd);
      final = nd;
    }
  }
  void lista::insertar_principio(TDATO d)
  {
    nodo* nd = new nodo(d);
    if(is_empty() == true)
    {
      inicio = nd;
      final = nd;
    }
    else
    {
      nd->set_siguiente(inicio);
      inicio = nd;
    }
  }

  TDATO lista::extraer_inicio(void)
  {
    TDATO res=0;
    if(is_empty() != true)
    {
      if(inicio==final)
      {
        res=inicio->get_dato();
        inicio->set_siguiente(NULL);
        inicio=NULL;
        final=NULL;
      }
      else
      {
        res = inicio->get_dato();
        nodo* auxiliar = inicio;
        inicio=inicio->get_siguiente();
        delete auxiliar;
      }
    }
    return res;
  }

  TDATO lista::extraer_final(void)
  {
    TDATO res=0;
    if(is_empty() != true)
    {
      if(inicio==final)
      {
        res=inicio->get_dato();
        inicio->set_siguiente(NULL);
        inicio=NULL;
        final=NULL;
      }
      else
      {
        res = final->get_dato();
        nodo* auxiliar=inicio;
        while(auxiliar->get_siguiente()!=final)
        {
          auxiliar=auxiliar->get_siguiente();
        }
        if(auxiliar->get_siguiente()==final)
        {
          final=auxiliar;
          auxiliar=auxiliar->get_siguiente();
          final->set_siguiente(NULL);
          delete auxiliar;
        }
      }
    }
    return res;
  }

  TDATO* lista::borrar_hasta(TDATO d)
  {
    if(is_empty() != true)
    {
      if(inicio == final)
      {
        if(inicio->get_dato() == d)
        {
          inicio->set_siguiente(NULL);
          inicio = NULL;
          final = NULL;
        }
      }
      else
      {
        nodo* auxiliar = new nodo();
        while(inicio->get_dato()!=d)
        {
          auxiliar=inicio;
          inicio=inicio->get_siguiente();
          auxiliar->set_siguiente(NULL);
          delete auxiliar;
        }
      }
    }
  }

  void lista::borrar_todo(void)
  {
      nodo* auxiliar = new nodo();
      if(is_empty() != true)
      {
        while(inicio!=NULL)
        {
          auxiliar=inicio;
          inicio=inicio->get_siguiente();
          auxiliar->set_siguiente(NULL);
          delete auxiliar;
        }
      }
  }

  void lista::mostrar_lista(void)
  {
    nodo* auxiliar;
    auxiliar=inicio;
    if(inicio==NULL)
    {
      cout << "Lista vacia"<< endl;
    }
    else
    {
      while(auxiliar!=NULL)
      {
        cout << auxiliar->get_dato();
        if(auxiliar->get_siguiente() != NULL)
        {
          cout << ",";
        }
        auxiliar = auxiliar->get_siguiente();
      }
    }
  }
