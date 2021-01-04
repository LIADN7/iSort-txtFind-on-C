#include <stdio.h>
#include <stdlib.h>
#include "funcSort.h"

#define len 50
static int arr[len];

int main(){
    int num;
    for(int j=0; j<len;){
             
        printf("enter num \n");
        int fla = scanf("%d", &num);
        if(fla!=0){
            *(arr+j)=num;
            j++;
        }
        else
            while(getchar() != '\n');
    }

    insertion_sort(arr , len);
    for(int j=0; j<len-1; j++){
        printf("%d,", arr[j]); 
    }   
    printf("%d", arr[len-1]); 
    printf("\n");
    return 0;
}




