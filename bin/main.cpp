#include "../lib/graphics.h"
#include <iostream>


int main(void){
    ConsoleGraphics cg = ConsoleGraphics();
    cg.SetSize(11, 19);
    std::cout << cg.test();
    return 0;
}