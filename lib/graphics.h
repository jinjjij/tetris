/*
    basic graphics functions for console games

    double-buffering
    color
    using cout as printing method

*/


#ifndef CONSOLE_GRAPHICS_H
#define CONSOLE_GRAPHICS_H

class ConsoleGraphics {
public:
    // consturctor
    ConsoleGraphics();

    // set windows size in charicter unit
    void SetSize(int width, int height);
    

    int test();

private:
    int width;
    int height;

    int testval;

};

#endif //CONSOLE_GRAPHICS_H