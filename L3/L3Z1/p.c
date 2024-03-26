#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "funs.h"

bool p(char napis[]){
    int r=strlen(napis);
for(int i=0;i<=(r/2);i++){
    if(napis[i]!=napis[(r-i-1)])
    {
        return 0;
    }
}
    return 1;
}