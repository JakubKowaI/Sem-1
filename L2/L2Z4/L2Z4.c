#include <stdio.h> 

int pr(int r){

    
    if(r%4==0){
        if(r%100==0){
            if(r%400==0){
                //printf("Rok %d jest przestepny",r);
                return 1;
            }
            //printf("Rok %d nie jest przestepny",r);
            return 0;
        }
        //printf("Rok %d jest przestepny",r);
        return 1;
    }
    //printf("Rok %d nie jest przestepny",r);
    return 0;

}

int ddk(int d1,int m1,int r1){
    int dni=0;
switch (m1)
    {
    case 1:
        dni= dni + 31+30+31+30+31+31+30+31+30+31+(31-d1);
        if(pr(r1)){
            dni=dni+29;
        }else{
            dni =dni+28;
        }
        break;
    case 2:
        
        if(pr(r1)){
            dni=dni+29-d1;
        }else{
            dni =dni+28-d1;
        }
        dni= dni + 31+30+31+30+31+31+30+31+30+31;
        break;    
    case 3:
        dni= dni + 30+31+30+31+31+30+31+30+31+(31-d1);
        break;
    case 4:
        dni= dni + 31+30+31+31+30+31+30+31+(30-d1);
        break;
    case 5:
        dni= dni + 30+31+31+30+31+30+31+(31-d1);
        break;
    case 6:
        dni= dni + 31+31+30+31+30+31+(30-d1);
        break;
    case 7:
        dni= dni + 31+30+31+30+31+(31-d1);
        break;
    case 8:
        dni= dni + 30+31+30+31+(31-d1);
        break;
    case 9:
        dni= dni + 31+30+31+(30-d1);
        break;
    case 10:
        dni= dni + 30+31+(31-d1);
        break;
    case 11:
        dni= dni + 31+(30-d1);
        break;
    case 12:
        dni= dni + 31-d1;
        break;
    
    default:
    printf("Zla data");
        break;
    }
return dni;
}

int dop(int d1,int m1,int r1){
    int dni=0;
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

int main (){
    int d1,d2,m1,m2,r1,r2;
    int dni =0;
    d1=9;
    m1=12;
    r1=2004;
    d2=4;
    m2=11;
    r2=2023;
        
    printf("%d||%d\n",ddk(d1,m1,r1),dop(d2,m2,r2));
    dni=ddk(d1,m1,r1)+dop(d2,m2,r2);
    r1++;
    while(r1<r2)
    {
        if(pr(r1)){
            dni= dni+366;
        }
        else{
            dni=dni+365;
        }
        r1++;
    }
    
    printf("Minelo %d dni, czyli %d sekund\n",dni,dni*24*60*60);
    return 0;
}