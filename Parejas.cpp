#include <stdio.h>


int main(int argc, char const *argv[]){
    int total = 0;
    int puntoA = 3, puntoB = 5;

    auto mujeres = {
        {0,1},
        {2,3},
        {0,2},
        {1,3}
    };
    auto hombres = {
        {0,3},
        {1,2},
        {3,2},
        {1,0}
    };
    
/*
 Implementar puntajes para tener un senso de los emparejamientos. El problema es de maximizar o minimizar
 este. Debe haber una importancia en lo cuantitativo, una gran diferencia dara resultados distintos.
 Analizar propiedades y explotarlas.
*/

	return 0;
}

int** crearMatrizGrande(int[4][2] h,int [4][2] m){
    int** result = new int[8][8];

    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            //Suponiendo que hombres-hombres no vale
            result[i][j] = 0;
        }
        for(j=0;j<4;j++){
            //hombres-mujeres
            //si primera opcion de hombre es j->dar max
            //si la segunda es j-> el min
            //sino, dar nada o default
            result[i][j+4] = 0;
        }
    }

    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            //mujeres-hombres
            //si primera opcion de mujer es j->dar max
            //si la segunda es j-> el min
            //sino, dar nada o default
            result[i+4][j] = 0;
        }
        for(j=0;j<4;j++){
            //Suponiendo que mujeres-mujeres no vale
            result[i+4][j] = 0;
        }
    }
    return res;
}