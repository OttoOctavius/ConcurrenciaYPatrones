#include<mutex>
#include<thread>
#include<iostream>

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

int main(){
    std::cout << "Numero de threas" << std::thread::hardware_concurrency() << std::endl;
    std::cout << "Mostrar ACERO o ACREO"<< std::endl;
        std::thread t1(CE), t2(ARO);   // run both functions at once
        letrac.lock();
        esperarc.lock();
        t1.join();
        t2.join();
    return 0;
}
