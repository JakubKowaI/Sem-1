#include <stdio.h>
//Jakub Kowal
int main()
{
    int n = 5;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n*2;j++)printf("*");
        printf("\n");
    }
    return 69;
}