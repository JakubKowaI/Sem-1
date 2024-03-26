#include <stdio.h> 
#include <math.h>

int pr(int r){    
    if(r%4==0){
        if(r%100==0){
            if(r%400==0){                
                return 1;
            }            
            return 0;
        }        
        return 1;
    }    
    return 0;
}

int licz(int d1,int m1,int r1){
    int d=1;
    int m=1;
    int r=1;
    int dni=0;
    if(r!=r1)
        {
        while(r<r1)
        {
            if(pr(r)){
                dni=dni+366;
            }
            else{
                dni=dni+365;
            }
            r++;
        }
    }
    switch (m1)
    {
    case 1:
        dni= dni + d1;        
        break;
    case 2:        
        dni= dni + d1+31;
        break;    
    case 3:
        dni= dni + d1+31;
        if(pr(r1)){
            dni=dni+29;
        }else{
            dni =dni+28;
        }
        break;
    case 4:
        dni= dni + d1+31+31;
        if(pr(r1)){
            dni=dni+29;
        }else{
            dni =dni+28;
        }
        break;
    case 5:
        dni= dni + d1+31+31+30;
        if(pr(r1)){
            dni=dni+29;
        }else{
            dni =dni+28;
        }
        break;
    case 6:
        dni= dni + d1+31+31+30+31;
        if(pr(r1)){
            dni=dni+29;
        }else{
            dni =dni+28;
        }
        break;
    case 7:
        dni= dni + d1+31+31+30+31+30;
        if(pr(r1)){
            dni=dni+29;
        }else{
            dni =dni+28;
        }
        break;
    case 8:
        dni= dni + d1+31+31+30+31+30+31;
        if(pr(r1)){
            dni=dni+29;
        }else{
            dni =dni+28;
        }
        break;
    case 9:
        dni= dni + d1+31+31+30+31+30+31+31;
        if(pr(r1)){
            dni=dni+29;
        }else{
            dni =dni+28;
        }
        break;
    case 10:
        dni= dni + d1+31+31+30+31+30+31+31+30;
        if(pr(r1)){
            dni=dni+29;
        }else{
            dni =dni+28;
        }
        break;
    case 11:
        dni= dni + d1+31+31+30+31+30+31+31+30+31;
        if(pr(r1)){
            dni=dni+29;
        }else{
            dni =dni+28;
        }
        break;
    case 12:
        dni= dni + d1+31+31+30+31+30+31+31+30+31+30;
        if(pr(r1)){
            dni=dni+29;
        }else{
            dni =dni+28;
        }
        break;
    
    default:
    printf("Zla data");
    return 0;
        break;
    }
    return dni;
}

int main(){
    int dni = abs(licz(9,12,2004)-licz(8,11,2023));
    printf("%d dni minelo do dzisiaj\n",licz(8,11,2023));
    printf("%d dni (%d sekund) minelo od dnia moich urodzin do dzisiaj\n",dni,dni*24*60*60);
    return dni;
}