#include <queue>
#include <mutex>
#include <thread>
#include <condition_variable>
#include<iostream>

std::queue<int32_t> the_queue;
std::mutex the_mutex;
std::condition_variable the_cv;

class Threadsito;

void wait_and_pop(int32_t& data){
    std::unique_lock<std::mutex> lk(the_mutex);
    the_cv.wait(lk, []() {return !the_queue.empty();});
    data=the_queue.front();
    the_queue.pop();
}

void push(int32_t const& data){
    std::lock_guard<std::mutex> lk(the_mutex);
    the_queue.push(data);
    the_cv.notify_one();
}

int main(){
    std::cout << "Numero de threas" << std::thread::hardware_concurrency() << std::endl;
    std::vector<int32_t> vec{1,2,3,4};
    Threadsito th( 4);//(int32_t) vec.capacity());

	std::thread t(th);
    
    std::cout << "::Dentro del main::" << std::endl;
    for(auto ite:vec){
        push(ite);
    }



    return 0;
}

class Threadsito{
    int32_t entero;
 public:
	 Threadsito (int32_t _entero){
         this->entero = _entero;
         std::cout << "Constructor de Threadsito...\n";
    };
	 void operator()(); // sobrecarga operador ()
	 ~Threadsito() { std::cout << "Destructor de Threadsito...\n"; }; // destructor
 };
 
 void Threadsito::operator()()
 {
     int32_t num;
	std::cout << "::Dentro del thread::" << std::endl;
    for(int x=0;x< this->entero;x++){
        wait_and_pop(num);
        std::cout << "Cargando numero" << num << std::endl;
    }
 }
 
