#include <stdio.h>
//Jakub Kowal
int main()
{
    int n=0;
    scanf("%d",&n);
    for(int i =0;i<n;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            printf(" ");
        }
        for(int j=0;j<i;j++)
        {
            printf("*");
        }
        printf("*");
        for(int k=0;k<i;k++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 96;
}