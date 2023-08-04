#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void bubble_sort(int a[], int length);

int main(void)
{
    int a[] = {1,3,7,0,2,4,9,5,8,6};

    int length = 10;

    bubble_sort(a, length);


    for (int i = 0; i < length; i++)
    printf("a[%d] = %d\n", i, a[i]);

    return 0;
}

void bubble_sort(int a[], int length)
{
    bool swapped = false;
    int i = 0;

    do
    {
    swapped = false;
    for (int j = 0; j < (length - 1 - i); j++)
    {

        if (a[j] > a[j + 1])
        {
            int temp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = temp;
            swapped = true;
        }
    }
    i++;
    }while (swapped);
}



/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void bubble_sort(int* a , int length);
int main(int argc , char* argv[]){
    int* a = malloc(10*sizeof(int));
    for(int i = 0 ; i < 10 ; i++){
        *(a+i) = 10-i;
    }
    for(int i = 0 ; i < 10 ; i++){
        printf("%d ",a[i]);
    }
    printf("\n\n");


    bubble_sort(a , 10);

    for(int i = 0 ; i < 10 ; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    free(a);


}
void bubble_sort(int* a , int length){

    bool swapped;
    do
    {
        swapped = false;
        for(int i = 0 ; i < length-1 ; i++){
            if(a[i] > a[i+1]){
                int tmp =a[i];
                a[i] = a[i+1];
                a[i+1] = tmp;
                swapped = true;
            }
        }
        length--;
    } while (swapped);


}

*/




/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
void bubble_sort(int* a , int length);
int main(int argc , char* argv[]){
    int a[] = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};

    int length = 20; // متغير يحتوي علي عدد عناصر الاراي

// طباعة الاراي قبل الترتيب
    for(int i = 0 ; i < length ; i++){
        printf("%d ",a[i]);
    }
    printf("\n\n");

// عمل فانكشن تدير عملة ترتيب الاراي باستخدام الجورزم بابل سورت
    bubble_sort(a,length);

// طباعة عناصر الاراي بعد الترتيب
        for(int i = 0 ; i < length ; i++){
        printf("%d ",a[i]);
    }

    printf("\n\n");
    return 0;

}
void bubble_sort(int* a , int length){

    bool swapped;
    do{
        swapped = false;
        for(int i = 0 ; i < length-1 ; i++){
            if(a[i] > a[i+1]){
                int tmp = a[i];
                a[i] = a[i+1];
                a[i+1] = tmp;
                swapped = true;
            }
        }
        length--;
    }while(swapped);
}

*/