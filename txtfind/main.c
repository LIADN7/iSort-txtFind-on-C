#include <stdio.h>
#include <stdlib.h>
#include "funcTxt.c"

#define LINE 256

int main(){
    FILE *f;
    f = fopen("input.txt", "rt");
    char c;
    char s [LINE];
    int  len=0;
    if(f != NULL)
    {
        do{
            c = fgetc(f);
            s[len] = c;
            len++;
        }while(c != EOF);
        fclose(f);
    }
    s[len]='\0';
        

    len =0;
    char cat [LINE];
    char ans;

    while(s[len]!=' '){
        *(cat+len)=*(s+len);
        len++;
    }
    *(cat+len+1)='\0';
    len ++;
    ans=*(s+len);

    if(*(s+len+1)!='\n'){
        printf("you give a warong txt");
        return 1;
    }
    len++;  

    char temp [256];

    for(int i = 0;s[len]!='\0';i++){
        temp[i]=s[len];
        len++;
    }
    
    if(ans=='a')
        a(cat, temp);
    else if(ans=='b')
        b(cat, temp);
    else
        printf("command not find\n");
        


    return 0;
}



