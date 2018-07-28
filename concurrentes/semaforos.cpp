#include<mutex>
#include<thread>
#include<iostream>

//define((x) := (y)) = auto x = y;

std::mutex letrac,esperarc,ultimaO;

void CE(){
    letrac.lock();
    std::cout << 'C';
    esperarc.unlock();
    ultimaO.lock();
    std::cout << 'E';
    ultimaO.unlock();
}

void ARO(){
    std::cout << 'A';
    letrac.unlock();
    esperarc.lock();
    std::cout << 'R';
    ultimaO.lock();
    std::cout << 'O';
}

void ACEROoACREO(){
    std::cout << "Mostrar ACERO o ACREO"<< std::endl;
        std::thread t1(CE), t2(ARO);
        letrac.lock();
        esperarc.lock();
        t1.join();
        t2.join();
}

void donantes(int cantidad){
    std::thread realizarExtracciones( [cantidad](){
        int pacientes = cantidad;
        while(pacientes != 0){
            pacientes--;
            /*
            releaseCamilla()
            sleep()
            aquireCamilla()*/
        }
    });

    /*
    thread donante{
    while(!atendido)
    if(camilla)
        if turno == n releaseRevista
    if(!revista)
        cronica()
    else
        revista.acquire();
    }*/
    realizarExtracciones.join();
}

int main(){
    ACEROoACREO();
    donantes(4);
    return 0;
}
