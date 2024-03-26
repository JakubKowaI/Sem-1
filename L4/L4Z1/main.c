#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool match(char *str1, char *str2) {
    int dlg,l1,l2;
    
    for(int i = strlen(str1)-1, j=strlen(str2)-1; i >=0; i--,j--) {
        if(str1[i] == '*'){ 
            break;
        }else
        {
            if(str1[i]==str2[j]||str1[i]=='?')
            {                
            l1=i;
            l2=j;
            }else{
                return false;
            }
        }        
    }
    l1--;l2--;
    
    if(l1 > l2) {
        dlg = l1;
        }else {dlg=l2;} 

    for(int i = 0, j=0; i < dlg; i++,j++) 
    {
        if(str1[i] == '*'&&i!=l1) 
        {
           
            if(str1[i+1] == '*')continue;            
                int g = i+1;
                for(int k = i+1; k < l1; k++)
                {
                    if(j==l2&&str1[k+1]!='*') return false;
                    if(str1[k] == '*')
                    {
                        i=k;
                        break;
                    }                    
                    if(str1[k] == '?') continue;
                    if(str1[k] == str2[j]) 
                    {                        
                        j++;
                        continue;                        
                    }else
                    {
                        if(j<l2) 
                        {
                            j++;
                            k=g;
                        }
                        else return false;
                    }
                }

            

        }else if(str1[i]=='*'&&i==l1) 
        {
            return true;
        }else if(str1[i]=='?') 
        {
            continue;
        }else
        {
            if(str1[i] != str2[j]) 
            {
                return false;
            }
        }
    }
    return true;
}

int main() {    
    printf("%d\n", match("a*b*a", &"abababababababababababa"));
    printf("%d\n", match("a*b*a", &"ababababababababababab"));
    //printf("%d\n", match("ab*?a", "abba"));
    //printf("%d\n", match("abb*a", "abbba"));
    //printf("%d\n", match("abb?a", "abbba"));
    
    return 0;
}
