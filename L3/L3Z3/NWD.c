#include <stdio.h>
#include "funs.h"   

int NWD(int a,int b){
    while(a!=b)
    {
        if(a>b){
            a-=b;
        }else{
            b-=a;
        }
    }
    return a;
}