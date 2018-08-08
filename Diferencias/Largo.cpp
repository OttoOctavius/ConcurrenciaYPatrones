#include <iostream>
#include <string>
#include <vector>

//El ejecutable pesa 18.4 K, lo mismo
using namespace std;

int main(int argc, char* argv[]){
    std::vector<std::string> args(argv+1,argv+argc);
    //algo
    for( string s : args)
        cout<<s<<endl;

    return 0;
}