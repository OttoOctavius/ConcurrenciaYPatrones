// custom allocator example
#include <cstddef>
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <numeric>

#include <string>
#include <functional>
#include <utility>

template <class T>
struct custom_allocator {
  typedef T value_type;
  custom_allocator() noexcept {}
  template <class U> custom_allocator (const custom_allocator<U>&) noexcept {}
  T* allocate (std::size_t n) { return static_cast<T*>(::operator new(n*sizeof(T))); }
  void deallocate (T* p, std::size_t n) { ::delete(p); }
};

template <class T, class U>
constexpr bool operator== (const custom_allocator<T>&, const custom_allocator<U>&) noexcept
{return true;}

template <class T, class U>
constexpr bool operator!= (const custom_allocator<T>&, const custom_allocator<U>&) noexcept
{return false;}

template <class T>
struct region_allocator {
  typedef T value_type;
  region_allocator() noexcept {}
  T* allocate (std::size_t n) { 
    auto p = static_cast<T*>(::operator new(n*sizeof(T)));
    lista.push_back<std::pair>(std::pair(p,n));
    return p;
  }
  void deallocate (T* p, std::size_t n) { ::delete(p); }
  ~region_allocator(){
    
    for(auto vec in lista)
    {
      this.deallocate(vec.first(),vec.second());
    }
    
  }
  std::vector<std::pair<T*,std::size_t>> lista;
};

int main () {

  std::vector<int,custom_allocator<int>> foo = {10,20,30};
  for (auto x: foo) std::cout << x << " ";
  std::cout << '\n';

  int sum = std::accumulate(foo.begin(), foo.end(), 0);
 
  int product = std::accumulate(foo.begin(), foo.end(), 1, std::multiplies<int>());
 
  auto dash_fold = [](std::string a, int b) {
                         return std::move(a) + '-' + std::to_string(b);
                     };
 
  std::string s = std::accumulate(std::next(foo.begin()), foo.end(),
                                    std::to_string(foo[0]), // start with first element
                                    dash_fold);

  

  std::cout << "suma " << sum << " " << std::accumulate(foo.begin(),foo.end(),0,[](int a,int b)->int {return a+b;})
            << " producto " << product << " string " << s;
  //std::transform(foo.begin(),foo.end(),[](int e)-> int{return e;});
  return 0;
}