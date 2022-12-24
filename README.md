# class_name

Get class or struct name as `std::string_view`.

```c++
#include "class_name.hpp"
#include <iostream>

struct S1 {
    int a,b,c;
};

namespace some_namespace{
    template<typename T>
    class TemplatedClass{
        int a,b,c;
    };
}

int main(){
    std::cout << class_name<S1>::value << std::endl; // S1
    std::cout << class_name<some_namespace::TemplatedClass<int>>::value << std::endl; // some_namespace::TemplatedClass<int>
}
```


## Supporing compilers

* gcc (>=7.4)
* clang (>=9.0)
* MSVC (>=19.14)

# License
This software is released under the MIT License, see [LICENSE](LICENSE).