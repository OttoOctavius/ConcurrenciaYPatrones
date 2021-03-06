#include <memory>
#include <iostream>
#include <string>

std::weak_ptr<int> gw;
 
    void observe()
    {
        std::cout << "use_count == " << gw.use_count() << ": ";

        if (auto spt = gw.lock()) { // Has to be copied into a shared_ptr before usage
        std::cout << *spt << "\n";
        }
        else {
            std::cout << "gw is expired\n";
        }
    }
    
    void testviejo(){
        std::allocator<int> a1;
        int* p = a1.allocate(1);
        auto a = std::make_unique<int*>(p);
        a1.construct(p, 7);
        //Hacer algo
        a1.deallocate(p, 1);
        /*Dos formas de transformar el allocator a otro tipo, supuestamente
         deberia ahorrar espacio?*/
        // same, but obtained by rebinding from the type of a1
        decltype(a1)::rebind<std::string>::other a2_1;
        // same, but obtained by rebinding from the type of a1 via allocator_traits
        std::allocator_traits<decltype(a1)>::rebind_alloc<std::string> a2_2;

        std::string* s = a2_2.allocate(2); // space for 2 strings
    
        a2_2.construct(s, "foo");
        a2_2.construct(s + 1, "bar");
    
        std::cout << s[0] << ' ' << s[1] << '\n';
    
        a2_2.destroy(s);
        a2_2.destroy(s + 1);
        a2_2.deallocate(s, 2);        

    }

    void testviejo(){
        std::allocator<int> a1;
        int* p = a1.allocate(1);
        auto a = std::make_unique<int*>(p);
        //a1.construct(p, 7); deprecated 
        //a* = 7;
        //Hacer algo
        a1.deallocate(p, 1);
        //
        std::allocator<std::string> a2_2;

        std::string* s = a2_2.allocate(2); // space for 2 strings
    
        s[0] = "foo";
        s[1] = "bar";
    
        std::cout << s[0] << ' ' << s[1] << '\n';
    
        a2_2.destroy(s);
        a2_2.destroy(s + 1);
        a2_2.deallocate(s, 2);        

    }
/*
    void testpolimorfico(){
        std::pmr::polymorphic_allocator a1;
        int* a = a1.allocate(1);
        a1.construct(a, 7);
        a1.deallocate(a, 1);
    }*/

    int main(int argc, char* argv[]){
        testviejo();
        {
        auto sp = std::make_shared<int>(42);
         std::cout << sp.use_count() << '\n';
        gw = sp; // probar con std::move(), no cambia el comportamiento, weakptr no contiene nada por si mismo?
         std::cout << sp.use_count() << '\n';   //No cuenta los usos del shared
        observe();
        }
    
        observe();
    return 0;
    }