#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define LINE 256

bool findSimi(char* s1, char* s2){
    int lens1,lens2, cont=0;
    lens1=strlen(s1);
    lens2=strlen(s2);
    if(lens1>lens2||lens1<lens2-1)
        return false;
    for(int i=0;i<lens2;i++){
        if(*(s1+cont)==*(s2+i))
            cont++;
    }
    bool flag = (cont==lens1);
    return flag;
}

bool findSame(char* s1, char* s2){
    int lens1,lens2, cont = 0;
    lens1=strlen(s1);
    lens2=strlen(s2);

    for(int i=0;i<lens2&&lens1<=lens2-i;i++){ 
        if(*s1==*(s2+i)){
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


void b(char* s, char* fil){

    int fillen = strlen(fil);
    for(int j=0; j<fillen;j++){
        
        char c [LINE];
        int i=0;
        while(*(fil + j) !=' '&&*(fil + j) !='\n'){
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

void a(char* user, char *txt)
{
    int lentxt = strlen(txt);
    for(int i = 0 ; i < lentxt ; i++)
    {
        char l [256];
        int index = 0;
        while(*(txt+i) != '\n' && i < lentxt)
        {
            *(l+index) = *(txt+i);
            i++;
            index++;
        }
        l[index]='\0';
        bool b = false;
        int lenline = strlen(l);
        for(int j = 0 ; j < lenline && !b; j++)
        {
            char word [LINE];
            int p = 0 ;
            while(*(l+j) != ' ' && j < lenline)
            {
                *(word+p) = *(l+j);
                p++;
                j++;
            }
            if(findSame(user,word))
            {
                b = true;
                printf("%s\n" , l);
            } 
            word[p]='\0';
        }
    }
}




