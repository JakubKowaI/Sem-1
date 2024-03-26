#include <stdio.h>
#include "funs.h"

int phi(long int n){
    //if(n==1)return 1;
    long int wynik=0;

    for(int i=1;i<=n;i++){
        if(NWD(i,n)==1){
            wynik++;
        }
    }
    return wynik;
}