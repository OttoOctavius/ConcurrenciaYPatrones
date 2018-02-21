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

    int puntoA = 3, puntoB = 5,puntonulo = 0;

int puntos(int persona[4][2],int cual,int pareja){
    if( persona[cual][0] == pareja)
        return puntoA;
    if( persona[cual][1] == pareja)
        return puntoB;
    //Etc si se formalizara
    return puntonulo; //El caso que no se cumple. Tiene que existir
}

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
    
    std::cout << puntos(hombres,0,0);
/*
 Implementar puntajes para tener un senso de los emparejamientos. El problema es de maximizar o minimizar
 este. Debe haber una importancia en lo cuantitativo, una gran diferencia dara resultados distintos.
 Analizar propiedades y explotarlas.
 Mejor puntaje: Solo primer columna se satisface
 Peor puntaje: Solo la segunda.

*/

	return 0;
}
