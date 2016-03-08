#include <iostream>

using namespace std;
typedef int d_racional;

class racional
{
friend ostream& operator<<(ostream& salida_pantalla,const racional &rac_);
friend istream& operator>>(istream& entrada_pantalla,racional &rac_);

private:
	d_racional numerador;
	d_racional denominador;
public:
	racional();
	racional(d_racional num_,d_racional den_);
	~racional();
	d_racional get_numerador(void);
	d_racional get_denominador(void);
	void set_numerador(d_racional num_);
	void set_denominador(d_racional dem_);
	d_racional denominador_comun(d_racional a,d_racional b);
	//d_racional mcd(d_racional num_,d_racional den_);
	//void minimizo(void);
	//operadores
	racional& operator+(const racional &rac_);
	racional& operator-(const racional &rac_);
	racional& operator*(const racional &rac_);
	racional& operator/(const racional &rac_);
	bool operator==(const racional &rac_);
	bool operator<(const racional &rac_);
	bool operator>(const racional &rac_);
};