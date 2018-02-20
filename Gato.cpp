#include<iostream>

using namespace std;

class Gato{
public:
	Gato();
	Gato(int edadInicial);
	~Gato();
	void AsignarEdad(int edad);
	int ObtenerEdad() const { return suEdad; }
	void Incremento() { ++suEdad; }
	const Gato & operator++ ();
private:
	int suEdad;
};


Gato::Gato(): suEdad(0){
};

const Gato & Gato::operator++()
{
++suEdad;
return *this;
}

/* Cuando aparece Objeto::metodo, el Objeto importa los atributos
no hay que usar this o alguna referencia
*/
Gato::Gato(int edadInicial){
	suEdad = edadInicial;
	cout <<"Creado gato" << endl;
}

Gato::~Gato(){
	cout << "Destruiste gato ;( " << endl;
}

void Gato::AsignarEdad(int edad){
	suEdad = edad;
} 

void compararfuncionalidadEdades(){
	Gato g;
	cout << "El valor de g es ";
	cout << g.ObtenerEdad() << endl;
	g.Incremento();
	cout << "El valor de g es ";
	cout << g.ObtenerEdad() << endl;
	++g;
	cout << "El valor de g es ";
	cout << g.ObtenerEdad() << endl;
	Gato otro = ++g;
	cout << "El valor de otro: " << otro.ObtenerEdad();
	cout << " y de g: " << g.ObtenerEdad() << endl;
}

Gato copia(){
	Gato Pelusa = Gato(3);
	Pelusa.AsignarEdad(7);
	return Pelusa;
}

int main(){
	Gato gato = copia();
	gato.AsignarEdad(8);
	gato.AsignarEdad(14);
    compararfuncionalidadEdades();
	return 0;
}
