#include"Arbol.h"
#include "Animal.h"
#include<fstream>
#include<sstream>

using namespace System;

class Controladora{
public:
	Arbol<Animal> MundoAnimales;	

	Controladora(void);
	~Controladora(void);

	void iniciar();
	void fin();
	Nodo_Arbol<Animal>* getRaiz();
	string datos_borde();
	void recorreArbol(Nodo_Arbol<Animal> &);
	void intercambia_niveles(int,int);
	int cantidad_niveles0();
	void cargarArbol(Nodo_Arbol<Animal> &,ifstream &Archivo);//Este metodo carga el Arbol de un documento de Texto.
	void guardarArbol(Nodo_Arbol<Animal> &,ofstream &Archivo);//Este metodo guarda el Arbol despues de terminar el programa.
	void generarArbol();//Este metodo genera un Arbol por defecto para iniciar el software.

};

Controladora::Controladora(void){}

Controladora::~Controladora(void){}

void Controladora::iniciar()
{
	ifstream Archivo ("Fuente del Conocimiento.txt");
	if(Archivo.is_open()){
		MundoAnimales.set_DatoRaiz(new Animal(""));
		this->cargarArbol((*this->MundoAnimales.getRaiz()),Archivo);
	}else
		this->generarArbol();	
}

void Controladora::fin()
{
	ofstream ArchivoG ("Fuente del Conocimiento.txt",ios::binary);
	this->guardarArbol((*this->MundoAnimales.getRaiz()), ArchivoG);
	ArchivoG.close();
}

void Controladora::generarArbol(){
	MundoAnimales.set_DatoRaiz(new Animal("Ave"));
	MundoAnimales.getRaiz()->setPuntero_0(new Nodo_Arbol<Animal> (new Animal("Reptil")));
	MundoAnimales.getRaiz()->setPuntero_1(new Nodo_Arbol<Animal> (new Animal("Aguila"), true));
	MundoAnimales.getRaiz()->getPuntero_0()->setPuntero_0(new Nodo_Arbol<Animal> (new Animal("Mamifero")));
	MundoAnimales.getRaiz()->getPuntero_0()->setPuntero_1(new Nodo_Arbol<Animal> (new Animal("Lagarto"),true));
	MundoAnimales.getRaiz()->getPuntero_0()->getPuntero_0()->setPuntero_0(new Nodo_Arbol<Animal> (new Animal("Pez")));
	MundoAnimales.getRaiz()->getPuntero_0()->getPuntero_0()->setPuntero_1(new Nodo_Arbol<Animal> (new Animal("Acuatico")));
	MundoAnimales.getRaiz()->getPuntero_0()->getPuntero_0()->getPuntero_0()->setPuntero_0(new Nodo_Arbol<Animal> (new Animal("Invertebrado")));
	MundoAnimales.getRaiz()->getPuntero_0()->getPuntero_0()->getPuntero_0()->setPuntero_1(new Nodo_Arbol<Animal> (new Animal("Beta"),true));
	MundoAnimales.getRaiz()->getPuntero_0()->getPuntero_0()->getPuntero_1()->setPuntero_0(new Nodo_Arbol<Animal> (new Animal("Maulla")));
	MundoAnimales.getRaiz()->getPuntero_0()->getPuntero_0()->getPuntero_1()->setPuntero_1(new Nodo_Arbol<Animal> (new Animal("Ballena"),true));
	MundoAnimales.getRaiz()->getPuntero_0()->getPuntero_0()->getPuntero_0()->getPuntero_0()->setPuntero_0(new Nodo_Arbol<Animal> (new Animal("Anfibio")));
	MundoAnimales.getRaiz()->getPuntero_0()->getPuntero_0()->getPuntero_0()->getPuntero_0()->setPuntero_1(new Nodo_Arbol<Animal> (new Animal("Araña"),true));
	MundoAnimales.getRaiz()->getPuntero_0()->getPuntero_0()->getPuntero_1()->getPuntero_0()->setPuntero_0(new Nodo_Arbol<Animal> (new Animal("Perro"),true));
	MundoAnimales.getRaiz()->getPuntero_0()->getPuntero_0()->getPuntero_1()->getPuntero_0()->setPuntero_1(new Nodo_Arbol<Animal> (new Animal("Gato"),true));
	MundoAnimales.getRaiz()->getPuntero_0()->getPuntero_0()->getPuntero_0()->getPuntero_0()->getPuntero_0()->setPuntero_0(new Nodo_Arbol<Animal> (new Animal("Culebra"),true));
	MundoAnimales.getRaiz()->getPuntero_0()->getPuntero_0()->getPuntero_0()->getPuntero_0()->getPuntero_0()->setPuntero_1(new Nodo_Arbol<Animal> (new Animal("Rana"),true));
}

void Controladora::guardarArbol(Nodo_Arbol<Animal> & raiz, ofstream &Archivo){
	if(!raiz.getHoja()){
		Archivo << raiz;
		guardarArbol((*raiz.getPuntero_0()),Archivo);
		guardarArbol((*raiz.getPuntero_1()),Archivo);
	}else{
		Archivo << raiz;
	}
}

void Controladora::cargarArbol(Nodo_Arbol<Animal> & raiz, ifstream &Archivo){
	Archivo >> raiz;
	if(!raiz.getHoja()){
		raiz.setPuntero_0(new Nodo_Arbol<Animal> (new Animal("")));
		raiz.setPuntero_1(new Nodo_Arbol<Animal> (new Animal("")));
		cargarArbol((*raiz.getPuntero_0()),Archivo);
		cargarArbol((*raiz.getPuntero_1()),Archivo);
	}
}



void MarshalString ( String ^ s, string& os ) {
   using namespace Runtime::InteropServices;
   const char* chars = 
      (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
   os = chars;
   Marshal::FreeHGlobal(IntPtr((void*)chars));
}

Nodo_Arbol<Animal>* Controladora::getRaiz()
{
	return this->MundoAnimales.getRaiz();
}

string Controladora::datos_borde()
{
	return this->MundoAnimales.datos_borde();
}

void Controladora::intercambia_niveles(int n1,int n2)
{
	this->MundoAnimales.intercambia_Nodos(n1,n2);
}

int Controladora::cantidad_niveles0()
{
	return this->MundoAnimales.cant_niveles0();
}