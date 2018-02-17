#include<mutex>
#include<thread>
#include<iostream>

#define currency_value int

class account {
    std::mutex m;
    currency_value balance;
    public:
    friend void transfer(account& from,account& to, currency_value amount){
        std::lock_guard<std::mutex> lock_from(from.m);
        std::lock_guard<std::mutex> lock_to(to.m);
        from.balance -= amount;
        to.balance += amount;
        }
};

void transfer(account& from,account& to, currency_value amount){
    std::lock(from.m,to.m);
    std::lock_guard<std::mutex> lock_from( from.m,std::adopt_lock);
    std::lock_guard<std::mutex> lock_to( to.m,std::adopt_lock);
    from.balance -= amount; 
    to.balance += amount;
    }
