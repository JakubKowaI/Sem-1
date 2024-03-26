#include <stdio.h>
#include <math.h>

int main (){
    double w=1;
    double n=1;
    for(double i =1;i<=1000;i++){
        w=w*pow(i,(1.0/1000.0));
    }    
    printf("Ostateczny wynik to %f\n",w);
    return 0;
}