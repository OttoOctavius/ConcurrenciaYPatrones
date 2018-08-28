#include <iostream>

using namespace std;

enum Distracciones {telefonica,hermanos,padres};

typedef void interrupcion(Distracciones quien,string porque);

class Persona
 {
 public:
	 Persona (); // constructor
	 Persona(Persona &); // constructor de copia
	 ~Persona(); // destructor

	 void estudiar(interrupcion i);
	 void comer(){ cout << "Comiendo" << endl;}
	 void descanzar(interrupcion i);
 };
 
 Persona::Persona()
 {
	 cout << "Constructor de Persona...\n";
 }
 
 Persona::Persona(Persona &)
 {
	 cout << "Constructor de copia de Persona...\n";
 }
 
 Persona::~Persona()
 {
	 cout << "Destructor de Persona...\n";
 }

void estudiar(interrupcion i){
	//TODO:random 1-4, nada o interrupcion
	i(padres,"porque si");
}

void descanzar(interrupcion i){
	//Ignorar todo
}

void llamadaMadre(Distracciones quien,string porque){
	if(quien == padres)
		cout << "llama a tu abuela!" << endl;
}

int main(int argc, char const *argv[])
{
	Persona per;
	per.estudiar(llamadaMadre);
	return 0;
}