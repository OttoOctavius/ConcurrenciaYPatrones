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

void h(int i){
    std::unique_lock<std::mutex> guard(m);
    std::cout<<"In f("<<i<<")"<<std::endl;
    guard.unlock();
    std::this_thread::sleep_for( std::chrono::seconds(1));
    guard.lock();
    std::cout<<"In f("<<i<<") again"<<std::endl;
    //Termina y se libera
}

int main(){
    std::unique_lock<std::mutex> guard(m);
    std::thread t(h,1);
    std::thread t2(h,2);
    std::cout<<"In main()"<<std::endl;
    std::this_thread::sleep_for( std::chrono::seconds(1));
    guard.unlock(); t2.join(); t.join();
}

int main1(){
    m.lock();
    std::thread t(g);
    for(unsigned i=0;i<5;++i){
        std::cout<<"In main()"<<std::endl;
        std::this_thread::sleep_for( std::chrono::seconds(1));
    }
    m.unlock();
    t.join();
}