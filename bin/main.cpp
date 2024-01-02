#include "../lib/graphics.h"


int main(void){
    ConsoleGraphics cg = ConsoleGraphics();

    for(int i=0;i<1000;i++){
        //int tpf = cg.getTimePerFrame();
        //std::string tpf_str = "tpf : ";
        //tpf_str.append(std::to_string(tpf));
        /*
        for(int i=0;i<tpf_str.length();i++){
            cg.setPixel(5+i,5,tpf_str[i]);
        }
        */
        //cg.Render();
    }
    return 0;
}