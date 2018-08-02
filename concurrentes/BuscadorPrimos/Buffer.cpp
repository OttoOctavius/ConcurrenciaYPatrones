
#include<iostream>
#include<string>
#include <condition_variable>


class Buffer {
    int *buffer;
    std::string[] num;
    std::condition_variable cv;
    std::mutex mu;
    int leido = 1;
    int capacidad;
    int count;
    
    public:
    Buffer(int capacidad,std::string[] numerosStr, int cantidadthreads) {
        this->capacidad = capacidad;
        this->num = numerosStr;

        buffer = new int[capacidad];
        this->capacidad = capacidad;
        this->cantidadthreads = cantidadthreads;
    }

    //Se entra cuando no hay mas numeros en el buffer, capacidad ==count
    bool agregar(){
        std::cout << "Cargando datos";
        /*
        BigInteger sum = BigInteger.valueOf(0);
        for(int i = 2; i < 5000; i++) {
            if (isPrim(i)) {
                sum.add(BigInteger.valueOf(i));
            }
        */

        if( leido == this->num.length + this->cantidadthreads ) return false;

        try{
        while (count != capacidad ) {
                this->cv.wait(std::unique_lock(mu));
        }
        } catch(...){}

        count = 0;
        for(int i=0;i<capacidad;i++) {
            if( leido < this->num.length )
                this->buffer[i] = Integer.parseInt( num[leido++] );
            else{
                this->buffer[i] = -1;
            }
        }

        this->cv.notify_all();
        return leido < this->num.length + this->cantidadthreads;
    }

    //Traba cuando se saca y esta vacia

    int lectores = 0;
    int cantidadthreads;

    int sacar(){

        lectores++;
        if(lectores == 4) this->cv.notify_all();
        //Si todos los lectores se quedaron barados, despierto al escritor
        
        try{
            while (count == capacidad) {
                std::cout << "Buffer vacio, espero" << std:: endl;        
                this->cv.wait(std::unique_lock(mu));
            }
        } catch(...){}

        this->cv.notify_all();
        lectores--;
        
        return buffer[count++];
    }
}