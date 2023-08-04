#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    scanf("%d",&n);
    int arr[n];
    int res = 0;
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&arr[i]);
        res += arr[i]; 
    }
    printf("%d",res);
    return 0;   
    return 0;
}