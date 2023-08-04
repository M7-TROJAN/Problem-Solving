#include <stdio.h>
float discount(float a , int b);
int main (){
    float reg;
    printf("enter the price: ");
    scanf("%f",&reg);
    int sale;
    printf("Enter the discount value: ");
    scanf("%i",&sale);
    float last = discount(reg,sale);
    FILE* file = fopen("average.txt","w");
    fprintf(file,"regular price %.2f , sale value %i\n\n",reg,sale);
    fprintf(file,"the price after discount is: %.2f",last);
    fclose(file);
}
float discount(float a , int b){
    return a*(100-b)/100;
}