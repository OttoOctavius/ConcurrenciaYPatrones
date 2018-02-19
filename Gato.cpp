#include<iostream>

using namespace std;

class Gato{
public:
	Gato(int edadInicial);
	~Gato();
	void AsignarEdad(int edad);
	void Maullar();
private:
	int suEdad;
};

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

void Gato::Maullar(){
	cout << "Miau " << suEdad << endl;
}

Gato* referencia(){
	Gato *Pelusa = new Gato(3);
	Pelusa->Maullar();
	Pelusa->AsignarEdad(7);
	Pelusa->Maullar();
	return Pelusa;
}

Gato copia(){
	Gato Pelusa = Gato(3);
	Pelusa.Maullar();
	Pelusa.AsignarEdad(7);
	Pelusa.Maullar();
	return Pelusa;
}

int main(){
	Gato gato = copia();
	gato.AsignarEdad(8);
	gato.Maullar();
	gato.AsignarEdad(14);
	gato.Maullar();

	//delete &gato; //Pelusa se libera por fin
	return 0;
}
