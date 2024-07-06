#include <iostream>
#include <functional>
#include "../headers/BloomFilter.hpp"


int main(int argc, char* argv[]){

    BloomFilter bf(10, 20);

    bf.insert("hello");
    bf.insert("world");

    std::cout << bf.contains("hello") << std::endl;
    std::cout << bf.contains("world") << std::endl;
    std::cout << bf.contains("chao") << std::endl;


    return 0;
}