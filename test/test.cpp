#include <iostream>
#include <string>


int main(void){
    int console_x = 10;
    int console_y = 10;
    int offset_x = 2;
    int offset_y = 2;
    int buffer_x = 5;
    int buffer_y = 5;

    char** chrbuf = new char*[buffer_y];

    for (int i = 0; i < buffer_y; ++i) {
        chrbuf[i] = new char[buffer_x];   // 두 번째 차원의 메모리 할당
    }

    for(int i=0;i<buffer_y;i++){
        for(int j=0;j<buffer_x;j++){
            chrbuf[j][i] = 'a'+i+j;
        }
    }

    int right_padding = console_x - offset_x - buffer_x;
    std::string renderString = "";

    for(int y=0;y<console_y;y++){
        if(y<offset_y){
            renderString.append(console_x, ' ');            // upper padding
            renderString.append("\n");                      // new line
        }else if(y < offset_y + buffer_y){
            renderString.append(offset_x, ' ');             // left padding
           renderString.append(chrbuf[y - offset_y],0,buffer_x);      // render area
            renderString.append(right_padding, ' ');        // right padding
         renderString.append("\n");                      // new line
        }else{
            renderString.append(console_x, ' ');            // lower padding
            if(y<console_y-1)   renderString.append("\n");  // new line(not in last line)
        }
    }

    std::cout << renderString;

    return 0;
}