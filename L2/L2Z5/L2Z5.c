#include <stdio.h>

int sigma(int n){
    int suma=0;
    for(int i=1;i<n;i++){
        if(n%i==0)suma+=i;
    }
return suma;
}

int main (){    
    for(int i=1;i<1000;i++){
        for(int j=i+1;j<1000;j++){
        if(sigma(j)==sigma(i))printf("%d || %d \n",i,j);
        }    
    }
    for(int i=1;i<1000;i++){
        if(sigma(i)==i)printf("%d jest liczba doskonala\n",i);
    }
    
    return 0;
}