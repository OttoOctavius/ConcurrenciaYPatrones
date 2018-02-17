#include <thread>
#include <iostream>

//using namespace std;

void do_some_work(){
    std::cout << "entro el thread, sale" << std::endl;
}

class background_task
{
public:
    void operator()() const
     {
        do_some_work();
        //do_something_else();
     }
    };
    
background_task f;
std::thread my_thread(f); //Valen threads con objetos, y tambeien globales?!?!

int main(){
    //std::thread my_thread(do_some_work);
    my_thread.join();
    //De no hacer el el join, los threds acaban con: std::terminate()
    //TODO: Que es detach? Correrlos libres, sin forma de comunicacion
    //Como los daemos process UNIX. No tienen join(), joinable = false
    return 0;
}