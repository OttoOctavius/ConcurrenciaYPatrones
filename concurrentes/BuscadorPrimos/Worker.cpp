
#include <iostream>
#include <Barrer.cpp>
#include <Buffer.cpp>

class Worker{
    Buffer fuenteNum;
    Barrer barrera;
    int[] divisores = new int[1000];
    int ultimo_div;

    public:
    Worker(Buffer numeros,Barrer barrera) {
        fuenteNum = numeros;
        this.barrera = barrera;
    }

    void operator()(){
        int buscado,suma;
        while(true){
        buscado = fuenteNum.sacar();
        suma = 0;

        if(buscado==-1) { 
            std::cout << "OK" << std::endl;
            barrera.pasar();
            return;
        }

        divisores(buscado);
        for(int i=0; i<ultimo_div;i++)
            suma += this->divisores[i];
        
        std::cout << "suma: " << suma << "; buscado: " + buscado << std::endl;

        if( suma ==buscado ) 
            std::cout << "Encontrado:" << buscado << std::endl;
        else
            std::cout << buscado << " no es perfecto." << std::endl;
        }
        
    }

    void divisores(int );
}

Worker::divisores(int buscado) {
        this->ultimo_div = 1;
        this->divisores[0]=1; //El resto de dividir por uno no es 0..
        for (int i=2;i < buscado && i < 100;i++) {
            if(buscado%i==0) {
                this->divisores[ultimo_div]=i;
                this->ultimo_div++;
            }
        }
    }