#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool match(char *T,char *P)
{
    if(*T=='\0' && *P=='\0')
    {
        return true;
    }
    if(*T=='*')
    {
        if(*(T+1)=='\0')
        {
            return true;
        }
        while(*P!='\0')
        {
            if(match(T+1,P)&&*(P+1)=='\0')
            {
                return true;
            }
            P++;
        }
                   
            if(*P=='\0'&&(*(T+1)!='\0'&&*(T+1)!='*'))
            {
                return false;
            }
        
    }
    if(*T=='?'&&*P!='\0')
    {
        return match(T+1,P+1);
    }
    if(*T==*P)
    {
        return match(T+1,P+1);
    }    
}

int main()
{
    printf("%d\n", match("Hello", "Hello"));
    printf("%d\n",match("a*b*a", "abababababababababababa"));// = true
    printf("%d\n",match("a*b*a", "ababababababababababab"));// = false
    printf("%d\n",match("***", "abcd"));// = true
    return 0;
}