#include <stdio.h>
#include <stdlib.h>

void weird(int x)
{
    if(x==10)return;
    
    printf("%d\n",x);
    if(x==5)weird(x+1);

    return weird(x+1);
    
}

int main()
{
    char T[10]="Hello";
    weird(1);
    return 0;
}