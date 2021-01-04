#include <stdio.h>
#include <stdbool.h>
#include "funcSort.h"

void swap(int* arr, int i, int j)
{
    int temp = *(arr+i);
    *(arr+i) = *(arr+j);
    *(arr+j) = temp;
}

void shift_element(int* arr, int i)
{
    for(int j=0; j<i; j++){
       swap(arr , j, i);
    }
}

void insertion_sort(int* arr , int len)
{
    for(int i=0;i<len;i++)
    {
        bool flag=true;
        for(int j=0; j < i && flag; j++)
        {
            if(*(arr+i)<*(arr+j))
            {
                shift_element((arr+j), (i-j));
                flag=false;
            }
        }
    }
}


