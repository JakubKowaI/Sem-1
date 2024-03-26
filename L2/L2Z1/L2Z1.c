#include <stdio.h>

int main (){
    int r;
    printf("podaj rok\n");
    scanf("%d",&r);
    if(r%4==0){
        if(r%100==0){
            if(r%400==0){
                printf("Rok %d jest przestepny",r);
                return 1;
            }
            printf("Rok %d nie jest przestepny",r);
            return 2;
        }
        printf("Rok %d jest przestepny",r);
        return 3;
    }
    printf("Rok %d nie jest przestepny",r);
    return 0;
}