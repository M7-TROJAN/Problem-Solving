// Solution without strtok() Function;
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    //Write your logic to print the tokens of the sentence here.
    for (size_t i = 0; i < strlen(s); i++)
    {
        if(s[i] == ' '){
            printf("\n");
            continue;
        }
            
        printf("%c",s[i]);
    }
    return 0;
}
//......................................................................................

// Solution with strtok() Function;

/*
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    // Write your logic to print the tokens of the sentence here.
    char *token;
    token = strtok(s, " ");
    while (token)
    {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }
    return 0;
}
*/