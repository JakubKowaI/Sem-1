#include <stdio.h>
#include <string.h>
#include <math.h>
//Jakub Kowal
int main (){
    float a,b,c;
    printf("podaj a: ");
    scanf("%f",&a);
    printf("podaj b: ");
    scanf("%f",&b);
    printf("podaj c: ");
    scanf("%f",&c);
    float delta=b*b-(4*a*c);
    printf("%f\n",delta);
    if(delta<0)
    {
        printf("Brak rozwiazan");
        return 6;
    }
    float rozwiazanie,roz1,roz2;
    if(delta==0)
    {
        rozwiazanie=(-1*b)/(2*a);
        printf("Delta ma jedno rozwiazanie: %f",rozwiazanie);
    }
    if(delta>0)
    {
        roz1=((-1*b)-sqrt(delta))/(2*a);
        roz2=((-1*b)+sqrt(delta))/(2*a);
        printf("Delta ma dwa rozwiazania: %f i %f",roz1,roz2);
    }
    return 0;
}