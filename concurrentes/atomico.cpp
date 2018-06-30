#include<iostream>
#include<future>
#include<chrono>

#include <vector>
#include <thread>
#include <atomic>

using namespace std;

atomic<int> accum(0);
void squareacumulable(int x) {
    accum += x * x;
}

int square(int x){
    return x*x;
}

int sumasquare(int total){
    int acummulacion=0;
    for(int i=0;i<=total;i++){
        acummulacion += square(i);
    }
    return acummulacion;
}

int convectores() {
    vector<thread> ths;
    for (int i = 1; i <= 20; i++) {
        ths.push_back(thread(&squareacumulable, i));
    }

    for (auto& th : ths) {
        th.join();
    }
    cout << "accum = " << accum << endl;
    return 0;
}

int main(){
    auto a= async(&sumasquare,20);
    convectores();
    cout << "Diferencia entre funcion square:" << square << " y el puntero de square:" << &square << endl;
    cout << "Devolvio: " << a.get() << endl;
    return 0;
}

/*Use async to solve the sum of squares problem. Iterate up to 20 and add your future<int> objects to a vector<future<int>>. Then, finally iterate all your futures and retrieve the value and add it to your accumulator. This should be only a few modifications from the code above.*/