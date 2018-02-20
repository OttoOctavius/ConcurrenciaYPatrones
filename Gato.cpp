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
	const Gato operator++(int x)
	{
		cout << "El argumento x es" << x << endl;
		Gato temp(*this);
		++suEdad;
		return temp;
	}
	Gato& operator&(){
		cout << "Entregando referencia con Edad:" << suEdad << endl;
		return *this;
	}

	Gato Sumar(const Gato & rhs)
	{
		return Gato(suEdad + rhs.ObtenerEdad());
	}

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

	cout << "Operador posterior" << endl;
	otro = g++; //Pierdo el valor anterior de otro (copia)
	cout << "El valor de otro: " << otro.ObtenerEdad();
	cout << " y de g: " << g.ObtenerEdad() << endl;	
}

int main(){
	Gato gato = Gato(3), sumaedades;
	//Gato& otro = gato&;
	sumaedades = gato.Sumar(gato);
	cout << "Su edad con operador +:" << sumaedades.ObtenerEdad() << endl;
    compararfuncionalidadEdades();
	return 0;
}
