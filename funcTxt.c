#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "funcTxt.h"

#define LINE 256

bool findSimi(char* s1, char* s2)
{
    int lens1,lens2, cont=0;
    lens1=strlen(s1);
    lens2=strlen(s2);
    if(lens1>lens2)
        return false;
    
    for(int i=0;i<lens2;i++)
    {
        if(*(s1+cont)==*(s2+i))
            cont++;
    }
    bool flag = (cont==lens1 && (cont == lens2-1 || cont == lens2));
    return flag;
}

bool findSame(char* s1, char* s2)
{
    int lens1,lens2, cont = 0;
    lens1=strlen(s1);
    lens2=strlen(s2);

    for(int i=0;i<lens2&&lens1<=lens2-i;i++)
    { 
        if(*s1==*(s2+i))
        {
            cont=1;
            for(int j=1;j<lens1;j++){    
                if(*(s1+j)==*(s2+i+j))
                    cont++;
            }
        }
        if(cont==lens1)
            return true;
    }
    return false;
}

void b(char* s, char* fil)
{
    int fillen = strlen(fil);
    fil[fillen-2] = '\n';
    for(int j=0; j<fillen;j++)
    {
        char c [LINE];
        int i=0;

        while(*(fil + j) != ' ' && *(fil + j) !='\n')
        {
            c[i]=*(fil+j);
            j++;
            i++;
        }
        *(c+i)='\0';
        if(findSimi(s, c)){
            printf("%s\n", c);   
        }
    }
}

void a(char* user, char *line)
{
    int lentxt = strlen(line);
    char s[LINE];
    char c;
    int len = 0;
    bool flag = false;
    int i;
    line[lentxt-2] = ' ';
    for(i = 0 ; i < lentxt-1 && !flag ; i++)
    {   
        c = line[i];
        s[len] = c;
        len++;
        if(c == ' ')
        {
            s[len]='\0';               
            len=0;
            if(findSame(user, s))
            {
                printf("%s", line);
                flag = true;
            }       
        }
    }
}
