#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
    int n;
    scanf("%d", &n);
    //Complete the code to calculate the sum of the five digits on n.

    /*
    ! important Note:
    Suppose we have a five-digit number num. We shall have to find the sum of its digits. 
    To do this we shall take out digits from right to left. Each time divide the number by 10 and the remainder will be the last digit 
    and then update the number by its quotient (integer part only) and finally the number will be reduced to 0 at the end.
    So by summing up the digits we can get the final sum.
    So, if the input is like num = 58612, then the output will be 22 because 5 + 8 + 6 + 1 + 2 = 22.

    To solve this, we will follow these steps below:
        num := 58612
        sum := 0
        while num is not equal to 0, do:
        sum := sum + num mod 10
        num := num / 10
        return sum
    */
    int sum = 0;

    while(n != 0){
        sum += n % 10;
        n = n/10;
    }
    printf("%d", sum);
    return 0;
}
