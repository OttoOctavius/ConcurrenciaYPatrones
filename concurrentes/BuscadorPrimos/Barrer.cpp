
#ifndef __BARRER__

#define __BARRER__
#include <condition_variable>
#include <exception>

class Barrer {
    int max,cant;
    std::condition_variable cv;
    std::mutex mu;

    public:
    Barrer(int cant) {
        this->max = cant;
        this->cant = 0;
    }
    void pasar(){
        try{
            cant ++;
            while(cant < max)
                this->cv.wait(std::unique_lock(mu));
        } catch(...){}
        
        this->cv.notify_all();
    }
};

#endif