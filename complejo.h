#include <iostream>

using namespace std;

typedef float d_complejo;

class complejo
{

friend ostream& operator<<(ostream &salida_pantalla, const complejo &complejo_);
friend istream& operator>>(istream &entrada_pantalla, complejo &complejo_);
private:
	d_complejo real;
	d_complejo imaginaria;
	bool signo;
	char variable_imaginaria;

public:
	complejo();
	complejo(d_complejo real_,d_complejo imaginaria_);
	~complejo();
	d_complejo get_real(void);
	d_complejo get_imaginaria(void);
	void set_real(d_complejo real_);
	void set_imaginaria(d_complejo imaginaria_);
	//operadores
	complejo& operator+(const complejo &complejo_);
	complejo& operator-(const complejo &complejo_);
	complejo& operator*(const complejo &complejo_);
	complejo& operator/(const complejo &complejo_);
};