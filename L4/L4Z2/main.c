#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void wypelnij(int (*T)[4]){
int a=1,b=1,c=1,d=1;
    for(int i=0;i<1296;i++){    
        T[i][0]=a;
        T[i][1]=b;
        T[i][2]=c;
        T[i][3]=d;
        d++;
        if(d==7){d=1;c++;}
        if(c==7){c=1;b++;}
        if(b==7){b=1;a++;}        
}
}

bool por(int *t,int *pyt,int C,int B)
{
int b=0,c=0;
int temp[4]={0,0,0,0};
int tempt[4]={0,0,0,0};

temp[0]=pyt[0];
temp[1]=pyt[1];
temp[2]=pyt[2];
temp[3]=pyt[3];

tempt[0]=t[0];
tempt[1]=t[1];
tempt[2]=t[2];
tempt[3]=t[3];

for(int i=0;i<4;i++){
    if(temp[i]==tempt[i])
    {
        c++;
        temp[i]=0;
        tempt[i]=9;
    }
}

for(int i=0;i<4;i++){    
    for(int j=0;j<4;j++){
        if(temp[j]==tempt[i])
        {
            b++;
            temp[j]=0;
            tempt[i]=9;
            break;
        }
    }
}
if(b==B&&c==C)return true;
else return false;
}

int main()
{
int (*tab)[4] = malloc(sizeof(int[1296][4]));
wypelnij(tab);
int pyt[4];
int C,B;

srand(time(NULL));

pyt[0]=rand()%6+1;
pyt[1]=rand()%6+1;
pyt[2]=rand()%6+1;
pyt[3]=rand()%6+1;

tab[0][0]=3;
tab[0][0]=1;
tab[0][0]=1;
tab[0][0]=5;

int k=1;
do{    
printf("%d.pytanie: %d %d %d %d\n",k,pyt[0],pyt[1],pyt[2],pyt[3]);
//printf("kod: 3115\n");
printf("Ile liczb sie zgadza i jest na swoim miejscu?\n");
scanf("%d",&C);
if(C==4)break;
printf("Ile liczb sie zgadza, ale nie jest na swoim miejscu?\n");
scanf("%d",&B);

k++;

for(int i=0;i<1296;i++){
    if(por(tab[i],pyt,C,B)==false)
    {
        tab[i][0]=0;
        tab[i][1]=0;
        tab[i][2]=0;
        tab[i][3]=0;
    }    
}

int los=0;
while(tab[los][0]==0&&los<1296){
    los++;
}

pyt[0]=tab[los][0];
pyt[1]=tab[los][1];
pyt[2]=tab[los][2];
pyt[3]=tab[los][3];
int licz=0;

for(int m=0;m<1296;m++)
{
    if(tab[m][0]!=0)licz++;
}
printf("Pozostalo %d mozliwych odpowiedzi\n\n",licz);
}while(C!=4);
return 0;
}