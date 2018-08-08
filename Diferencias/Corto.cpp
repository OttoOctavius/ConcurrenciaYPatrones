#include <iostream>
#include <string>
#include <vector>

//El ejecutable pesa 18.4 K
namespace io{
    using std::cout;
    using std::cerr;
    using std::endl;
};

namespace containers{
    using std::string;
    using std::vector;
    using svec = std::vector<std::string>;
    using lvec = std::vector<long>;
};

int main(int argc, char* argv[]){
    using namespace io;
    using namespace containers;

    svec args(argv+1,argv+argc);
    //algo
    for( string s : args)
        cout<<s<<endl;

    return 0;
}