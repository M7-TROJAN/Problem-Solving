#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum{ FAST = 1 , NORMAL = 2 , ADVANCED = 3}en_mood;
void welcome(void);
void fast(void);
void normal(void);
void advanced(void);
int main(int argc , char* argv[]){
    en_mood m;
    welcome();
    if(!scanf("%d",&m)){
        puts("wrong choice");
        system("PAUSE");
        return 1;
    }
    while ((m != 1) && (m != 2) && (m != 3))
    {
        printf("error wrong mode\n");
        printf("enter mode number: ");
        scanf("%d",&m);
    }
    if (m == FAST)
        fast();
    else if (m == NORMAL)
        normal();
    else if (m == ADVANCED)
        advanced();
    else
        puts("wrong choice\n");

    puts("\nDone All Folders Are Created");
    system("PAUSE");
}

void welcome(void){
    printf("\n\a"
           "\t\t**************************************\n"
           "\t\t*                                    *\n"
           "\t\t*                                    *\n"
           "\t\t*         Hello, Tro<m7>jan          *\n"
           "\t\t*                                    *\n"
           "\t\t*                                    *\n"
           "\t\t**************************************\n\n\n");
    printf("please chose the mode\n");
    printf("(1) fast mode\n"
           "(2) normal mode\n"
           "(3) advanced mode\n");
    printf("enter your chose number: ");
    return;
} 

void fast(void) {
    int count;
    printf("Enter the number of folders you want to create: ");
    scanf("%d", &count);

    for (int i = 1; i <= count; i++) {
        char command[30];
        sprintf(command, "mkdir \"%d\"", i);
        if (system(command) != 0) {
            printf("Failed to create folder: %d\n", i);
        }
        printf("%d\r", i);
    }
}

void normal(void){
    int count;
    char a[100] = "mkdir ";
    printf("How many folders do you want to creat?: ");
    scanf("%d",&count);
    system("mkdir \"new folder\"");
    count-=1;
    for (int i = 1; i <= count; i++)
    {   
        sprintf(a,"mkdir \"new folder(%d)\"", i+1);
        system(a);
        printf("%d\r",i+1);
        
        
        
    }    
}

void advanced(void){
    int count;
    char a[100] = "mkdir ";
    char b[100];
    char tmp;
    printf("How many folders do you want to creat?: ");
    scanf("%d",&count);
    for (int i = 1; i <= count; i++)
    {
        
        printf("enter folder name: ");
        scanf("%c",&tmp);
        scanf("%[^\n]",b);
        sprintf(a,"mkdir \"%s\"", b);
        system(a);
    }
}
