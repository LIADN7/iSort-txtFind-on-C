#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcTxt.h"

#define LINE 256
#define BUFFERSIZE 100

int main()
{
    char buffer[BUFFERSIZE];
    fgets(buffer, BUFFERSIZE , stdin);
    char c = *buffer;
    char word [LINE];
    int  len=0;
    while(c != ' '){
        *(word+len)=c;
        len++;
        c = *(buffer+len);
    }
    *(word+len+1)='\0';

    char ans;
    ans= *(buffer + len +1);
    if(ans!='a' && ans!='b'){
        printf("command not find\n");
        return 1;
    }

    while(fgets(buffer, BUFFERSIZE , stdin) != NULL)
    {
        if(ans == 'a')
        {
            a(word, buffer);
        }
        else if(ans == 'b')
        {
            b(word, buffer);
        } 
    }
    return 0;
}



