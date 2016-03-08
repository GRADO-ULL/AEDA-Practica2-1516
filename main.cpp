#include <iostream>     // std::cin, std::cout
#include <string>       // std::string
#include <cctype>       // std::isdigit
#include <stdio.h>
#include <stdlib.h>
#include "complejo.h"
#include "racional.h"
#include "pila.h"

using namespace std;

typedef int TDATO; 

int main () {

  pila p1;
  cout << "Introduzca expresion regular: ";
  cout.flush();    // ensure output is written

while(cin.peek() != EOF && cin.peek() != '\n')
{
  cin >> std::ws;  // eat up any leading white spaces
  TDATO c = cin.peek();  // peek character
  cout << "Peek->" << cin.peek() << endl;
  
  if (isdigit(c) )
  {
    TDATO n;
    cin >> n;
    cout << "Ha introducido un digito " << n << '\n';
    p1.push(n);
  }
  else
  {
    char str;
    cin >> str;
    if(!isdigit(cin.peek()))
    {
        cout << "Str->" << str << endl;

        cout << "Ha introducido un operando: " << str << '\n';
        switch(str)
        {
            case '+':
                { 
                    TDATO auxiliar = 0;
                    //cout << "Sumando" << endl;
                    //cout << "Auxiliar-> " << auxiliar << endl;
                    int i=0;
                    while(i<2)
                    {
                        auxiliar += p1.pop();
                        //cout << "Auxiliar-> " << auxiliar << endl;
                        i++;
                    }
                    p1.push(auxiliar);
                    p1.mostrar_pila();
                    break;
                }
            case '-':
                {
                    TDATO auxiliar = 0;
                    //cout << "Restando" << endl;
                    //cout << "Auxiliar-> " << auxiliar << endl;
                    int i=0;
                    if(!p1.is_empty())
                    {
                    while(i<2)
                        {
                            auxiliar = p1.pop() - auxiliar;
                            i++; 
                        }
                    p1.push(auxiliar);
                    }
                break;
                }
            case '*':
                {
                    TDATO auxiliar = 1;
                    //cout << "Multiplicando..." << endl;
                    //cout << "Auxiliar->" << auxiliar  << endl;
                    int i=0;
                    while(i<2)
                    {
                        auxiliar = p1.pop() * auxiliar;
                       // cout << "Auxiliar->" << auxiliar << endl;
                        i++;
                    }
                    p1.push(auxiliar);
                break;
                }
            case '/':
                {
                    TDATO auxiliar = 1;
                    //cout << "Dividiendo..." << endl;
                    auxiliar = p1.pop();
                    auxiliar = p1.pop() / auxiliar;
                    p1.push(auxiliar);
                }
                break;
            default:
                cout << "Operando no descubierto..." << endl;
        }
    }
    else
    {
        if(str == '-')
        {
           TDATO c = cin.peek();  // peek character
           cout << "Peek->" << cin.peek() << endl;
          
            if (isdigit(c) )
            {
             TDATO n;
             cin >> n;
             n = -n;
             cout << "Ha introducido un digito " << n << '\n';
             p1.push(n);
            }
        }
    }
  }
}

  cout << "Resultado: " << endl;
  p1.mostrar_pila();
  
  cout << endl;
  return 0;
}