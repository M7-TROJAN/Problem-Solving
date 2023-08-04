#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    char *s = malloc(1000);
    if(!s) return 1;
    scanf("%[^\n]",s);

    int print[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i <= strlen(s); i++)
    {
        char c = s[i];
        switch (c)
        {
        case '0':
            print[0]++;
            break;
        case '1':
            print[1]++;
            break;
        case '2':
            print[2]++;
            break;
        case '3':
            print[3]++;
            break;
        case '4':
            print[4]++;
            break;
        case '5':
            print[5]++;
            break;
        case '6':
            print[6]++;
            break;
        case '7':
            print[7]++;
            break;
        case '8':
            print[8]++;
            break;
        case '9':
            print[9]++;
            break;
        }
    }

    free(s);
    
    for(int i = 0 ; i <= 9 ; i++){
        printf("%d ",print[i]);
    }
    return 0;
}

// another solution 

/*

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    char *s = (char *)malloc(1000 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s));
    int cheek;
    int a[10] = {0,0,0,0,0,0,0,0,0,0};
    for (int i = 0; i < strlen(s); i++)
    {
        cheek = s[i] - '0';
        if (cheek >= 0 && cheek < 10)
            a[cheek]++;
    }

    free(s);

    for (size_t i = 0; i < 10; i++)
        printf("%d ", a[i]);

    return 0;
}

*/



// another solution 
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%s", s);
    s = realloc(s, strlen(s) + 1);
    int len = strlen(s), i;
    int arr[10];
    for(i = 0; i < 10; i++)
        arr[i] = 0;
    for(i = 0; i < len; i++) {
        if(s[i] >= '0' && s[i] <= '9') {
            arr[(int)(s[i] - '0')]++;
        }
    }
    for(i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    printf("\n");
    free(s);
    return 0;
}
*/
