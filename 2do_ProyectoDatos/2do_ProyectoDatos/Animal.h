#include <iostream>
#include <ostream>
#include <string>

using namespace std;

class Animal{
private:
	string nombre;
public:
	Animal(string="");
	~Animal();
	void setNombre(string);
	string getNombre();
	friend ostream & operator << (ostream& salida,const Animal& an);
	friend istream & operator >> (istream& entrada,Animal& an);
};

Animal::Animal(string n):nombre(n){}

Animal::~Animal(){}

void Animal::setNombre(string n)
{
	this->nombre=n;
}

string Animal::getNombre()
{
	return this->nombre;
}

ostream & operator << (ostream& salida,const Animal& an)
{
	salida<<an.nombre<<"\n";
	return salida;
}

istream & operator >> (istream& entrada,Animal& an)
{
	getline(entrada,an.nombre,'\n');
	return entrada;
}
