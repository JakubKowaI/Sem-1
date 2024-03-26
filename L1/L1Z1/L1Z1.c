#include <stdio.h>
//#include <string.h>
//Jakub Kowal
int main (){
    char zdanie[]="ABRAKADABRA";    
    int z =12;
    for(int i =0;i<z;i++){        
        for(int j=0;j<z-i-1;j++){
            printf("%c ",zdanie[j]);
        }        
        printf("\n");        
        for(int k=0;k<=i;k++)
        {            
            printf(" ");            
        }
    }
 return 0;
}
