#include <stdio.h>

// if first 3 bytes in file != ( 0xff   ,   0xd8   ,   0xff ) then  file not jpg .

int main(int argc , char* argv[]){
    if (argc != 2)
    {
        printf("ERROR File name is missed\n");
        return 1;
    }

    FILE* file = fopen(argv[1] , "r" );

    if (file == NULL)
    {
        do
        {
        printf("ERROR Incorrect File name, please try again\nENTER file name: ");
        scanf("%s",argv[1]);
        file = fopen(argv[1] , "r" );
        } while (file == NULL);
    }
    unsigned char c[3];
    fread(c,1,3,file);

    if(c[0] == 0xff && c[1] == 0xd8 && c[2] == 0xff){
        printf("Yes possibly\n");
    }

    else{
        printf("NO\n");
    }
    printf("\n\n");

    printf("%0x\n",c[0]);
    printf("%0x\n",c[1]);
    printf("%0x\n",c[2]);

    fclose(file);

    return 0;
}

