#include <stdio.h>
#include <math.h>
#include "funs.h"

double rozwiazanie(double a,double b,double eps){
    printf("a = %lf i b =%lf\n",a,b);
    while (fabs(a-b)>eps)
    {
        if(f(a)>0&&f((a+b)/2)>0){
            //printf("a przed %lf",a);
            a=(a+b)/2;
            //printf("a po %lf\n",a);
        }else{
            //printf("b przed %lf",b);
            b=(a+b)/2;
            //printf("b po %lf\n",b);
        }
    }
    return a;
}