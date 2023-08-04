#include <stdio.h>
int main(){
    int length;
    printf("How many numbers do you want to calculate the average of them?: ");
    scanf("%i",&length);
    int numbers[length];
    int result = 0;
    FILE* file = fopen("average.txt","w");
    for(int i = 0 ; i < length ; i++){
        printf("number%i: ",i+1);
        scanf("%i",&numbers[i]);
        result+=numbers[i];
        fprintf(file,"%i  ",numbers[i]);
    }
    fprintf(file,"\n \n");
    printf("the average is: %.2f",result / (float) length);
    fprintf(file,"the average is: %.2f",result / (float) length);
    fclose(file);
    

}