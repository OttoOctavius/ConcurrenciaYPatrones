#include<chrono>

using namespace std;

void medirtiempo(void &func()){
    
    auto start = std::chrono::system_clock::now();
    *fun();
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
 
    std::cout << "Empezo" << std::ctime(&end_time)
              << "y termino en tiempo: " << elapsed_seconds.count() << "s\n";
}
