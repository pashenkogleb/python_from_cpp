#include <iostream>


int add(int x, int y, int z){
    return x+y+z;
}


template <typename... Args>
int my_add(Args... args){
    return add(args..., 3);
}


int main(){

    std::cout << my_add(3,2) << std::endl;
    return 0;
}