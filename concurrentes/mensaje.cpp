#include <map>
#include <iostream>
#include <sstream>
#include <fstream>      // std::filebuf

template<typename C>
struct MessageExpression
{
    //
    std::map<std::string,void(C::*)(void)> functions;
    //Toma string y funcion::void->void
    void registerFunc(std::string name,void(C::*function)(void))
        { functions[name]=function; }
    void sendMesg(std::string name)
        { (static_cast<C*>(this)->*functions[name])(); }
};

struct SomeClass : public MessageExpression<SomeClass>
{
    void method1() { std::cout << "method1" << std::endl; };
    void method2() { std::cout << "method2" << std::endl; };
};

int ejemplo1(){
    SomeClass s;
    s.registerFunc("method1",&SomeClass::method1);
    s.registerFunc("method2",&SomeClass::method2);
    s.sendMesg("method1");
    s.sendMesg("method2");
    s.sendMesg("method3"); //No pasa nada
    return 0;
}


int main()
{
  std::filebuf fb;
  fb.open ("test.txt",std::ios::out);
  std::ostream os(&fb);
  os.register_callback([](std::ios::event ev, std::ios_base& stream, int index){
                            std::cout<<"Tocado";},0);
  os << "Test sentence\n";
  fb.close();
    _onexit(ejemplo1);

}

//La unica forma de tener polimorfismo es por punteros void, o usar templates.