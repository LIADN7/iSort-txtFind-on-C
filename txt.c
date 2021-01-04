#include <stdio.h>
#include <stdlib.h>
#include "funcTxt.h"

#define LINE 256

int main(int argc, char *argv[]){
    char* arg;
    
    if (argc !=2)
        arg = "input.txt";
    else
        arg = argv[1];
    

    FILE *f;
    f = fopen(arg, "rt");
    char c;
    char s [LINE];
    int  len=0;
    char cat [LINE];
    char ans;

    if(f== NULL){
        printf("error: not succes reading from txt\n");
        return 1;
    }

    c = fgetc(f); //"cat"
    while(c != ' '){
        *(cat+len)=c;
        len++;
        c = fgetc(f);
    }
    *(cat+len+1)='\0';
    
    c = fgetc(f);
    ans=c;

    if(ans!='a' && ans!='b'){
        printf("command not find\n");
        return 1;
    }

    c = fgetc(f);// -> \n
    c = fgetc(f); 
    c = fgetc(f);
    c = fgetc(f);

    len =0;
        while(c != EOF){
            c = fgetc(f);
            s[len] = c;
            len++;
            if(c == '\n'){
                s[len]='\0';             
                len=0;
                if(ans=='a')
                    a(cat, s);
                else if(ans=='b')
                    b(cat, s);
            }
            else if(c == EOF){
                s[len-1]='\n';
                s[len]='\0';               
                len=0;
                if(ans=='a')
                    a(cat, s);
                else if(ans=='b')
                    b(cat, s);

            }

        }
        fclose(f);
    
      


    return 0;
}



