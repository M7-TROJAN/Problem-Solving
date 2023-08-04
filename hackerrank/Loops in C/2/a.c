#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    char tmp;
    scanf("%d",&n);
    scanf("%c",&tmp);
    char *s[n];
    for (int i = 0; i < n; i++)
    {
        s[i] = malloc(10000);
        scanf("%s",s[i]);
    }

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < strlen(s[i]); j++)
        {
            if(j%2 == 0)
            printf("%c",s[i][j]);
        }
        printf(" ");
        for (size_t x = 0; x < strlen(s[i]); x++)
        {
            if(x%2 != 0)
            printf("%c",s[i][x]);
        }
        printf("\n");
        
        
    }


    for (int i = 0; i < n; i++)
    {
        free(s[i]);
    }   
    return 0;
}
