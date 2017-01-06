#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;


template<class T>
class Nodo_Arbol{
private:
	Nodo_Arbol<T>* punt_0;
	Nodo_Arbol<T>* punt_1;
	T* dato;
	bool Hoja;//es hoja?
public:
	Nodo_Arbol(T*);
	Nodo_Arbol(T*,bool);
	~Nodo_Arbol();
	T* getDato() const;
	void setPuntero_0(Nodo_Arbol<T>*);
	void setPuntero_1(Nodo_Arbol<T>*);
	Nodo_Arbol<T>* getPuntero_0();
	Nodo_Arbol<T>* getPuntero_1();
	bool getHoja();
	friend ostream & operator << (ostream & salida,Nodo_Arbol<T>& nd)
	{
		salida<<(*nd.dato)<<"\n"<< nd.Hoja;
		return salida;
	}

	friend istream & operator >> (istream & entrada,Nodo_Arbol<T>& nd)
	{
		entrada>> (*nd.dato) >> nd.Hoja;
		return entrada;
	}
};

template<class T>
Nodo_Arbol<T>::Nodo_Arbol(T* info,bool h):punt_0(NULL),punt_1(NULL),dato(info),Hoja(h){}

template<class T>
Nodo_Arbol<T>::Nodo_Arbol(T* info):punt_0(NULL),punt_1(NULL),dato(info),Hoja(false){}

template<class T>
Nodo_Arbol<T>::~Nodo_Arbol(){}

template<class T>
T* Nodo_Arbol<T>::getDato() const
{
	return dato;
}

template<class T>
Nodo_Arbol<T>* Nodo_Arbol<T>::getPuntero_0()
{
	return this->punt_0;
}

template<class T>
Nodo_Arbol<T>* Nodo_Arbol<T>::getPuntero_1()
{
	return this->punt_1;
}

template<class T>
void Nodo_Arbol<T>::setPuntero_0(Nodo_Arbol<T>* nd)
{
	this->punt_0=nd;
}

template<class T>
void Nodo_Arbol<T>::setPuntero_1(Nodo_Arbol<T>* nd)
{
	this->punt_1=nd;
}

template<class T>
bool Nodo_Arbol<T>::getHoja()
{
	return this->Hoja;
}