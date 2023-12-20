#include "graphics.h"


ConsoleGraphics::ConsoleGraphics(){

}


void ConsoleGraphics::SetSize(int height, int width){
    ConsoleGraphics::width = width;
    ConsoleGraphics::height = height;
}


int ConsoleGraphics::test(){
    return width * height;
}