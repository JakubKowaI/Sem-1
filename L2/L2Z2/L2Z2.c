#include <stdio.h>
#include <math.h>

int main(){
    float  n=1;
    float w=0;
    float x,z;
    float j=1;
    int g;
    while(w<=10){
        
        w=w+(1.0/n);    
        g=floor(n);    
        printf("%d || %f\n",g,w);
        n++;        
    }
    printf("Najmniejsze n = %f",g);
    return 0;
}