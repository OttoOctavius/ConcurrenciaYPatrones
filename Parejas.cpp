#include<mutex>
#include<thread>
#include<iostream>

std::mutex m;

void f(){ 
    m.lock();
    std::cout<<"In f()"<<std::endl;
    m.unlock();
}

void g(){
    std::lock_guard<std::mutex> guard(m); //Suficiente con uno
    std::cout<<"In g()"<<std::endl;
    //Creo que al terminar y hacer destroy se termina
}

/*
 Implementar puntajes para tener un senso de los emparejamientos. El problema es de maximizar o minimizar
 este. Debe haber una importancia en lo cuantitativo, una gran diferencia dara resultados distintos.
 Analizar propiedades y explotarlas.
*/
const int puntoA = 3, puntoB = 5,puntonulo = 0;
/* Mejor puntaje: Solo primer columna se satisface
 Peor puntaje: Desde puntaje nulo, a elegir solo la segunda.*/

int puntos(int persona,int cual,int pareja){
    //Si persona fuera diccionario, comprobar si coincide la dic[clave] con "pareja"
    if( persona[cual][0] == pareja)
        return puntoA;
    if( persona[cual][1] == pareja)
        return puntoB;
    //Etc si se formalizara
    return puntonulo; //El caso que no se cumple. Tiene que existir
}

int buscarparejas_con_un_thread(int** hombres,int** mujeres,int* parejas, int maximo);

int main(int argc, char const *argv[]){
    int total = 0;

    int mujeres[4][2] = {
        {0,1},
        {2,3},
        {0,2},
        {1,3}
    };
    int hombres[4][2] = {
        {0,3},
        {1,2},
        {3,2},
        {1,0}
    };
    int parejas[4]; //hombre 0,1,2,i con mujer parejas[i]
    //std::cout << puntos(hombres,0,0);



	return 0;
}

//Asignar el peor caso es peligroso, porque se podria escojer una solucion imposible
int buscarparejas_con_un_thread(int** hombres,int** mujeres,int* parejas, int maximo){
    int puntajes[maximo][maximo];
    for(int i=0;i<maximo;i++){
        for(int j=0;j<maximo;j++){
            puntajes[i][j] = puntos(hombres,i,j) + puntos(mujeres,j,i);
        }
    }

    for(int i=0;i<maximo;i++){
        for(int j=0;j<maximo;j++){
            puntajes[i][j] = puntos(hombres,i,j) + puntos(mujeres,j,i);
        }
    }
}
