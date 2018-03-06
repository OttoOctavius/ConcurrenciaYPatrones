#include<mutex>
#include<thread>
#include<iostream>

std::mutex m;

void CE(){
    m.lock();
    std::cout << 'C';
    std::cout << 'E';
}

void ARO(){
    std::cout << 'A';
    m.unlock();
    std::cout << 'R';
    std::cout << 'O';
}

int main(){
    std::cout << "Mostrar ACERO o ACREO"<< std::endl;
    return 0;
}
