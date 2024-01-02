/*
    basic graphics functions for console games

    double-buffering
    color
    using cout as printing method

*/


#ifndef CONSOLE_GRAPHICS_H
#define CONSOLE_GRAPHICS_H

#include <cstdlib>
#include <string>
#include <iostream>
#include <Windows.h>
// time
#include <chrono>

class ConsoleGraphics {
private:
    // console screen size
    int consoleX;
    int consoleY;

    // rendering area offset
    int offsetX;
    int offsetY;

    // rendering area size (buffer size)
    int bufferX;
    int bufferY;

    // frame per second
    double fps;

    // rendering end time :: microseconds
    std::chrono::high_resolution_clock::time_point render_end_time;

    // last stall time (when this loop started) :: microseconds
    std::chrono::high_resolution_clock::time_point last_stall_time;

    // buffer pointer
    char** charBuffer;

    // time per frame : microseconds
    int time_per_frame;


public:
    // consturctor
    ConsoleGraphics();

    /*
        set windows size in charicter unit
        minimum : 14,1
        maximum : 1000, 1000
    */ 
    void SetConsoleSize(int width, int height);

    void SetOffset(int offsetX, int offsetY);

    void setBufferSize(int width, int height);

    void setFps(double fps);

    /*
        render framebuffer on console screen
        and stall to adjust fps
    */ 
    void Render();

    // set one pixel on frameBuffer
    void setPixel(int x, int y, char value);

    // create buffer (2-dim array of char)
    void createBuffer();


    // get time per frame (microseconds)
    int getTimePerFrame();


};

#endif //CONSOLE_GRAPHICS_H