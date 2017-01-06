#include "Nodo_Arbol.h"


template<class T>
class Arbol{
private:
	Nodo_Arbol<T>* raiz;
public:
	Arbol();
	~Arbol();
	void set_DatoRaiz(T*);
	Nodo_Arbol<T>* getRaiz()const;
	string datos_borde();
	void intercambia_Nodos(int,int);
	int cant_niveles0();
	Nodo_Arbol<T>* getNodo_X_0(int);
};

template<class T>
Arbol<T>::Arbol()
{
}

template<class T>
Arbol<T>::~Arbol(){}

template<class T>
void Arbol<T>::set_DatoRaiz(T *raiz1)
{
	this->raiz=new Nodo_Arbol<T>(raiz1);
}

template<class T>
Nodo_Arbol<T>* Arbol<T>::getRaiz() const
{
	return this->raiz;
}

template<class T>
string Arbol<T>::datos_borde()
{
	stringstream datos;
	Nodo_Arbol<T>* act;
	act=this->raiz;
	for(int i=1;i<cant_niveles0();i++)
	{
		datos<<i<<": "<<*act->getDato()<<"\n";
		act=act->getPuntero_0();
	}
	return datos.str();
}

template<class T>
void Arbol<T>::intercambia_Nodos(int p1,int p2)
{
	Nodo_Arbol<T>* aux1=this->getNodo_X_0(p1);
	Nodo_Arbol<T>* aux2=this->getNodo_X_0(p2);
	Nodo_Arbol<T>* aux1_next;
	Nodo_Arbol<T>* aux1_prev;
	Nodo_Arbol<T>* aux2_prev;
	Nodo_Arbol<T>* aux2_next;

	if(p1!=1 && p1!=p2-1)
	{
		aux1_next=aux1->getPuntero_0();
		aux1_prev=this->getNodo_X_0(p1-1);
		aux2_prev=this->getNodo_X_0(p2-1);
		aux1->setPuntero_0(aux2->getPuntero_0());
		aux2->setPuntero_0(aux1_next);
		aux1_prev->setPuntero_0(aux2);
		aux2_prev->setPuntero_0(aux1);
	}
	if(p1!=1 && p1==p2-1)
	{	
		aux1_prev=this->getNodo_X_0(p1-1);
		aux2_next=aux2->getPuntero_0();
		aux1_prev->setPuntero_0(aux2);
		aux2->setPuntero_0(aux1);
		aux1->setPuntero_0(aux2_next);
	}

	if(p1==1 && p1!=p2-1)
	{
		aux2_prev=this->getNodo_X_0(p2-1);
		aux2_next=aux2->getPuntero_0();
		aux1_next=aux1->getPuntero_0();
		aux2->setPuntero_0(aux1_next);
		aux2_prev->setPuntero_0(aux1);
		aux1->setPuntero_0(aux2_next);
		this->raiz=aux2;
	}

	if(p1==1 && p2==2)
	{
		aux2_next=aux2->getPuntero_0();
		aux2->setPuntero_0(aux1);
		aux1->setPuntero_0(aux2_next);
		this->raiz=aux2;
	}	
}

template<class T>
int Arbol<T>::cant_niveles0()
{
	int i=0;
	Nodo_Arbol<T>* act;
	act=raiz;
	for(i;act!=NULL;i++)
		act=act->getPuntero_0();
	return i;
}

template<class T>
Nodo_Arbol<T>* Arbol<T>::getNodo_X_0(int t)
{
	Nodo_Arbol<T>* act=raiz;
	for(int i=1;i<=cant_niveles0();i++)
	{
		if(i==t)
		{
			return act;
		}
		act=act->getPuntero_0();
	}
	return NULL;
}