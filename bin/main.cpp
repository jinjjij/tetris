#include "../lib/graphics.h"


int main(void){
    ConsoleGraphics cg = ConsoleGraphics();
    cg.setFps(1);
    for(int i=0;i<1000;i++){
        
        for(int i=0;i<30;i++){
            cg.setPixel(i,0,'0'+i/10);
            cg.setPixel(0,i,'0'+i/10);
        }
        
        cg.Render();
    }
    return 0;
}