#include <stdio.h>
#include <stdlib.h>
int main(){

    int *x = malloc(100*sizeof(int));
    int *y = malloc(200*sizeof(int));
    for(int i = 0 ; i < 100 ; i ++){
        x[i] = 100 - i ;
        y[i] = x[i];



    }
    for(int i = 100 ; i < 200 ; i ++ ){
        y[i] = 200 -( i-100);


    }
    int tmp;
    for(int i = 0 , n = 200 ; i < 200 ; i ++){
        for(int j = 0 ; j < n - 1 ; j++){
            if(y[j] > y[j+1]){
               tmp = y[j];
               y[j] = y[j+1];
               y[j+1] = tmp;
            }
        }
        n--;
    }
    free(x);
    x = y ;

    FILE* file = fopen("fil.txt","w");
    for(int i = 0 ; i < 200 ; i++){
        printf("%d\n",x[i]);
        fprintf(file,"%d\n",x[i]);
    }
    fclose(file);
    free(x);



}