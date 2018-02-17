#include<future>
#include<iostream>

void write_msg(std::string const& msg){
    std::cout<<msg;
}

int main(){
    //Como si fuera un thread: std::launch::async
    //Bajo demanda:std::launch::deferred
    auto f=std::async(std::launch::deferred, write_msg,"hola mundo asincronico!\n");
    write_msg("mundo del main\n");
    int x;
    f.wait(); 
    std::cin >> x; 
    //Olvidar el wait no parece mostrar diferencias en este caso. Se espera que termine
    
    return 0;
}