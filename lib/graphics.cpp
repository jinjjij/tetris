#include "graphics.h"


// constructor
ConsoleGraphics::ConsoleGraphics(){
    // default settings
    ConsoleGraphics::consoleX = 100;
    ConsoleGraphics::consoleY = 50;
    ConsoleGraphics::offsetX = 2;
    ConsoleGraphics::offsetY = 1;
    ConsoleGraphics::bufferX = 96;
    ConsoleGraphics::bufferY = 48;
    ConsoleGraphics::fps = 60;
    
    createBuffer();
    ConsoleGraphics::last_stall_time = std::chrono::high_resolution_clock::now();
}

/*
    set windows size in charicter unit
    minimum : 14,1
    maximum : 1000, 1000
*/ 
void ConsoleGraphics::SetConsoleSize(int width, int height){
    ConsoleGraphics::consoleX = width;
    ConsoleGraphics::consoleY = height;
    std::string sysString = "mode CON: lines=" + std::to_string(consoleX) + " cols=" + std::to_string(consoleY);
    std::system(sysString.c_str()); 
}

void ConsoleGraphics::SetOffset(int offsetX, int offsetY){
    ConsoleGraphics::offsetX = offsetX;
    ConsoleGraphics::offsetY = offsetY;
}

void ConsoleGraphics::setBufferSize(int bufferX, int bufferY){
    ConsoleGraphics::bufferX = bufferX;
    ConsoleGraphics::bufferY = bufferY;
}

void ConsoleGraphics::setFps(double fps){
    ConsoleGraphics::fps = fps;
}

/*
    render framebuffer on console screen
    and stall to adjust fps
*/ 
void ConsoleGraphics::Render(){
    
    // setup variables to use inside this function
    int console_x = ConsoleGraphics::consoleX;
    int console_y = ConsoleGraphics::consoleY;
    int offset_x = ConsoleGraphics::offsetX;
    int offset_y = ConsoleGraphics::offsetY;
    int buffer_x = ConsoleGraphics::bufferX;
    int buffer_y = ConsoleGraphics::bufferY;

    int right_padding = buffer_x - offset_x - buffer_x;

    // render area buffer
    char** chrbuf = ConsoleGraphics::charBuffer;
    
    
    // make string for cout : apply padding(offset)
    std::string renderString;

    for(int y=0;y<console_y;y++){
        if(y<offset_y){
            renderString.append(console_x, ' ');            // upper padding
            renderString.append("\n");                      // new line
        }else if(y < offset_y + buffer_y){
            renderString.append(offset_x, ' ');             // left padding
            renderString.append(chrbuf[y - offset_y]);      // render area
            renderString.append(right_padding, ' ');        // right padding
            renderString.append("\n");                      // new line
        }else{
            renderString.append(console_x, ' ');            // lower padding
            if(y<console_y-1)   renderString.append("\n");  // new line(not in last line)
        }
    }


    // render using cout
    std::cout << renderString;

    // record render_end_time
    ConsoleGraphics::render_end_time = std::chrono::high_resolution_clock::now();

    // find stall time
    int time_this_frame = std::chrono::duration_cast<std::chrono::milliseconds>(ConsoleGraphics::render_end_time - ConsoleGraphics::last_stall_time).count();
    ConsoleGraphics::time_per_frame = time_this_frame;

    double frameTime = 1000000.0f / ConsoleGraphics::fps;
    int stall_time = (int)frameTime - time_this_frame;

    // stall
    if(stall_time > 0){
        Sleep(stall_time/1000);
    }
    
    // record last_stall_time
    ConsoleGraphics::last_stall_time = std::chrono::high_resolution_clock::now();
}

// set one pixel on frameBuffer
void ConsoleGraphics::setPixel(int x, int y, char value){
    ConsoleGraphics::charBuffer[y][x] = value;
}


// create buffer (2-dim array of char)
void ConsoleGraphics::createBuffer(){
    ConsoleGraphics::charBuffer = new char*[ConsoleGraphics::bufferY];

    for (int i = 0; i < ConsoleGraphics::bufferY; ++i) {
        ConsoleGraphics::charBuffer[i] = new char[ConsoleGraphics::bufferX];   // 두 번째 차원의 메모리 할당
    }
}


int ConsoleGraphics::getTimePerFrame(){
    return ConsoleGraphics::time_per_frame;
}

// 콘솔게임만들때자주쓰는함수들 : https://app-developer.tistory.com/57