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

int main(int argc, char const *argv[])
{
	int *var = (int*) malloc(8*sizeof(int));

	for(int contador=0;contador<8;contador++){
		var[contador] = contador;
		printf("%d,",var[contador]);
	}

	free(var);
	return 0;
}